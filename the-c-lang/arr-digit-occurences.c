#include <stdio.h>

int main()
{
    int i; /* index used to traverse the array*/
    int c; /* current char being read*/
    int nwhite, nother; /* num of spaces and others (non-digit)*/
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != '\n') {
        // this works by comparing char code value
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("Digits:      0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurrences:");
    for (i = 0; i < 10; i++) {
        printf(" %d", ndigit[i]);
    }
    printf(", spaces:%d, other:%d\n", nwhite, nother);
}
