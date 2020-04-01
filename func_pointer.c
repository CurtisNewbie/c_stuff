#include <stdio.h>

int getInt(int);
void doSomething(int (*)(int), int);

/* 
Function pointer is essentially a name that can refer to a specific function.
Which can be changed during runtime, it's similar to lambda expression in java or
those those in js. 
*/
int main()
{
    // we pass this function pointer to another function
    // the syntax is the same (*func_name)
    doSomething((*getInt), 12345);
}

int getInt(int n)
{
    printf("%d\n", n);
    return n;
}

/*
To use the function pointer:

    syntax: return_type (*func_name) (parameters)

Always has the parenthese with the * inside to refer to it as a function pointer

*/
void doSomething(int (*func)(int), int n)
{
    // this is just like callback function
    func(n);
}