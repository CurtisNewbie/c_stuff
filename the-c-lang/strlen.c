#include <stdio.h>

int strlength(char*);

int main()
{
    char str[] = "abcde";
    printf("str: %s\n", str);
    printf("str starting from 0, len = %d\n", strlength(&str[0]));

    char* p = str;
    printf("str starting from 0, len = %d\n", strlength(p));

    // we can pretend that we pass part of an array to the method as follows
    printf("str starting from 2, len = %d\n", strlength(&str[2]));
    printf("str starting from 2, len = %d\n", strlength(p + 2));
}

/*
str is a pointer, and it itself is also a variable storing the address to other variables. In this case, it's a string or an array, which is essentially pointing to str[0], we can then increment the address to traverse the elements within this string/array.
*/
int strlength(char* str)
{
    int i;
    // increments address to access str[?]
    for (i = 0; *str != '\0'; str++)
        i++;
    return i;
}