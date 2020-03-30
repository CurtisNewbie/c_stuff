#include <stdio.h>

int main()
{
    int twoDimenArr[2][2] = { { 11, 12 },
        { 21, 22 } };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("[%d][%d]: %d\n", i, j, twoDimenArr[i][j]);
        }
    }

    /*
    an array is not a pointer, it can however sometimes be decayed to a pointer pointing to the first element. 
    
    "The multidimensional arrays are simply syntactic sugar. Behind the scenes this is simply a one dimensional array 10 * 20 ints long. When you access an element at x[5][6] the compiler generates the equivalent to x[5 * 20 + 6];"

    https://stackoverflow.com/questions/11511779/pointers-and-multi-dimensional-arrays#

    */
}