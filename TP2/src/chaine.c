#include <stdio.h>

int calcLengthMot();
void copyMot();
void concatenateMot();


int main(){
    //init des variables
    char mot1[] = "test 1 ";
    char mot2[] = "test 2 ";

    int longueurMot = 0;
    longueurMot = calcLengthMot(&mot1);
    printf("longueur_mot = %i\n", longueurMot);

    copyMot(&mot1, &mot2);
    printf("mot2 = %s\n", mot2);
    printf("mot1 = %s\n", mot1);

    int length1 = calcLengthMot(&mot1);
    int length2 = calcLengthMot(&mot2);
    char mot3[length1+length2];
    concatenateMot(&mot3, &mot1, &mot2);
    printf("mot3 = %s\n", mot3);

    return 0;
}

//calcul de la longeur d'un char
int calcLengthMot(char* ptrmot ){
    int i = 0;
    char l = *(ptrmot+i);
    while( l != '\0' ){
        i++;
        l = *(ptrmot+i);
    }
    return i;
};

void copyMot(char *ptrmot1, char *ptrmot2){
    int length = calcLengthMot(ptrmot1);
    for (int i = 0; i < length; i++){
        *(ptrmot2+i) = *(ptrmot1+i); 
    }
};

//concatenation de deux mots
void concatenateMot(char *mot3, char *mot1, char *mot2){
    int length1 = calcLengthMot(mot1);
    int length2 = calcLengthMot(mot2);

    for (int i = 0; i < length1; i++){
        *(mot3+i) = *(mot1+i);
        }

    for (int i = 0; i < length2; i++){
        *(mot3+length1 + i) = *(mot2+i);
    }
};

