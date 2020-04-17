#include <stdio.h>

#define MAX_LINE_LENGTH 10

/* Get line from stdin and return length of this line */
int getLine(void);
/* copy a line*/
void copy(void);

// external variables
int maxLen = 0;
char currLine[MAX_LINE_LENGTH];
char longest[MAX_LINE_LENGTH];

/* Using external variables*/
int main()
{
    int currLen;
    extern int maxLen;
    extern char longest[];

    // only accept 3 lines
    for (int i = 0; i < 3 && (currLen = getLine()) > 0; i++) {
        if (currLen > maxLen) {
            maxLen = currLen;
            copy();
        }
    }

    if (maxLen > 0)
        printf("Longest: '%s'\nLength:%d\n", longest, maxLen);
    return 0;
}

int getLine(void)
{
    int maxLineLength = MAX_LINE_LENGTH;
    extern char currLine[];
    int c;
    int i;
    for (i = 0; i < maxLineLength - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        currLine[i] = c;
    }

    // last char must be '\0', it marks the end. It's so called null character.
    currLine[i] = '\0';
    return i;
}

void copy(void)
{
    int i = 0;
    extern char currLine[];
    extern char longest[];
    while ((longest[i] = currLine[i]) != '\0')
        ++i;
}
