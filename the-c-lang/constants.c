#include <stdio.h>

// int constant
#define MAX_AGE 12
// long constant
#define MAX_POPULATION 123456789l
// char constant
#define TOP_GRAGE 'A'
// octal constant, starts with 0
#define OCTAL_NUM 070
// hexdecimal constant, starts with \x
#define HEX_NUM '\x7'

int main()
{

    // #define is not the only way to make a variable constant
    // we can use const

    const int i = 4;
    printf("const i: %d\n", i);

    printf("int: %d\n", MAX_AGE);
    printf("long: %ld\n", MAX_POPULATION);
    printf("char: %c\n", TOP_GRAGE);
    printf("octal: %o\n", OCTAL_NUM);
    printf("hex: %x\n", HEX_NUM);
    return 0;
}