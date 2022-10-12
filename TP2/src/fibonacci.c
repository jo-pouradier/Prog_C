#include <stdio.h>

//fct qui calcul la suite de fibonacci
int* suite_fibo(int n, int *suite){
    int u0 = 0;
    int u1 = 1;

    suite[0] = u0;
    suite[1] = u1;

    for (int i = 2; i < n; i++){
        suite[i] = suite[i-1] + suite[i-2];
    }

    return suite;
}

int main(){
    //init variables
    int n;
    printf("nombre de valeur a afficher : ");
    scanf("%i",&n);
    int suite[n];

    //calcul du resultat
    int *res = suite_fibo(n, suite);

    //affichage du resultat
    for (int i = 0; i < n; i++) {
    printf("valeur %i = %i\n", i, res[i]);
    
    }

}