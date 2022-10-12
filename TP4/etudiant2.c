#include <stdio.h>

//creation sruct
struct etudiant{
    char prenom[30];
    char nom[30];
    char rue[30];
    char ville[30];
    short notes[2];
    };

int main(){
    //init data
    char Tprenom[5][30] = {"Adrein", "Pierre", "Louis", "Martin", "Hugues"};
    char Tnom[5][30] = {"Dalb", "Tlp", "Telep", "Cov", "Fart"};
    char True[5][30] = {"Blv", "rue", "chm", "imp", "rocade"};
    char Tville[5][30] = {"lille", "Lyon", "marseille", "paris", "charbo"};
    short Tnotes[5][2] = {{12,10}, {12,10}, {12,10}, {12,10}, {12,10}};


    struct etudiant petite_classe[5];

    //utilisation de la structure
    for (int i=0; i<5; i++){
        strcpy(petite_classe[i].prenom, Tprenom[i]);
        strcpy(petite_classe[i].nom, Tnom[i]);
        strcpy(petite_classe[i].rue, True[i]);
        strcpy(petite_classe[i].ville, Tville[i]);
        petite_classe[i].notes[0] = Tnotes[i][0];
        petite_classe[i].notes[1] = Tnotes[i][1];
    }
    
    //affichage
    for(int i = 0; i < 5; i++) {
        printf("Prenoms : %s, Nom : %s, rue : %s, Ville : %s, Notes 1: %hu, Notes 2 : %hu\n", petite_classe[i].prenom, petite_classe[i].nom, petite_classe[i].rue, petite_classe[i].ville, petite_classe[i].notes[0], petite_classe[i].notes[1]);
    }

}