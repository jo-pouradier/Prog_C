#ifndef __REPERTOIRE__H
#define __REPERTOIRE__H

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void lire_dossier(char*);

void lire_dossier_recursif(char*);

void lire_dossier_iteratif(char *);

#endif /* __REPERTOIRE__H */