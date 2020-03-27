#include <stdbool.h>
#include <stdio.h>

void printBinary(int);
void printTitle(char[], char[]);
void bitwiseAnd();
void bitwiseOr();
void bitwiseNot();
void bitwiseXor();

int main()
{
    bitwiseAnd();
    bitwiseOr();
    bitwiseNot();
    bitwiseXor();
}

void bitwiseAnd()
{
    printTitle("Bitwise AND", "Both 1 returns 1, else 0");
    int num1 = 37;
    int num2 = 23;
    printf("num1: %d ", num1);
    printBinary(num1);
    printf("num2: %d ", num2);
    printBinary(num2);

    int res = num1 & num2;
    printf("Bitwise AND: %d & %d = %d\n", num1, num2, res);
    printf("%d is same as: ", res);
    printBinary(res);
}

void bitwiseOr()
{
    printTitle("Bitwise OR", "One of them is 1 then returns 1, else 0");
    unsigned char num1 = 37;
    unsigned char num2 = 23;
    printf("num1: %d ", num1);
    printBinary(num1);
    printf("num2: %d ", num2);
    printBinary(num2);
    unsigned char res = num1 | num2;
    printf("Bitwise OR: %d | %d = %d\n", num1, num2, res);
    printf("%d is same as: ", res);
    printBinary(res);
}

void bitwiseNot()
{
    printTitle("Bitwise NOT", "Flip all bits");
    unsigned char num1 = 37;
    printf("num1: %d ", num1);
    printBinary(num1);
    unsigned char res = ~num1;
    printf("Bitwise NOT: ~%d = %d\n", num1, res);
    printf("%d is same as: ", res);
    printBinary(res);
}

void bitwiseXor()
{
    printTitle("Bitwise XOR", "If one is 1 and the other is 0, returns 1 else 0.");
    unsigned char num1 = 37;
    unsigned char num2 = 23;
    printf("num1: %d ", num1);
    printBinary(num1);
    printf("num2: %d ", num2);
    printBinary(num2);

    unsigned char res = num1 ^ num2;
    printf("Bitwise NOT: %d ^ %d = %d\n", num1, num2, res);
    printf("%d is same as: ", res);
    printBinary(res);
}

void printTitle(char title[], char msg[])
{
    printf("\n--------------------");
    printf("\n\n%s\n\n", title);
    printf("%s\n\n", msg);
    printf("--------------------\n");
}

// print binary literals; num should be no larger than 16 bits, and it should be positive
void printBinary(int num)
{
    // int is guaranteed 16 bits
    char binary[17];
    binary[17] = '\0';
    int i = 16;

    while (num != 0) {
        binary[i--] = (num % 2) + '0';
        num /= 2;
    }
    short l = 17 - i;
    if (l < 8)
        for (int j = 0; j <= 8 - l; j++) {
            printf("0");
        }

    for (i += 1; i < 17; i++) {
        printf("%c", binary[i]);
    }
    printf("\n");
}
