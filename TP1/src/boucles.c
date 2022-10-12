/*
    AUTEUR : Joseph Pouradier Duteil
*/
#include <stdio.h>

int main()
{
    //init variables
    unsigned int bcl;
    char star = '*';
    char cross = '#';

    //input taille du tableau
    do{
        printf("Entrer la taille de la pyramide superieur a 4 : \n");
        scanf("%d", &bcl);
        printf("\n");
    } while (bcl < 4);

    //boucle d'affichage
    for (int i = 0; i < bcl + 1; i++){
        printf("%c ", star);
        if (i == bcl){
            for (int j = 0; j < bcl; j++) printf("%c ", star);
        }
        if (i > 0 && (i < bcl)){
            for (int j = 0; j < i - 1; j++) printf("%c ", cross);
            printf("%c ", star);
        }
        printf("\n");
    }

    return 0;
}