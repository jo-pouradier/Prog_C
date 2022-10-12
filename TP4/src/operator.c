#include <stdio.h>
#include "operator.h"

int main (){
    int num1;
    int num2;
    char op;

    //input des parametres
    printf("Donner deux nombre et un epérateur : \n");
    scanf("%d\n",&num1);
    scanf("%d\n",&num2);
    scanf("%c",&op);
    printf ("ok\n");
    printf ("Operation = ");

    switch (op){
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