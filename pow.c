#include <stdio.h>

/* Calculate base^power */
int power(int, int);

int main()
{
    printf("2^3 = %d\n", power(2, 3));
}

int power(int base, int power)
{
    int res = 1;
    if (power == 0)
        return res;

    for (int i = 1; i <= power; i++) {
        res *= base;
    }
    return res;
}