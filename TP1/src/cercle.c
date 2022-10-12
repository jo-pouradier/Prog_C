/*
    AUTEUR : Joseph Pouradier Duteil
*/
#include <stdio.h>
#include <math.h>

int main (){
    float rayon;
    
    //imput du rayon
    printf("Quel rayon ? ::");
    scanf("%f", &rayon);

    float aire = M_PI * rayon * rayon;
    float perimeter = M_PI * rayon * 2;

    //affichage resultat
    printf(" Le perimetre est de %f\n", perimeter);
    printf("L'aire est de %f\n", aire);
}