#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>



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

