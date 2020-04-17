#include <stdio.h>

int main()
{
    int c;
    int spaces = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            spaces++;
        else
            spaces = 0;

        if (spaces <= 1)
            putchar(c);
    }
}