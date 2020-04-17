#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof()*/

#define NON_INT -1
#define INT 1

int getInt(int*);

int main()
{
    int num;
    int res = getInt(&num);
    if (res == INT)
        printf("Integer found: %d\n", num);
    else
        printf("Integer not found\n");
}

int getInt(int* p)
{
    char c;
    char integer[10]; // avoid overflow
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < 9) {
        if (isdigit(c))
            integer[i++] = c;
    }
    integer[i] = '\0';
    if (i > 0) {
        *p = atoi(integer);
        return INT;
    } else {
        return NON_INT;
    }
}