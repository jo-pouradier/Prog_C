#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "fichier.h"

void lire_fichier(char *nom_de_fichier){
    char content[1000]; //c'est le nombre de char par ligne possible, on espere que ca va pas depasser
    int fd, count, size;
    fd = open(nom_de_fichier, O_RDONLY);
    
    size = read(fd, content, 1000);
    for (count = 0; count < size; count ++) {
    printf("%c", content[count]); 
    }
    close(fd);
};

void ecrire_dans_fichier(char *nom_de_fichier, char *message){
    int fd, count, size;
    fd = open(nom_de_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR); 
    size = write(fd, message, strlen(message));
    close(fd);
};
