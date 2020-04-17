#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORDS 5 /* max num of words read from stdin*/
#define MAXLEN 100 /* max len of each word*/

/* list of keywords that we are counting */
struct key {
    char* word;
    int count;
} keytab[] = {
    { "auto", 0 },
    { "break", 0 },
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
    { "continue", 0 },
    { "default", 0 },
    { "unsigned", 0 },
    { "void", 0 },
    { "volatile", 0 },
    { "while", 0 }
};

int getWord(char*, int);
int getWords(char*, int);
int binarySearch(char*, struct key*, int);

// count keywords
int main()
{
    int n = 0;
    int i;
    char word[MAXLEN];
    while (n++ < MAXWORDS && getWord(word, MAXLEN) != EOF) {
        i = binarySearch(word, keytab, MAXWORDS);
        if (i >= 0) {
            keytab[i].count++;
        }
    }
    // syntax: sizeof obj
    // syntax: sizeof (type_name)
    for (int j = 0; j < sizeof keytab / sizeof(struct key); j++) {
        printf("{ word: '%s', count:%d }\n", keytab[j].word, keytab[j].count);
    }
    return 0;
}

/* 
len: the length of the char[]

return the first char in this word
*/
int getWord(char* word, int len)
{
    int c, i;
    for (i = 0; i < len - 1 && (c = getchar()) != EOF && isalpha(c); i++)
        *(word + i) = c;

    *(word + i) = '\0';
    return *word;
}

/* binary search: find word in tab[0]...tab[n-1]; return -1 if not found*/
int binarySearch(char* word, struct key tab[], int n)
{
    int res;
    int l, h, m;

    l = 0;
    h = n - 1;
    while (l <= h) {
        m = l + (h - l) / 2;
        if ((res = strcmp(word, tab[m].word)) > 0)
            l = m + 1;
        else if (res < 0)
            h = m - 1;
        else
            return m;
    }
    return -1;
}
