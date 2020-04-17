#include <stdio.h>
#include <string.h>

int main()
{
    int size = 500;
    char str[size], *sp;
    sp = str;

    char* filename = "/home/yongjie/git/c-tut/the-c-lang/temp.txt";

    /* a FILE type defined in stdio.h, and this is a pointer pointing to an external file*/
    FILE* fp;

    /* use fopen() to open connection to an external file, mode includes: 'r' 'w' 'a' (append) and 'b' (for binary) */
    fp = fopen(filename, "r");

    /*
    ------------------------------------
    
    Read from file
    
    ------------------------------------
    */
    int c;
    if (fp != NULL) { /* no error found */
        // read char from the file one by one
        for (int i = 0; i < size - 1 && (c = getc(fp)) != EOF; i++) {
            *sp++ = c;
        }
        *sp = '\0';
        printf("%s\n", str);
    }

    /*
    ------------------------------------
    
    Write to file
    
    ------------------------------------
    */
    fp = fopen(filename, "w"); /* write mode*/
    char* txt = "I love banana! :D";
    int l = strlen(txt);
    for (int i = 0; i < l; i++) {
        putc(*(txt + i), fp);
    }

    fclose(fp); /* close file*/
    return 0;
}