#include <stdio.h>

int main(){
    short sh = 30;
    int i = 333;
    float f = 1.0;
    double d = 12.40;
    long double ld = 134567.9;
    char *octets[6][16] = {&sh, &i, &f, &d, &ld};

    for (int i = 0; i < 6; i++) {
        printf("%x ", *octets[i]);
    }

}