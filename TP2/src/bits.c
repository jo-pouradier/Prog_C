#include <stdio.h>

int main(){
    //input du nombre transformer
    long int a;
    printf("quelle nombre a convertir en binaire ? ");
    scanf("%lu",&a);

    //affichage du pointeur
    long int *ptra = &a;
    printf("ptr a = %p\n", ptra);

    // ET logique avec le nombre demander
    if ((*ptra & 0x80008) == 0x80008 ) { //524296
        printf("1\n");
    }else printf("0\n");

}