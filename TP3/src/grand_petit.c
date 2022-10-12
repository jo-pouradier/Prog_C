#include <stdio.h>
#include <stdlib.h>

int main (){
    const int taille_table = 300;
    const int random_max = 1000;

    int table[taille_table];

    for (int i = 0; i < taille_table; i++){
        table[i] = rand() % random_max;
    }
    int min  = table[0]; //il faut pas mettre 0 sinon on reste a 0
    int max = 0;

    for (int i = 0; i < taille_table; i++){
        if (table[i] < min) min = table[i];
        if (table[i] > max) max = table[i];
    }

    // for (int i = 0; i < taille_table; i++){
    //     printf("%i ,", table[i]);
    // }
    printf("\nMin : %i\n", min);
    printf("Max: %i\n", max);

}