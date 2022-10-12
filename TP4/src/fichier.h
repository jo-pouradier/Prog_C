#ifndef __FICHIER__H
#define __FICHIER__H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void lire_fichier(char *);

void ecrire_dans_fichier(char *, char *);


#endif /* __FICHIER__H */