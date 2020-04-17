#include <stdio.h>

int main()
{
    // int is used intentionally for detecting EOF
    int c;

    // getchar() is a way to read single char from a stream
    c = getchar();

    // EOF is a int constant in stdio.h
    while (c != EOF)
    {
        // put this char back to a stream
        putchar(c);

        // copy next char
        c = getchar();
    }
}