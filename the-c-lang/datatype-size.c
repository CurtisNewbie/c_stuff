#include <float.h>
#include <limits.h>
#include <stdio.h>

int main()
{
    printf("-------------------\n");
    printf("\nlimits.h\n\n");
    printf("-------------------\n");
    printf("Unsigned datatype is always positive (e..g, int, char, etc), and they are always of 2^n\n");
    printf("Signed char max: %d, Unsigned char max: %d\n", SCHAR_MAX, UCHAR_MAX);
    printf("Signed char min: %d, Unsigned char min: %d\n", SCHAR_MIN, 0);
    printf("Signed int max: %d, Unsigned int max: %d\n", INT_MAX, UINT_MAX);
    printf("Signed int min: %d, Unsigned int min: %d\n", INT_MIN, 0);
    printf("Signed long max: %ld, Unsigned long max: %ld\n", LONG_MAX, ULONG_MAX);
    printf("Signed long min: %ld, Unsigned long min: %d\n", LONG_MIN, 0);
    printf("Signed short max: %d, Unsigned short max: %d\n", SHRT_MAX, USHRT_MAX);
    printf("Signed short min: %d, Unsigned short min: %d\n", SHRT_MIN, 0);

    printf("-------------------\n");
    printf("\nfloat.h\n\n");
    printf("-------------------\n");
    printf("float max: %f\nfloat min: %f\n", FLT_MAX, FLT_MIN);
    printf("double max: %lf\ndouble min: %lf\n", DBL_MAX, DBL_MIN);
    printf("\n");
}