#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 500
char* readline();

// https://stackoverflow.com/questions/7396925/when-should-i-use-free-in-c
// https://www.programiz.com/c-programming/c-dynamic-memory-allocation
int main()
{
    char* p = readline();
    printf("Allocated mem storing the line:\n'%s'\n", p);

    // after we done using it, we free the memory, only do it once
    free(p);

    // we shouldn't ever use, this is only to prove that it works
    printf("Mem freed:\n'%s'\n", p);

    // we should free() every pointers that point to memory allocated using
    // molloc. However, we don't always need to, as OS reclaims it when app stops.
}

// read one single line
char* readline()
{
    // allocate memeory
    char* lp = (char*)calloc(MAX_LEN, sizeof(char));
    char* res = lp;
    int c;
    for (int i = 0; (c = getchar()) != EOF && c != '\n' && i < MAX_LEN; i++) {
        *lp++ = c;
    }
    *lp = '\0';

    // return the pointer to the allocated memory
    return res;
}
