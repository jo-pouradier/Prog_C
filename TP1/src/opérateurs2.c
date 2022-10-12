#include <stdio.h>

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
            printf("%i", num1+num2);
            break;
        case '-':
            printf("%i", num1-num2);
            break;
        case '*':
            printf("%i", num1*num2);
            break;
        case '/':
            printf("%i", num1/num2);
            break;
        case '%':
            printf("%i", num1%num2);
            break;
        case '&':
            printf("%i", num1&num2);
            break;
        case '|':
            printf("%i", num1|num2);
            break; 
        case '<':
            printf("%i", num1<num2);
            break;
        case '>': 
            printf("%i", num1>num2);
            break;

        default:
            break;
    }
}