#include <stdio.h>

#define MAX_LINE_LENGTH 10
/* Get line from stdin and return length of this line */
int getLine(char[], int);
/* copy a line*/
void copy(char[], char[]);

int main()
{
    int currLen;
    int maxLen = 0;
    char currLine[MAX_LINE_LENGTH];
    char longest[MAX_LINE_LENGTH];

    // only accept 3 lines
    for (int i = 0; i < 3 && (currLen = getLine(currLine, MAX_LINE_LENGTH)) > 0; i++) {
        if (currLen > maxLen) {
            maxLen = currLen;
            copy(longest, currLine);
        }
    }

    if (maxLen > 0)
        printf("Longest: '%s'\nLength:%d\n", longest, maxLen);
    return 0;
}

// line[] is the address of this array, maxLineLength is a value copied.
int getLine(char line[], int maxLineLength)
{
    int c;
    int i;
    for (i = 0; i < maxLineLength - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    // last char must be '\0', it marks the end. It's so called null character.
    line[i] = '\0';
    return i;
}

// both to[] and from[] are addresses pointing to them
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
