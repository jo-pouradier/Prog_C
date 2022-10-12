#include <stdio.h>
#include <stdlib.h>

int main(){
    struct couleur { int r, g, b, a; };
    struct nbr_couleur {struct couleur clr; int nbr;};

    //creation du tableau de nbr_color couleurs
    const int nbr = 100;
    struct couleur couleurs[nbr];
    for (int i=0; i < nbr; i++) {
        (couleurs + i)->r = rand() %255;
        (couleurs + i)->g = rand() %255;
        (couleurs + i)->b = rand() %255;
        (couleurs + i)->a = rand() %255;
    }


    //comptage des couleurs
    struct nbr_couleur nbr_clr[nbr];
    for (int i=0; i < nbr; i++){
        (nbr_clr + i)->clr = *(couleurs+i);
        (nbr_clr + i)->nbr = 0;
        for (int j=0; j < nbr; j++) {
            if ((nbr_clr + i)->clr.r == (couleurs + j)->r && (nbr_clr + i)->clr.g == (couleurs + j)->g && (nbr_clr + i)->clr.b == (couleurs + j)->b && (nbr_clr + i)->clr.a == (couleurs + i)->a){
                (nbr_clr + i)->nbr++;
            }
        }
    }

    //affichage du tableau de couleurs et son nombre
    for (int i=0; i < nbr; i++) {
        printf("%x, %x, %x, %x\n", (couleurs + i)->r, (couleurs + i)->g, (couleurs +i)->b, (couleurs + i)->a);
    }
    printf("\n");
    for (int i=0; i < nbr; i++) {
        printf("%x, %x, %x, %x, nbr = %i \n", (nbr_clr + i)->clr.r, (nbr_clr + i)->clr.g, (nbr_clr +i)->clr.b, (nbr_clr + i)->clr.a, (nbr_clr +i)->nbr);
    }
}