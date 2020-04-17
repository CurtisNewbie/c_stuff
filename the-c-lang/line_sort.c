#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 5
#define MAX_LEN 500

void readlines(char* linesp[], int n);
void readline(char* lp);
void printLines(char* linesp[], int n);
void sortLines(char* linesp[], int n);
void quickSort(char* linesp[], int l, int h);
void swap(char* ptrs[], int l, int r);
int strcmp(char* s, char* t);

/* sort all the lines read from input */
int main()
{
    // create an array of pointers (pointer that points to pointer)
    char* linesp[MAX_LINES + 1];
    // alloc mem
    for (int i = 0; i < MAX_LINES; i++) {
        linesp[i] = malloc(MAX_LEN * sizeof(char));
    }

    readlines(linesp, MAX_LINES);
    sortLines(linesp, MAX_LINES);
    printLines(linesp, MAX_LINES);

    // free mem
    for (int i = 0; i < MAX_LINES; i++) {
        free(linesp[i]);
    }
}

void readlines(char* linesp[], int n)
{
    for (int i = 0; i < n; i++)
        readline(linesp[i]);
}

void readline(char* lp)
{
    int c;
    for (int i = 0; (c = getchar()) != EOF && c != '\n' && i < MAX_LEN; i++) {
        *lp++ = c;
    }
    *lp = '\0';
}

void printLines(char* linesp[], int n)
{
    printf("\nlines:\n");
    for (int i = 0; i < n; i++)
        printf("[%d] '%s'\n", i, *(linesp + i)); // we can also use linesp[i]
}

void sortLines(char* linesp[], int n)
{
    quickSort(linesp, 0, n - 1);
}

void quickSort(char* linesp[], int l, int h)
{
    if (l >= h) {
        return;
    }

    // swap between low and mid
    swap(linesp, l, (l + h) / 2);

    // pivot is the mid, and it's pointer to pointer, thus **
    char** pivot = &linesp[l];
    int pIndex = l; /*pivot index*/

    // compare with pivot starting from l + 1, meanwhile pIndex is moving toward right until
    // all are partially sorted (in comparison to the pivot value)
    for (int i = l + 1; i <= h; i++)
        if (strcmp(linesp[i], &(**pivot)) < 0) // is lexicographically smaller
            swap(linesp, ++pIndex, i);

    swap(linesp, l, pIndex); // pivot was always used to compare, but it's still at l.
    quickSort(linesp, l, pIndex - 1);
    quickSort(linesp, pIndex + 1, h);
}

/* swap address of pointers*/
void swap(char* ptrs[], int l, int r)
{
    char* t = ptrs[l];
    ptrs[l] = ptrs[r];
    ptrs[r] = t;
}

// compare two strings lexicographically
int strcmp(char* s, char* t)
{
    // skip those identical characters
    while (*s == *t) {
        if (*s == '\0')
            return 0;
        s++;
        t++;
    }
    return *s - *t;
}
