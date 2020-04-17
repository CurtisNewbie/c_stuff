#include <ctype.h> /* for char*/
#include <stdio.h> /* stdio.h is for standard input and output*/

/*

When every reading data from or writing data to stdio, never assumes the one that you are
interacting with is the terminal. Since most OS support IO redirection, e.g., for Unix alike
OS, the > is used for redirecting output, and < is for redirecting input

    e.g.,

    program > outputfile

    program < inputfile

*/
int main()
{
    int c;

    // use getchar() to get a single char from stdin
    for (int i = 0; i < 10; i++) {
        c = getchar();
        // use EOF to avoid compatibility problem
        if (c != EOF && c != '\n') {
            // we can use printf to write stuff to stdout
            printf("%c ", tolower(c));

            // we can also push a single char to the stdout using putchar()
            putchar(toupper(c));
            printf("\n");
        }
    }
    return 0;
}