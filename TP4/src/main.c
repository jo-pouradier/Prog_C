#include <stdio.h>
#include "fichier.h"

int main() { 
    char *nom_de_fichier = "text.txt";
    lire_fichier(nom_de_fichier);
    printf("\n");

    char message[] = "Hello World \n";

    ecrire_dans_fichier(nom_de_fichier, message);

    lire_fichier(nom_de_fichier);
    return 0; 
}