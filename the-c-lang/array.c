#include <stdio.h>

int main()
{
    int len = 10;
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printf("arr[] = [");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i != len - 1)
            printf(", ");
    }
    printf("]\n");

    int* pa; // init pointer
    pa = &arr[0]; // pointing to arr[0], i.e., assign address of arr[0] to pa
    printf("pa pointing to arr[0]: %d\n", *pa);

    // to change the pointer pointing to arr[1], we can achieve this as follows:
    pa = &arr[1];
    printf("( &arr[1] ) pa pointing to arr[1]: %d\n", *pa);

    // we can also achieve this by incrementing pa, since the array is a list of consequtive memory address
    pa += 1;
    printf("( pa += 1 ) pa pointing to arr[2]: %d\n", *pa);

    // or we can calculate the address wihout incrementation
    printf("( *(pa + 1) ) pa pointing to arr[3]: %d\n", *(pa + 1));

    // the address of an array is always arr[0]
    // and arr[i] is the same as *arr[0 + i]
    pa = &arr[0];
    printf("( &arr[0] ) pa pointing to arr[0]: %d\n", *pa);
    pa = arr;
    printf("( arr ) pa pointing to arr: %d\n", *pa);
}