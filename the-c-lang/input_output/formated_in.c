#include <stdio.h>
/*
------------------------------------

Formatted Input

------------------------------------
*/
int main()
{
    /*
    scanf() is similar to printf() except that it convert
    input in opposite direction

    the scanf() reads the specified value, converts it, and 
    then assign values to the given pointer
    */
    int a, b;
    if (scanf("%d", &a) == 1) /* read one item, which is an int*/
        printf("Read a: %d\n", a);

    if (scanf("%d", &b) == 1)
        printf("Read b: %d\n", b);

    /*
    Instead of reading from stdin, we can read from a string using sscanf()

    However, a better way to handle this will be to read a line first, and then use sscanf()
    */
    int c, d;
    char* str = "321  123 123123";
    if (sscanf(str, "%d      %d", &c, &d) == 2) { /* conversion specification, spaces/tabs/newline, etc., are ignored */
        printf("Read c: %d\n", c);
        printf("Read d: %d\n", d);
    }
    return 0;
}