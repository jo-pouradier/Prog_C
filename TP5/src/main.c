#include "repertoire.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Usage: readdir path\n");
        return(EXIT_FAILURE);
    }

    lire_dossier(argv[1]);
    return 0;
}