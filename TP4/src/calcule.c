#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main (int argc, char **argv){
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    char *op  = argv[1];

    //input des parametres
    printf ("Operation = ");

    switch (*op){
        case '+':
            somme(&num1,&num2);
            break;
        case '-':
            difference(&num1,&num2);
            break;
        case '*':
            produit(&num1,&num2);
            break;
        case '/':
            quotient(&num1,&num2);
            break;
        case '%':
            modulo(&num1,&num2);
            break;
        case '&':
            et(&num1,&num2);
            break;
        case '|':
            ou(&num1,&num2);
            break; 

        default:
            break;
    }

    printf ("%i \n", num1);
}