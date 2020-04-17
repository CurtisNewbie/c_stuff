#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
    int c;
    int state = OUT;
    long wc = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            break;

        // intentionally excludes '\n', so that this demo works
        if (c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            wc++;
        }
    }
    printf("Word Count: %ld\n", wc);
}