#include <stdio.h>

int main(){
    //init variabels
    const int table_size = 5;
    int table_integer[table_size] = {13, 56, 37, 84, 100};
    float table_float[table_size] = {0.45, 1.3, 2.99, 3.5, 40.03};

    //creation des ptr
    int* ptr_table_integer = &table_integer;
    float* ptr_table_float = &table_float;

    //multiplicationd e l'ensemble du tableau
    for (int i = 0; i < table_size; i++) {
        if (i%2 == 0){
            *(ptr_table_integer + i) *= 3;
            *(ptr_table_float + i) *= 3;
        }
    }

    //affichage
    for (int i = 0; i < table_size; i++) {
        printf("table_intger %d : %i\n", i, *(ptr_table_integer + i));
    }
    for (int i = 0; i < table_size; i++) {
        printf("table_float %d : %f\n", i, *(ptr_table_float + i));
    }
}