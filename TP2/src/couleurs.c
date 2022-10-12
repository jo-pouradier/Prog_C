#include <stdio.h>

struct couleur { int r, g, b, a; };

int main(){
    struct couleur couleurs[10];

    for (int i=0; i<10; i++) {
        couleurs[i].r = i*2;
        couleurs[i].g = i*10;
        couleurs[i].b = i*5;
        couleurs[i].a = i*10;
    }

    for (int i=0; i<10; i++) {
        printf("%x, %x, %x , %x \n", couleurs[i].r, couleurs[i].g, couleurs[i].b, couleurs[i].a);
    }

    return 0;
}