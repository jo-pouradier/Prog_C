/*
    AUTEUR : Joseph Pouradier Duteil
*/
#include <stdio.h>

int main()
{
    char my_char = 'A';
    unsigned char my_unsigned_char = 'U';
    signed char my_signed_char = 'A';

    short my_short = 0;
    unsigned short my_unsigned_short = 10;
    signed short my_signed_short = 0;

    int my_int = 989;
    unsigned int my_unsigned_int = 989;
    signed int my_signed_int = 989;

    long int my_long_int = 99999999;
    unsigned long int my_unsigned_long_int = 99999999;
    signed long int my_signed_long_int = 99999999;

    long long int my_long_long_int = 999999999999;
    unsigned long long int my_unsigned_long_long_int = -999999999999;
    signed long long int my_signed_long_long_int = 999999999999;

    float my_float = 0.12;
    double my_double = 0.1;
    long double my_long_double = 0.1111;

    // print touts les types de variables
    printf("taille en octet de char : %c\n", my_char);
    printf("taille en octet de unsigned char : %hhu\n", my_unsigned_char);
    printf("taille en octet de signed char : %c\n", my_signed_char);

    printf("taille en octet de short : %hd\n", my_short);
    printf("taille en octet de unsigned short : %hu\n", my_unsigned_short);
    printf("taille en octet de signed short : %hd\n", my_signed_short);

    printf("taille en octet de int : %i\n", my_int);
    printf("taille en octet de unsigned int : %u\n", my_unsigned_int);
    printf("taille en octet de signed int : %i\n", my_signed_int);

    printf("taille en octet de long int : %ld\n", my_long_int);
    printf("taille en octet de signed long int : %lu\n", my_signed_long_int);
    printf("taille en octet de unsigned long int : %ld\n", my_unsigned_long_int);

    printf("taille en octet de long long int : %lld\n", my_long_long_int);
    printf("taille en octet de signed long long int : %llu\n", my_signed_long_long_int);
    printf("taille en octet de unsigned long long int : %llu\n", my_unsigned_long_long_int);

    printf("taille en octet de float : %f\n", my_float);

    printf("taille en octet de double : %f\n", my_double);

    printf("taille en octet de long double : %Lg\n", my_long_double);
}