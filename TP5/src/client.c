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
#include <arpa/inet.h>
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

char * recois_message(int socketfd, char *data){
  int read_status = read(socketfd, (void * )data, sizeof(data));
  if(read_status < 0){
    perror("erreur lecture");
    return NULL;
  }
  return data;
}

void open_eleve_data(struct dirent * entry,DIR * dirp, eleve * promo, char * dir){
  //obtention de tout les eleves
  int n = 0;
  while ((entry = readdir(dirp)) != NULL){
    strcpy((promo+n)->prenom, entry->d_name);
    char dire[1024];
    printf("%s\n", dir);
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
}

int calcule_moyenne(eleve *promo, int socketfd){
  char *data;
  int data_size = 1024;
  data = malloc(data_size * sizeof(char));
  for (int i = 0;i<NBR_ELEVE;i++) {
      (promo+i)->notes.moyenne = 0;
      // printf("%i\n", (promo+i)->notes.nbr_notes);
      //si pas de notes on arrete
      if ((promo+i)->notes.nbr_notes==0) break;
      for (int j = 0;j < (promo+i)->notes.nbr_notes;j++){
        char * num1 ;
        char * num2 ;
        num1 = malloc(sizeof((promo+i)->notes.moyenne));
        num2 = malloc(sizeof((promo+i)->notes.notes[i]));
        memset(data,0, data_size);
        sprintf(num1, "%i", (promo+i)->notes.moyenne);
        sprintf(num2, "%i", (promo+i)->notes.notes[j]);
        strcpy(data,"calcule: ");
        strcat(data, strcat(strcat(num1," "),num2));
        strcat(data," +");
        envoie_message(socketfd, data);
        memset(data, 0, data_size);
        data = recois_message(socketfd, data);
        (promo+i)->notes.moyenne = atoi(data);
        memset(data, 0, data_size);
      }
      (promo+i)->notes.moyenne/=(promo+i)->notes.nbr_notes;
      // printf("Moyenne: %i\n",(promo+i)->notes.moyenne );
    }
  free(data);
  return (EXIT_SUCCESS);
};

void envoie_numeros_operateur(int socketfd, char *data, eleve * promo){
  //init data
  char dir[1024];
  char delim[] =" ";
  char *dip;
  dip = strtok(data, delim);
  dip = strtok(NULL, delim);
  printf("%s\n", dip);
  memset(dir, 0, sizeof(dir));
  strcpy(dir, dip);
  //on enleve le "\n" de fin
  if( dir[strlen(dir)-1] == '\n' )
    dir[strlen(dir)-1] = 0;
  printf("%s\n", dir);

  //ouverture du dossier de l'eleve
  DIR *dirp = opendir(dir);
  struct dirent *entry;
  if (dirp == NULL) {
      printf("error opendir");
      return;
  }
  //on met a zeros toutes les notes
  for (int i = 0; i < NBR_ELEVE;i++) {
    memset((promo+i)->notes.notes, 0, sizeof((promo+i)->notes.notes));
  }

  entry = readdir(dirp); // on enleve .
  entry = readdir(dirp); // on enleve ..
  entry = readdir(dirp); // on enleve .DS_store

  //initialisation de la data de l'eleve
  open_eleve_data(entry, dirp, promo, dir);

  //on recupere les notes et on fait la moyenne pour chaque eleve
  for (int num_eleve = 0; num_eleve < NBR_ELEVE; num_eleve++){
    printf("--------------------------------");
    printf("boucle eleve for tour : %i, dir : %s\n", num_eleve,(promo+num_eleve)->dire);
    //on ouvre le dossier de l'eleve
    DIR *dirp = opendir((promo+num_eleve)->dire);
    struct dirent *file;
    if (dirp == NULL) {
      printf("fin des eleves\n");
      return;
    }
    //on considere qu'on a mtn que des fichiers avec des notes et non des dossiers
    //on lit toutes les notes de l'eleve
    (promo+num_eleve)->notes.nbr_notes = 0;
    int j = 0;
    while ((file = readdir(dirp)) != NULL){
      // printf("boucle note for tour : %i\n", j);
      if (strcmp(file->d_name, ".")==0)file = readdir(dirp); // on enleve .
      if (strcmp(file->d_name, "..")==0)file = readdir(dirp); // on enleve ..
      if (strcmp(file->d_name, ".DS_Store")==0)file = readdir(dirp); // on enleve .DS_store
      // printf("%s\n", file->d_name);

      FILE* ptr_file;
      char note[3] = {0};
      char filename[1024];
      // printf("file: %s\n", file->d_name);
      // Opening file in reading mode
      strcpy(filename, (promo+num_eleve)->dire);
      strcat(filename, file->d_name);
      ptr_file = fopen(filename, "r");
      if (NULL == ptr_file) {
          printf("file can't be opened : %s\n", filename);
          continue;
      }
      // reading first line of file
      fgets(note, 3, ptr_file);
      // Closing the file
      fclose(ptr_file);

      //mise a jour de la data
      (promo+num_eleve)->notes.notes[j] = atoi(note);
      (promo+num_eleve)->notes.nbr_notes++;
      // printf("%i\n", (promo+num_eleve)->notes.notes[j]);
      // printf("%i\n", (promo+num_eleve)->notes.nbr_notes);
      j++;
      // printf("\n");
    }
    closedir(dirp);

    //affichage des notes des eleves
    printf("notes:");
    for (int k=0; k<((promo+num_eleve)->notes.nbr_notes); k++) {
        printf("%i, [%i] ; ", (promo+num_eleve)->notes.notes[k], k);
      }
    printf("\n");
    printf("nbr_notes : %i\n",(promo+num_eleve)->notes.nbr_notes);
  }
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
  //on recuper le debut du code recu
  char code[10];
  memset(code, 0, sizeof(code));
  sscanf(data, "%s", code);
  printf("'%s'\n", code);
  printf("%s\n", data);

  if (strcmp(code, "message:") == 0) envoie_message(socketfd, data);
  if (strcmp(code, "calcule:") == 0) envoie_message(socketfd, data);
  if (strcmp(code, "calculeM:") == 0) {
    eleve *promo;
    promo = malloc(NBR_ELEVE * sizeof(eleve));
    envoie_numeros_operateur(socketfd, data, promo);
    //mtn on calcul la moyennes des eleves
    int test = calcule_moyenne(promo, socketfd);
    if (test){printf("erreur calcul moyenne"); return(EXIT_FAILURE);}
    //fin de la transmission
    char end[4] = "fin";
    envoie_message(socketfd, end);
    printf("fin de transmission\n");
    //affichage des moyennes
    for (int i = 0; i <NBR_ELEVE; i++){
      if ((promo+i)->notes.nbr_notes != 0){
        printf("Eleve : %s -> notes : %d\n", (promo+i)->prenom, (promo+i)->notes.moyenne);
      }
    }
    return (EXIT_SUCCESS);
  } 

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));
  // lire les données de la socket
  recois_message(socketfd, data);
  printf("Message recu: %s\n", data);

  return (EXIT_SUCCESS);
};

int main(){
  int socketfd;
  struct sockaddr_in server_addr;
  //char *ip = "192.168.221.154";

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
  // server_addr.sin_addr.s_addr = inet_addr(ip);

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0){
    perror("error connection serveur");
    exit(EXIT_FAILURE);
  }

  // appeler la fonction pour envoyer un message au serveur
  int test = envoie_recois_message(socketfd);
  if (test){printf("erreur envoie_recois_message");};

  close(socketfd);
}
