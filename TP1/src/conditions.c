#include <stdio.h>

int main (){
    //input du choix
    char possible;
    do{
        printf ("Donner a, b, ou c : \n");
        scanf("%c", &possible);
    }while ((possible != 'a') && (possible != 'b') && (possible != 'c'));
    
    //init des variables
    int A;
    int B;
    int nbr = 1000;

    switch (possible){
    case 'a':
        A = 2;
        B = 15;
        for (int i = 0; i <= nbr; i++){
            if (i%A == 0 && i%B == 0){
                printf("%i\n", i);
            }
        }
        break;
    
    case 'b':
        A = 103;
        B = 107;
        for (int i = 0; i <= nbr; i++){
            if (i%A == 0 || i%B == 0){
                printf("%i\n", i);
            }
        }
        break;

    case 'c':
        A = 5;
        B = 7;
        int c = 3;
        for (int i = 0; i <= nbr; i++){
            if ((i%A == 0 || i%B == 0) && (i%c != 0)){
                printf("%i\n", i);
            }
        }
        break;

    default:
        break;
    }
}