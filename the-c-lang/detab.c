#include <stdio.h>

#define SPACES_FOR_TAB 4
#define MAX_LEN 1000

void readLine(char[], int);

/* 
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?
*/
int main()
{
    char text[MAX_LEN];
    readLine(text, MAX_LEN);
    printf("Processed: '%s'\n", text);
}

void readLine(char text[], int len)
{
    int c, i, j;
    for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if (c == '\t') {
            for (j = i; j < SPACES_FOR_TAB + i && j < len - 1; j++)
                text[j] = '_'; // for demonstration only, it's supposed to be a space
            i += SPACES_FOR_TAB;
        } else {
            text[i] = c;
        }
    }
    text[i] = '\0';
}