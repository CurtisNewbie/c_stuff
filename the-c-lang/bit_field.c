#include <stdio.h>

struct { // do not assume the struct also only takes 1 bit, they are not the same thing
    unsigned int isWorking : 1; // only takes one bit size
} config;

/*
    Bit field is essentially a field that uses the specified the number of bits as its size

    Syntax:

        type member_name : bit_size;

    E.g., we can use it as boolean, where we only use 1 bit to turn it on or off as usual

    "Fields may be declared only as ints; for portability, specify signed or unsigned explicitly."
*/
int main()
{
    // we can use it as normal type for arithmatic
    config.isWorking = 1;

    if (config.isWorking == 1)
        printf("It's turned on\n");

    config.isWorking = 0;

    if (config.isWorking == 0)
        printf("It's turned off\n");

    return 0;
}