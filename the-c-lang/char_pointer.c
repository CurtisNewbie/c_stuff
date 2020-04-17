#include <stdio.h>

void strcopy(char* from, char* to);
void enhancedStrCopy(char* from, char* to);
int strcmp(char* s, char* t);

int main()
{
    // a string is not handled as a unit in c
    char* ps;
    ps = "yo, whats up";
    // ps doesn't store the values, instead, it's automatically assigned #
    // to the address to the first char in this string
    printf("Variable of which the *ps pointing to: %c\n", *ps);

    // as we initialised this string with a pointer, we need a loop to print it
    printf("Print this string by incrementing *ps:\n");
    while (*ps != '\0') {
        printf("%c", *ps);
        ps++;
    }
    printf("\n");

    // array is different from a pointer
    char arr[] = "I am an array";
    char* point = "I am a pointer pointing to a string";
    char to[11];
    char enhTo[11];
    strcopy(arr, to);
    printf("strcopy() - Copied array, To: '%s'\n", to);
    enhancedStrCopy(arr, enhTo);
    printf("enhancedStrCopy() - Copied array, To: '%s'\n", enhTo);
    printf("Compare 'abc' and 'aBC: ");
    int res = strcmp("abc", "aBC");
    if (res = 0)
        printf("Same\n");
    else if (res < 0)
        printf("%s < %s\n", "abc", "aBC");
    else
        printf("%s > %s\n", "abc", "aBC");
}

/* Copy string by traversing the all characters rathen than just the pointer*/
void strcopy(char* from, char* to)
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}

/* enhanced version in terms of readability */
void enhancedStrCopy(char* from, char* to)
{
    while (*to++ = *from++)
        ;
}

// compare two strings lexicographically, essentially, it compares the char code in the strings
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