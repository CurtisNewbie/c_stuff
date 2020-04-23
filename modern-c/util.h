#include <stdio.h>
#include <stdlib.h>

/* print an array on console 
(*arr -> array; len -> length of the array) */
void printArr(int arr[], int len);

/* 
put random number (not really) into the arry 
(*arr -> array; len -> length of the array) */
void randArr(int arr[], int len);

void printArr(int arr[], int len)
{
    printf("Array: [");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        // putchar(arr[i] + '0'); // won't work if arr[i] > 9
        if (i != len - 1)
            putchar(' ');
    }
    putchar(']');
    putchar('\n');
}

void randArr(int arr[], int len)
{
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 10;
    }
}