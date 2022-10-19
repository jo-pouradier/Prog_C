#include "repertoire.h"


int main(int argc, char **argv) {

    if (argc < 2) {
    printf("Usage: readdir path\n");
    return(EXIT_FAILURE);
    }

    lire_dossier_iteratif(argv[1]);
    return 0;
}