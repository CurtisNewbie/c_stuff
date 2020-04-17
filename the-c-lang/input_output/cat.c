#include <stdio.h>

void filecopy(FILE* in, FILE* out);

/* Cat Concatenate files */
int main(int argc, char* argv[])
{
    FILE* fp;

    if (argc == 1) {
        fprintf(stderr, "Please enter file paths.\n");
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) != NULL) { /* file opened */
                printf("\nCat: '%s'\n\n", *argv);
                filecopy(fp, stdout);
                fclose(fp);
            } else {
                fprintf(stderr, "Cannot open file: '%s'\n", *argv);
                return 1;
            }
        }

        if (ferror(stdout)) /* somethings wrong with the stdout stream*/
            fprintf(stderr, "standard output stream error occurred.");
    }
    return 0;
}

/* Copy chars from *in to *out */
void filecopy(FILE* inpt, FILE* outpt)
{
    char c;
    while ((c = getc(inpt)) != EOF) {
        putc(c, outpt);
    }
    putc('\n', outpt);
}