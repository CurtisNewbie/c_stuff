#include <stdio.h>

void withExtern(void);
void withoutExtern(void);

// this cannot be accessed by other c files unless using extern
// this protects the other files from using this variable unintentionally
static int staticNumber = 10;

int main()
{
    withExtern();
    withoutExtern();
}

void withExtern(void)
{
    // since staticNumber is static, we must use extern to access to it
    // tho it's defined above main()
    extern int staticNumber;
    printf("With extern: %d\n", staticNumber);
}

void withoutExtern(void)
{
    // appears to be some random number
    int staticNumber;
    printf("Without extern: %d\n", staticNumber);
}
