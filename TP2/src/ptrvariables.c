#include <stdio.h>

int main()
{
    //data
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

    // print toute les taille des types de variables
    printf("taille en octet de char : %p\n", &my_char);
    printf("taille en octet de unsigned char : %p\n", &my_unsigned_char);
    printf("taille en octet de signed char : %p\n", &my_signed_char);

    printf("taille en octet de short : %p\n", &my_short);
    printf("taille en octet de unsigned short : %p\n", &my_unsigned_short);
    printf("taille en octet de signed short : %p\n", &my_signed_short);

    printf("taille en octet de int : %p\n", &my_int);
    printf("taille en octet de unsigned int : %p\n", &my_unsigned_int);
    printf("taille en octet de signed int : %p\n", &my_signed_int);

    printf("taille en octet de long int : %p\n", &my_long_int);
    printf("taille en octet de signed long int : %p\n", &my_signed_long_int);
    printf("taille en octet de unsigned long int : %p\n", &my_unsigned_long_int);

    printf("taille en octet de long long int : %p\n", &my_long_long_int);
    printf("taille en octet de signed long long int : %p\n", &my_signed_long_long_int);
    printf("taille en octet de unsigned long long int : %p\n", &my_unsigned_long_long_int);

    printf("taille en octet de float : %p\n", &my_float);

    printf("taille en octet de double : %p\n", &my_double);

    printf("taille en octet de long double : %p\n", &my_long_double);
}