#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> /* for atof()*/

#define MAX_VAL 100 /* maximum number of values in stack*/
#define MAX_OP 100 /* maximum number of operand and operator*/
#define MAX_LINE_LEN 500 /* maximum number of characters in the line*/
#define NUMBER '0'
/*
------------------------

Method Definition

------------------------
*/

void push(double);
double pop(void);
int next(char[]);
void readLine();
/*
------------------------------------

External variables

------------------------------------
*/

/* index in stack*/
int s = 0;
/* value stack*/
double valStack[MAX_VAL];
/* index j in line read from stdin*/
int j = 0;
/* line read from stdin*/
char line[MAX_LINE_LEN];

/* reverse polish calculator*/
int main()
{
    char val[MAX_OP];
    readLine();
    double op2;
    int type;

    while ((type = next(val)) != '\0') {
        switch (type) {
        case NUMBER:
            push(atof(val));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            push(pop() - pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("\nZero divisor");
            break;
        default:
            printf("\nerror: unknown command found %s", val);
            break;
        }
    }
    printf("\nAnswer:%lf", pop());
    return 0;
}

/* push value in to stack*/
void push(double val)
{
    if (s < MAX_VAL) {
        valStack[s++] = val;
    } else
        printf("\nError pushing value into stack, index:%d", s);
}

/* pop value from stack*/
double pop(void)
{
    if (s >= 0)
        return valStack[--s];
    else {
        printf("\nError poping value out of stack, index:%d", s);
        return 0.0;
    }
}

/* get next operator or numeric operand*/
int next(char nextOper[])
{
    int i = 0;
    int c;
    // skip all spaces and tabs
    while ((c = line[j++]) == ' ' || c == '\t')
        ;
    nextOper[0] = c;
    nextOper[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c; // not a number

    // is a digit or '.'
    i = 1;
    if (isdigit(c)) // collect integer part
        while (isdigit(c = line[j++]))
            nextOper[i++] = c;

    if (c == '.') { // collect fraction part
        nextOper[i++] = c;
        while (isdigit(c = line[j++]))
            nextOper[i++] = c;

        nextOper[i] = '\0';
    }
    return NUMBER;
}

/* read a line from stdin*/
void readLine()
{
    int i = 0, c;
    while ((c = getchar()) != EOF && c != '\n' && i < MAX_LINE_LEN - 1) {
        line[i++] = c;
    }
    line[i] = '\0';
}
