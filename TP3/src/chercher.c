#include <stdio.h>
#include <stdlib.h>

int main(){
    //init tableau random
    const int taille_table = 300;
    const int random_max = 1000;
    int table[taille_table];
    for (int i = 0; i < taille_table; i++){
        table[i] = rand() % random_max;
    }

    //affichage du tableau
    for (int i = 0; i < taille_table; i++){
        printf("%i ,", table[i]);
    }
    printf("\n");

    int entier_chercher;
    printf("Quel entier chercher ? : ");
    scanf("%d",&entier_chercher);

    //recherche de la valeur
    for (int i = 0; i < taille_table; i++){
        if (table[i] == entier_chercher) printf("entier présent\n"); //on le print autant de fois qu'il y a l'entier
    }

    //init phrases
    char phrases[5][31] = {"je suis a la maison c'est cool", "je n'aime pas les epinards !! ", "le cafe est a meilleur boisson", "la vodka est la pire boisson !","le gin est une bonne boisson !"};
    char phrase_chercher[31];
    printf("Quel phrase a chercher ? : ");
    scanf("%31c",phrase_chercher);

    //recherche de la phrase
    for (int i = 0; i < 31; i++) printf("%c", phrase_chercher[i]);
    printf("\n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 31; j++) printf("%c", phrases[i][j]);
        printf("\n");
    }

    for (int i = 0; i < 5; i++){
        printf("test\n");
        if (phrases[i] == phrase_chercher){printf("phrase trouvé"); continue;}; //on compte le nombre de charactere correspondant
    }
}