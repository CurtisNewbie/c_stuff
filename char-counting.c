#include <stdio.h>

/*count characters in input; 1st version*/
int main()
{
    // at least 32 bints
    long num = 0;
    int c;
    while ((c = getchar()) != EOF)
    {
        // newline is also counted as a character that is read by getchar()
        if (c == '\n')
            break;

        ++num;
    }
    printf("Number of Characters:%1ld\n", num);
}