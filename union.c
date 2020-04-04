#include <stdio.h>

#define INT 1
#define FLOAT 2
#define STRING 3

/* this union can be of three different types, int, float or char* */
union Data {
    int ival;
    float fval;
    char* sval;
} u;

/* type of union that is used*/
int type;

void printUnion();

/* 
"A union is a variable that may hold (at different times) objects of different types and sizes. In effect, a union is a structure in which all members have offset zero from the base, the structure is big enough to hold the ``widest'' member" 

This is not needed 95% of the time, but it's often very useful in embedded programming or when you want to save memory.

https://stackoverflow.com/questions/252552/why-do-we-need-c-unions

members in union are accessed as follows:

    union_name.member

    or 

    union_ptr->member

we may often have a variable to keep track of the type that is used

*/
int main()
{
    type = INT;
    u.ival = 123;
    printUnion();

    type = FLOAT;
    u.fval = 123.1;
    printUnion();

    type = STRING;
    u.sval = "abc";
    printUnion();
    return 0;
}

void printUnion()
{
    if (type == INT)
        printf("ival : %d\n", u.ival);
    else if (type == FLOAT)
        printf("fval : %f\n", u.fval);
    else if (type == STRING)
        printf("sval : '%s'\n", u.sval);
    else
        printf("error - unknown type being use");
}

/*

union can also be in structure

*/
struct {
    int size;
    // as for struct, the name is optional
    union {
        int ival;
        float fval;
        char* sval;
    } un;
} StructuredData;