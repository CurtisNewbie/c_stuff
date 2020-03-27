#include <stdio.h>

int main()
{
    // items in enum are by default have an index start at 0
    enum months { ZERO,
        ONE,
        TWO };
    // we can specify values as well
    enum escapes { BELL = '\a',
        BACKSPACE = '\b',
        TAB = '\t' };
    return 0;
}