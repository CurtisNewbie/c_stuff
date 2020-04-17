#include <stdbool.h>
#include <stdio.h>

// ASCII 128 charset
#define MAX_PAIRS 128
#define MAX_LEN_PER_LINE 500

struct pair {
    char key;
    int count;
};

void initMap(struct pair*, int*);
void printMap(struct pair*, int*, bool);
void readline(char*);
void parseLine(char*, struct pair*, int*);
int findChar(char*, struct pair*, int*);

// a program that counts occurences of each char to demonstrate how to use the array of struct
int main()
{
    int len = 0;
    struct pair map[MAX_PAIRS], *mp;
    mp = map;

    initMap(mp, &len);
    printMap(mp, &len, true);

    char line[MAX_LEN_PER_LINE];
    readline(line);

    printf("\nYou entered: '%s'\n", line);
    parseLine(line, mp, &len);
    printMap(mp, &len, false);

    return 0;
}

void initMap(struct pair* mp, int* len)
{
    // init 128 ASCII char set in map
    int i;
    for (i = 0; i < MAX_PAIRS; i++) {
        struct pair t = { 0 + i, 0 };
        // map[i] = t;
        *(mp++) = t;
    }
    *len = i;
}

void printMap(struct pair* mp, int* len, bool printZero)
{
    printf("\nMap: len = %d, Char Occurrence:\n", *len);
    for (int i = 0; i < *len; i++) {
        if (printZero || (mp + i)->count > 0)
            printf("[ASCII %d] {%c, %d}\n", i, (mp + i)->key, (mp + i)->count);
    }
}

// read a line from stdin
void readline(char* str)
{
    printf("\nEnter a line of char, then I will show you the occurences of each character:\n");
    int c;
    for (int i = 0; i < MAX_LEN_PER_LINE && (c = getchar()) != EOF && c != '\n'; i++) {
        *str++ = c;
    }
    *str = '\0';
}

// parse the line, counting the occurences of each char in the line
void parseLine(char* line, struct pair* mp, int* len)
{
    while (*line != '\0') {
        int pos = findChar(line, mp, len);

        if (pos != -1) // found
            ((mp + pos)->count)++;
        else
            printf("Error, found an unknown char : %c\n", *line);

        // moves the pointer
        line++;
    }
}

// binary search, that checks whether the char in the map; if not returns -1, else return sthe position of it in the map
int findChar(char* c, struct pair* mp, int* len)
{
    int l, h, m;
    l = 0;
    h = *len - 1;

    while (l <= h) {
        m = (l + h) / 2;

        char midChar = (mp + m)->key;
        if (*c == midChar) // found
            return m;
        else if (*c < midChar)
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}