/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef __CLIENT_H__
#define __CLIENT_H__

/*
 * port d'ordinateur pour envoyer et recevoir des messages
 */
#define PORT 8089
//ip 192.168.221.244

typedef struct{
    char dire[1024];
    char prenom[30]; //nom de son repertoire
    struct notes{int nbr_notes, notes[50], moyenne;} notes;// pour faire sa moyenne, 50 notes max
}eleve;

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */
void open_eleve_data(struct dirent * entry,DIR * dirp, eleve * promo, char * dir);
int envoie_message(int socketfd, char *data);
char * recois_message(int socketfd, char *data);
int calcule_moyenne(eleve *promo, int socketfd);
void envoie_numeros_operateur(int socketfd, char *data, eleve * promo);
int envoie_recois_message(int socketfd);

// on cree un struct eleve pour stocké les données
const int NBR_ELEVE = 248;
int calcul_moyenne(eleve *, int socketfd);

#endif
