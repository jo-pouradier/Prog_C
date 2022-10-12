#include <stdio.h>

int main()
{
    // print toutes les tailles des types de variables
    printf("taille en octet de char : %lu\n", sizeof(char));
    printf("taille en octet de unsigned char : %lu\n", sizeof(unsigned char));
    printf("taille en octet de signed char : %lu\n", sizeof(signed char));

    printf("taille en octet de short : %lu\n", sizeof(short));
    printf("taille en octet de unsigned short : %lu\n", sizeof(unsigned short));
    printf("taille en octet de signed short : %lu\n", sizeof(signed short));

    printf("taille en octet de int : %lu\n", sizeof(int));
    printf("taille en octet de unsigned int : %lu\n", sizeof(unsigned int));
    printf("taille en octet de signed int : %lu\n", sizeof(signed int));

    printf("taille en octet de long int : %lu\n", sizeof(long int));
    printf("taille en octet de signed long int : %lu\n", sizeof(signed long int));
    printf("taille en octet de unsigned long int : %lu\n", sizeof(unsigned long int));

    printf("taille en octet de long long int : %lu\n", sizeof(long long int));
    printf("taille en octet de signed long long int : %lu\n", sizeof(signed long long int));
    printf("taille en octet de unsigned long long int : %lu\n", sizeof(unsigned long long int));

    printf("taille en octet de float : %lu\n", sizeof(float));

    printf("taille en octet de double : %lu\n", sizeof(double));

    printf("taille en octet de long double : %lu\n", sizeof(long double));
}