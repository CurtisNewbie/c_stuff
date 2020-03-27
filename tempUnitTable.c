#include <stdio.h>

/*
Systematic way to define constants
*/
#define LOWER_BOUND 0   /* lower bound in fahrenheit */
#define UPPER_BOUND 300 /* upper bound in fahrenheit */
#define GAP 20          /* every n fahrenheit degree displayed */

/*
Print Fahrenheit-Celsius Table
*/
int main()
{
    /*
        float fahr, cels;
        int l, h, gap;
        l = LOWER_BOUND;
        h = UPPER_BOUND;
        gap = GAP;
    
        printf("%s %s\n", "Fahrenheit", "Celsius");
        fahr = l;
        while (fahr <= h)
        {
            cels = 5 * (fahr - 32) / 9;
            printf("%.1f\t%8.1f\n", fahr, cels);
            fahr += gap;
        }
    */

    printf("%s %s\n", "Fahrenheit", "Celsius");

    float cels;
    for (int fahr = LOWER_BOUND; fahr <= UPPER_BOUND; fahr += GAP)
    {
        cels = 5 * (fahr - 32) / 9;
        printf("%d\t%8.1f\n", fahr, cels);
    }
}