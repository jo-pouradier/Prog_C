/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <sys/types.h>
#include <sys/socket.h>
//#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "operator.h"
#include "serveur.h"

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data)
{
  int data_size = write(client_socket_fd, (void *)data, strlen(data));

  if (data_size < 0){
    perror("erreur ecriture");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

int recois_numeros_calcul(int client_socket_fd, char *data){
  char delim[] =" ";
  char *ptr;
  ptr = strtok(data, delim);
  ptr = strtok(NULL, delim);
  int num1 = atoi(ptr);
  ptr = strtok(NULL, delim);
  int num2 = atoi(ptr);
  char *op = strtok(NULL, delim);

  switch (*op){
        case '+':
            somme(&num1,&num2);
            break;
        case '-':
            difference(&num1,&num2);
            break;
        case '*':
            produit(&num1,&num2);
            break;
        case '/':
            quotient(&num1,&num2);
            break;
        case '%':
            modulo(&num1,&num2);
            break;
        case '&':
            et(&num1,&num2);
            break;
        case '|':
            ou(&num1,&num2);
            break; 

        default:
            break;
    }
    sprintf(data,"%d", num1);
    renvoie_message(client_socket_fd,data);
    return (EXIT_SUCCESS);
};

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd){
  struct sockaddr_in client_addr;
  char data[1024];
  unsigned int client_addr_len = sizeof(client_addr);

  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_socket_fd < 0){
    perror("not accepted");
    return (EXIT_FAILURE);
  }
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));
  int transmission = 1;

  while(transmission) {
    // lecture de données envoyées par un client
    int data_size = read(client_socket_fd, (void *)data, sizeof(data));
    if (data_size < 0){
      perror("erreur lecture");
      return (EXIT_FAILURE);
    }

    /*
     * extraire le code des données envoyées par le client.
     * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
     */
    printf("Message recu: %s \n", data);
    char code[10];
    sscanf(data, "%s", code);
    //Si on a un message, on en renvoie un
    if (strcmp(code, "message:") == 0){
      // Demandez à l'utilisateur d'entrer un message
      char message2[1024];
      printf("Votre message (max 1023 caracteres): ");
      fgets(message2, sizeof(message2), stdin);
      strcat(data, message2);
      renvoie_message(client_socket_fd, message2);
    }

    //Si on a in caclule il faut renvoyer le resultat
    else if (strcmp(code, "calcule:") == 0){
      recois_numeros_calcul(client_socket_fd,data);
    }

    else{
      char fin[4];
      sscanf(code, "%s", fin);
      printf("%s\n" , fin);
      if (strcmp(fin, "fin") == 0) {printf("fin\n");transmission = 0;}
      else{
        strcpy(data, "Vous n'aves pas envoyer un message ou un calcule\n");
        renvoie_message(client_socket_fd, data);
      }
    }
  }

  // fermer le socket
  close(socketfd);
  return (EXIT_SUCCESS);
}

int main()
{
  int socketfd;
  int bind_status;
  struct sockaddr_in server_addr;

  //Creation d'une socket
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0){
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (bind_status < 0){
    perror("bind");
    return (EXIT_FAILURE);
  }

  // Écouter les messages envoyés par le client
  listen(socketfd, 10);

  // Lire et répondre au client
  recois_envoie_message(socketfd);

  return 0;
}
