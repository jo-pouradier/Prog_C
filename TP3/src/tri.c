#include <stdio.h>
#include <stdlib.h>

int main(){
    const int taille_table = 100;
    const int random_max = 1000;

    int table[taille_table];
    int table_tries[taille_table];

    for (int i = 0; i < taille_table; i++){
        *(table+i) = rand() % random_max;
    }
    printf("Tableaux non trier : \n");
    for (int i = 0; i < taille_table; i++){
        printf("%i ,", table[i]);
    }
    printf("\n");

    int min = 0;
    for (int i = 0; i < taille_table; i++) {
        if ( *(table + i) < min){
            min = *(table + i); //init min
        }
    }
    
    int count = taille_table - 1;

    while (count >= 0){
        int max = 0;
        int count_max = 0;
        for (int i = 0; i < taille_table; i++){
            if (*(table + i) > max) {
                max = *(table + i); //init max
                count_max = i; //indice du max
            }
        }
        *(table + count_max) = 0; //on retire le max du premier tableau
        *(table_tries + count) = max; //on ajoute le max dans le deuxieme tableau
        count--; //on prepare le prochain max
    }

    // for (int i = 0; i < taille_table; i++){ //ca n'affiche que des zeros
    //     printf("%i ,", table[i]);
    // }
    printf("\n");
    printf("Tableau trier : \n");
    for (int i = 0; i < taille_table; i++){
        printf("%i ,", table_tries[i]);
    }
    printf("\n");

}