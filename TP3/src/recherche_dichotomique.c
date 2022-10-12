#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    //init table random_maxndom
    const int taille_table = 100;
    const int random_max = 1000;
    int table[taille_table];
    int table_tries[taille_table];
    for (int i = 0; i < taille_table; i++){
        *(table+i) = rand() % random_max;
    }
    
    int count = taille_table - 1;

    //tri de table
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

    //print du tableau trier
    printf("Tableau trier : \n");
    for (int i = 0; i < taille_table; i++){
        printf("%i ,", table_tries[i]);
    }
    printf("\n");

    //dichotomie
    int end = taille_table;
    int start = 0;
    int middle = 0;
    bool found = false;
    int entier_chercher;
    printf("Quel entier chercher ? : ");
    scanf("%d",&entier_chercher);

    while (!found && start <= end){
        middle = (start + end) / 2;
        if (*(table_tries + middle)==entier_chercher) found = true;
        else {
            if (entier_chercher > *(table_tries + middle)) start = middle + 1; 
            if (entier_chercher < *(table_tries + middle)) end = middle - 1;
        }
    }

    //affichage de fin
    if (found) printf("la valeur a été trouvé au rang %i /n", middle);
    else printf("la valeur n'a pas été trouvé/n");
}

