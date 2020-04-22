#include <stdio.h>
#include <stdlib.h>

/*
------------------------------------

Challenge 1

1) a merge sort with recursion

------------------------------------
*/

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

// sort and merge arr[l...m] and arr[m + 1...r]
void merge(int arr[], int l, int m, int r)
{
    int lLen = m - l + 1;
    int rLen = r - m;
    int lArr[lLen];
    int rArr[rLen];

    int i;
    for (i = 0; i < lLen; i++) {
        lArr[i] = arr[l + i];
    }

    for (i = 0; i < rLen; i++) {
        rArr[i] = arr[m + 1 + i];
    }

    int j = l;
    int la = 0;
    int ra = 0;

    while (la < lLen && ra < rLen) {
        if (lArr[la] <= rArr[ra])
            arr[j++] = lArr[la++];
        else
            arr[j++] = rArr[ra++];
    }

    while (la < lLen)
        arr[j++] = lArr[la++];

    while (ra < rLen)
        arr[j++] = rArr[ra++];
}

void splitMerge(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        splitMerge(arr, l, m);
        splitMerge(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(int arr[], int len)
{
    if (len > 0) {
        splitMerge(arr, 0, len - 1);
    }
}

int main()
{
    int len = 10;
    int arr[] = { 3, 6, 7, 5, 3, 5, 6, 2, 9, 1 };
    // int len = 6;
    // int arr[] = { 12, 11, 13, 5, 6, 7 };

    printArr(arr, len);
    mergeSort(arr, len);
    printArr(arr, len);

    return 0;
}
