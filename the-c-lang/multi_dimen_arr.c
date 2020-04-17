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

    printf("------------------------------\n");

    /*
    an array is not a pointer, it can however sometimes be decayed to a pointer pointing to the first element. 
    
    "The multidimensional arrays are simply syntactic sugar. Behind the scenes this is simply a one dimensional array 10 * 20 ints long. When you access an element at x[5][6] the compiler generates the equivalent to x[5 * 20 + 6];"

    https://stackoverflow.com/questions/11511779/pointers-and-multi-dimensional-arrays#

    It's rather easy to get confused about the differences between an array of pointers and a two dimensional array.

    */
    char x[] = "x string";
    char y[] = "y string";
    printf("x: '%s'\n", x);
    printf("y: '%s'\n\n", y);

    char* arrOfPtrs[10]; // array of pointers
    char arr[10][10]; // two dimensional array

    // first pointer, point to the whole string, so the [0][1] while refers to the first char in string x. I.e., [0][1], [0] refers to the first pointer, [1] refers to the first value in the variable pointed by thie pointer
    arrOfPtrs[0] = x;
    // this is the same as above, since x is kinda equivalent to x[0]
    arrOfPtrs[2] = &x[0];

    // the first pointer, points to something, where the first char is y[0]
    arrOfPtrs[1][0] = y[0];
    arrOfPtrs[1][1] = y[1];
    arrOfPtrs[1][2] = y[2];
    arrOfPtrs[1][3] = y[3];

    // since this is a two-dimensional array, if x or y exceeds the size of 10, it will be out-of-bound, or i.e., we can only stores 10 chars in each row
    arr[0][0] = x[0];
    arr[0][1] = x[1];
    arr[0][2] = x[2];
    arr[0][3] = x[3];
    // arr[1] = y;  we cannot do this

    // the values stored in/ pointed to, in both of them can be accessed
    // using the same syntax: arr[x][y]
    printf("(arrOfPtrs[0] = x) -> arrOfPtrs[0]: '%s'\n", arrOfPtrs[0]);
    printf("(arrOfPtrs[0] = x) -> *arrOfPtrs[0]: '%c'\n", *arrOfPtrs[0]);
    printf("(arrOfPtrs[0] = x) -> arrOfPtrs[0][0]: '%c'\n\n", arrOfPtrs[0][0]);

    printf("(arrOfPtrs[2] = &x[0]) -> arrOfPtrs[2]: '%s'\n", arrOfPtrs[2]);
    printf("(arrOfPtrs[2] = &x[0]) -> *arrOfPtrs[2]: '%c'\n\n", *arrOfPtrs[2]);

    printf("(arrOfPtrs[1][0] = y[0]) -> arrOfPtrs[1][0]: '%c'\n", arrOfPtrs[1][0]);
    printf("(arrOfPtrs[1][1] = y[1]) -> arrOfPtrs[1][1]: '%c'\n\n", arrOfPtrs[1][1]);

    printf("// not properly displayed wihout '\\0'\n");
    printf("arrOfPtrs[1] without '\\0': '%s'\n", arrOfPtrs[1]); // not properly displayed wihout '\0'
    arrOfPtrs[1][4] = '\0';
    printf("(arrOfPtrs[1][4] = '\\0') arrOfPtrs[1] with '\\0': '%s'\n\n", arrOfPtrs[1]);

    printf("arr[0][0]: '%c'\n", arr[0][0]);
    printf("arr[0][1]: '%c'\n", arr[0][1]);
    printf("arr[0][2]: '%c'\n", arr[0][2]);
    printf("arr[0][3]: '%c'\n", arr[0][3]);
}
