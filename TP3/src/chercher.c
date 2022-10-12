#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //init tableau random
    const int taille_table = 300;
    const int random_max = 1000;
    int table[taille_table];
    for (int i = 0; i < taille_table; i++){
        table[i] = rand() % random_max;
    }

    //affichage du tableau
    // for (int i = 0; i < taille_table; i++){
    //     printf("%i ,", table[i]);
    // }
    // printf("\n");

    //on demande les inputs
    int entier_chercher;
    printf("Quel entier et votre phrase a chercher ? : \n");
    scanf("%d\n",&entier_chercher);
    char phrase_chercher[31];
    fgets(phrase_chercher, sizeof phrase_chercher, stdin);

    //recherche de la valeur
    for (int i = 0; i < taille_table; i++){
        if (table[i] == entier_chercher) printf("entier présent\n"); //on le print autant de fois qu'il y a l'entier
    }
    printf("\n");

    //init phrases
    char phrases[5][31] = {"je suis a la maison c'est cool", "je n'aime pas les epinards !! ", "le cafe est a meilleur boisson", "la vodka est la pire boisson !","le gin est une bonne boisson !"};
    //on affiche les phrases
    // for (int i = 0; i < 5; i++){
    //     printf("%s", phrases[i]);
    //     printf("\n");
    // }

    
    //fgets(phrase_chercher, sizeof(phrase_chercher), stdin );
    //on affiche la phrase a chercher
    printf("votre phrase : %s \n", phrase_chercher);

    //recherche de la phrase
    for (int i = 0; i < 5; i++){
        int count = 0;
        if (strlen(phrases[i]) != strlen(phrase_chercher)){
            printf ("taille differente\n");
            continue;
            }
        for (int j = 0; j < 31; j++){
            if (phrases[i][j] == phrase_chercher[j]) {
                count ++;
            }
        }
        if (count == 31) printf("phrase trouvée");
    }
    return 0;
}