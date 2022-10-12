#include <stdio.h>
#include <math.h>

int main (){
    //initialisation des variables
    int nombre;
    int bin[31];
    int k = 0;
    for ( int i = 0; i < 31; i++) {
        bin[i] = 0;
    }
    //inpur du nombre
    printf("quelle nombre a convertir en binaire ? ");
    scanf("%i",&nombre);

    //transformation en binaire
    while (nombre >= 1) {
        bin[k] = nombre % 2;
        nombre /= 2;
        k++;
    }

    //affichage du nombre en binaire
    printf("votre nombre en binaire: ");
    for (int i=k-1; i>=0; i--) printf("%i",bin[i]);
    printf("\n");
    return 0;
}
