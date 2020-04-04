#include <stdio.h>

/*

    typedef is a facility for creating new data type names.

    I.e., it defines a name as a synonym for a type


*/
int main()
{
    typedef int Len; /* Len is a synonym of int type */
    Len l = 15;
    printf("Len: %d\n", l);

    typedef char* String; /* String is a synonym of char* pointer*/
    String s = "I am a String";
    printf("String: %s\n", s);

    return 0;
}