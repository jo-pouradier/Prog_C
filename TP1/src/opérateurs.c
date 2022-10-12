/*
    AUTEUR : Joseph Pouradier Duteil
*/
#include <stdio.h>

int main()
{
    float a = 57;
    float b = 2;

    // opérateurs logiques
    int not_a = !a;
    int and = a && b;
    int or = a || b;
    printf("logical not a = %i\n", not_a);
    printf("logical a and b = %i\n", and);
    printf("logical a or b = %i\n", or);

    // opérateurs arithmetique
    short add = a + b;
    short minus = a - b;
    int multiply = a * b;
    int div = a / b;
    short mod = ((int)a) % ((int)b);
    printf("arithmetique add = %hd\n", add);
    printf("arithmetique minus = %hd\n", minus);
    printf("arithmetique multiply = %i\n", multiply);
    printf("arithmetique div = %i\n", div);
    printf("arithmetique mod = %hd\n", mod);
}