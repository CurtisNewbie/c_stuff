#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int l, int r)
{
    if (l != r) {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
    }
}

void qs(int arr[], int l, int r)
{
    if (l < r) {
        int pivot = arr[l];
        int i = l + 1; // forward searching
        int j = r; // backward searching

        while (i < j) {
            // find one that is less than pivot
            while (i <= j && arr[i] <= pivot)
                i++;

            // find one that is greate the pivot
            while (i <= j && arr[j] > pivot)
                j--;

            if (i < j) {
                swap(arr, i, j);
            }
        }

        // make sure j is at the correct position
        while (j > l && arr[j] >= pivot)
            j--;

        // assume l is the correct position of pivot
        int pi = l;
        // swapt j and pivot, if j is in fact the correct position of j
        if (pivot > arr[j]) {
            swap(arr, l, j);
            pi = j;
        }
        qs(arr, l, pi - 1);
        qs(arr, pi + 1, r);
    }
}

void quickSort(int arr[], int len)
{
    qs(arr, 0, len - 1);
}

/*
------------------------------------

Challenge 1

1) a quick sort with recursion 

------------------------------------
*/
int main()
{
    int len = 20;
    int arr[len];
    randArr(arr, len);
    printArr(arr, len);
    quickSort(arr, len);
    printArr(arr, len);
    return 0;
}