#include <stdio.h>

int main()
{
    int c;
    int tabs = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            ++tabs;
        }

        if (c == '\n')
            printf("Number of tabs:%d\n", tabs);
    }
}