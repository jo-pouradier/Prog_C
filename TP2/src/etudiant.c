#include <stdio.h>

int main(){
    //init des tableaux
    char prenom[5][30] = {"Adrein", "Pierre", "Louis", "Martin", "Hugues"};
    char nom[5][30] = {"Dalb", "Tlp", "Telep", "Cov", "Fart"};
    char rue[5][30] = {"Blv", "rue", "chm", "imp", "rocade"};
    char ville[5][30] = {"lille", "Lyon", "marseille", "paris", "charbo"};
    short notes[5][2] = {{12,10}, {12,10}, {12,10}, {12,10}, {12,10}};

    //affichage des donnees
    for (int i = 0; i < 5; i++) {
        printf("Prenoms : %s, Nom : %s, rue : %s, Ville : %s, Notes 1: %hu, Notes 2 : %hu\n", prenom[i], nom[i], rue[i], ville[i], notes[i][0], notes[i][1]);
    }
    return 0;

};