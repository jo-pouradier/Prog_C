#ifndef __OPERATOR__H
#define __OPERATOR__H

void somme(int *a, int *b){
    *a += *b;
}

void difference(int *a, int *b){
    *a -= *b;
}

void produit(int *a, int *b){
    *a *= *b;
}

void quotient(int *a, int *b){
    *a /= *b;
}

void modulo(int *a, int *b){
    *a %= *b;
}

void et(int *a, int *b){
    *a = *a & *b;
}

void ou(int *a, int *b){
    *a = *a | *b;
}

#endif