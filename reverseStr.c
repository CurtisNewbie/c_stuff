#include <stdio.h>

#define LEN 1000

/*
------------------------------------

method definitions

------------------------------------
*/

void readLine();
void reverse();
void swap(int, int);

/*
------------------------------------

External variables

------------------------------------
*/

char line[LEN];
int len;

/*
------------------------------------

Main

------------------------------------
*/

int main()
{
    readLine(line);
    printf("Before: %s\n", line);
    reverse(line);
    printf("After: %s\n", line);
}

void readLine()
{
    int i, c;
    for (i = 0; i < LEN - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    line[i] = '\0';
    len = i - 1;
}

void reverse()
{
    swap(0, len);
}

char temp;
void swap(int l, int h)
{
    if (h > l) {
        temp = line[l];
        line[l] = line[h];
        line[h] = temp;

        swap(++l, --h);
    }
}
