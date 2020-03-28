#include <stdio.h>

void basic(void);
void swap(int, int);
void swapWithRef(int*, int*);

// pointer and address
int main()
{
    printf("-------------------\n");
    printf("\nBasic\n\n");
    printf("-------------------\n");
    basic();

    printf("-------------------\n");
    printf("\nSwap (pass by value)\n\n");
    printf("-------------------\n");
    int x = 'x';
    int y = 'y';
    printf("x: '%c'\ny: '%c'\n", x, y);
    swap(x, y);
    printf("After swapping (pass by values)\nx: '%c'\ny: '%c'\n", x, y);

    printf("-------------------\n");
    printf("\nSwap (passing address)\n\n");
    printf("-------------------\n");
    printf("x: '%c'\ny: '%c'\n", x, y);
    swapWithRef(&x, &y);
    printf("After swapping (passing address)\nx: '%c'\ny: '%c'\n", x, y);
}

void basic(void)
{
    int x = 'x';
    int y = 'y';
    printf("x: '%c'\ny: '%c'\n", x, y);
    int z[] = { 'z', 'o' };
    printf("z: ['%c', '%c']\n", z[0], z[1]);

    /*
    ------------------------------------
    
    - mark one as pointer using *
    - point to a variable using *
    - change address that the pointer is pointing to without *
    - get the address of a variable using &
    
    ------------------------------------
    */
    int* p; // not pointing to anything
    p = &x; // pointing to x
    printf("Pointer pointing to x: '%c'\n", *p); // dereferencing to the x using *p
    p = &y; // change and point to y
    printf("Pointer pointing to y: '%c'\n", *p); // dereferencing to the y using *p

    p = &x; // change back to pointing to x
    *p = y; // change value of x to y
    printf("Change value of x to y by pointer: x is now '%c'\n", x);

    p = &z[0]; // change pointer pointing to z[0]
    printf("Pointer pointing to z[0]: '%c'\n", *p); // dereferencing to the z[0] using *p
    p = &z[1]; // change pointer pointing to z[1]
    printf("Pointer pointing to z[1]: '%c'\n", *p); // dereferencing to the z[1] using *p

    int* np = p; // copy pointer
    printf("Copy pointer pointing to z[1]: '%c'\n", *p);
}

void swap(int x, int y)
{
    /*
    ------------------------------------
    
    c is pass by value, so original values
    are copied, and cannot really be changed
    
    ------------------------------------
    */
    int temp = x;
    x = y;
    y = temp;
}

void swapWithRef(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}