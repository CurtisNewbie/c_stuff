#include <stdio.h>

/* CLI arguments, convetionally, two args are received, 'argc' for argument count, 'argv' for argument vector */
// try to run it like this: "./a.out apple juice", then you will see [apple juice]
int main(int argc, char* argv[])
{
    // the first one is the name of this program
    printf("You entered: '%s' to run this program\n", argv[0]);

    printf("Optional Arguments: [");
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i != argc - 1)
            printf(" ");
    }
    printf("]\n");
}