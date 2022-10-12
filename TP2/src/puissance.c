#include <stdio.h>

int main(){
    //init
    int a = 3;
    int x = a;
    int b = 3;

    //calcul de la puissance
    for (int i = 1; i < b; i++){
        a *= x;
    }

    //affichage
    printf("a = %i, b = %i\n a^b = %i\n", x,b, a);
    return 0;
}