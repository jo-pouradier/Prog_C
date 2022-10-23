/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>

#include "client.h"
#include "repertoire.h"


/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_message(int socketfd, char *data){
  int write_status = write(socketfd, data, strlen(data));
    if (write_status < 0){
      perror("erreur ecriture");
      exit(EXIT_FAILURE);
    }
  return(EXIT_SUCCESS);
}

int envoie_numeros_operateur(int socketfd, char *data){
  //printf("in fct\n");
  char dir[1024];
  char delim[] =" ";
  char *dip;
  dip = strtok(data, delim);
  dip = strtok(NULL, delim);
  memset(dir, 0, sizeof(dir));
  strcpy(dir, dip);
  //on enleve le "\n" de fin
  if( dir[strlen(dir)-1] == '\n' )
    dir[strlen(dir)-1] = 0;
  //printf("%s\n", dir);

  //on va ouvrir le dossier
  DIR *dirp = opendir(dir);
  //printf("opening folder\n");
  struct dirent *entry;
  if (dirp == NULL) {
      printf("error opendir");
      return(EXIT_FAILURE);
  }
  printf("ouverture dossier ok\n");

  // on cree un struct eleve pour stocké les données
  typedef struct{
    char dire[1024];
    char prenom[30]; //nom de son repertoire
    struct notes{int nbr_notes, notes[50];} notes;// pour faire sa moyenne, 50 notes max
  }eleve;
  const int NBR_ELEVE = 248;
  eleve promo[NBR_ELEVE];

  //initialisation du prenom et du dossier eleve
  int n = 0; //compte le nombre d'eleve
  entry = readdir(dirp); // on enleve .
  entry = readdir(dirp); // on enleve ..
  entry = readdir(dirp); // on enleve .DS_store
  while ((entry = readdir(dirp)) != NULL){
    strcpy((promo+n)->prenom, entry->d_name);
    char dire[1024];
    strcpy((promo+n)->dire, dir);
    strcat((promo+n)->dire, entry->d_name);
    strcat((promo+n)->dire, "/");
    printf("prenom : %s\n", (promo+n)->prenom);
    printf("direction : %s\n", (promo+n)->dire);
    n++;
  }
  closedir(dirp);
  //on a mtn tout les eleves
  printf("\n");
  //on recupere les notes et on fait la moyenne pour chaque eleve
  for (int i = 0; i < NBR_ELEVE; i++){
    printf("boucle eleve for tour : %i\n", i);
    //on ouvre le dossier de l'eleve
    DIR *dirp = opendir((promo+i)->dire);
    struct dirent *file;
    if (dirp == NULL) {
        printf("error opendir eleve");
    }
    printf("eleve directory opened\n");

    //on considere qu'on a mtn que des fichiers avec des notes et non des dossiers
    //on lit toutes les notes de l'eleve
    (promo+i)->notes.nbr_notes = 0;
    for (int j=0; j<n; j++){
      printf("boucle note for tour : %i\n", j);
      file = readdir(dirp);
      
      if (file == NULL){
        printf("error readdir eleve : %s", (promo+j)->dire);
        continue;
      };
      printf("fichier note readdir");
      file = readdir(dirp); // on enleve .
      file = readdir(dirp); // on enleve ..
      file = readdir(dirp); // on enleve .DS_store
      printf("%s\n", file->d_name);

      FILE* ptr_file;
      char note[3];
      char filename[1024];
      // Opening file in reading mode
      strcpy(filename, (promo+i)->dire);
      strcat(filename, file->d_name);
      printf("%s\n", filename);
      ptr_file = fopen(filename, "r");
      if (NULL == ptr_file) {
          printf("file can't be opened \n");
      }
      printf("file opened \n");
      // reading first line of file
      fgets(note, 3, ptr_file);
      // Closing the file
      fclose(ptr_file);

      //mise a jour de la data
      (promo+i)->notes.notes[j] = atoi(note);
      (promo+i)->notes.nbr_notes++;
      printf("%i\n", (promo+i)->notes.notes[j]);
      printf("%i\n", (promo+i)->notes.nbr_notes);
    }
    closedir(dirp);
  }
  
  return(EXIT_SUCCESS);
};

int envoie_recois_message(int socketfd){
  char data[1024];
  // la réinitialisation de l'ensemble de la donnée
  memset(data, 0, sizeof(data));

  // Demandez à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1023 caracteres): \nCommencez par 'message:' ou 'calcule:' (ex : 'caclule: 2 3 +') ==> ");
  fgets(message, sizeof(message), stdin);
  strcat(data, message);

  char code[10];
  memset(code, 0, sizeof(code));
  sscanf(data, "%s", code);
  printf("'%s'\n", code);
  printf("%s\n", data);

  if (strcmp(code, "message:") == 0) envoie_message(socketfd, data);
  if (strcmp(code, "calcule:") == 0) envoie_message(socketfd, data);
  if (strcmp(code, "calculeM:") == 0) envoie_numeros_operateur(socketfd, data); 

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if(read_status < 0){
    perror("erreur lecture");
    return -1;
  }
  printf("Message recu: %s\n", data);

  return 0;
};

int main(){
  int socketfd;
  struct sockaddr_in server_addr;

  //Creation d'une socket
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0){
    perror("error socket");
    exit(EXIT_FAILURE);
  }

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0){
    perror("error connection serveur");
    exit(EXIT_FAILURE);
  }

  // appeler la fonction pour envoyer un message au serveur
  envoie_recois_message(socketfd);

  close(socketfd);
}
