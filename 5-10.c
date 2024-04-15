/*
    Program expr which evaluates a reverse Polish expression from the command line 
    where each operator or operand is a separate argument.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 100
#define NUMBER '0'

double valBuffer[MAXSIZE];
char checkType(char[]);
void push(double);
double pop(void);

double *bufferSp = &valBuffer[0];
double *bufferMaxSp = &valBuffer[MAXSIZE];

int main(int argc, char *argv[])
{
    char *argument;
    double op2;
    // You need at least input three operator or operand to calculate
    if (argc < 4)
    {
        printf("Error, not enough argument\n");
        exit(1);
    }
    
    while (--argc > 0)
    {
        argument = *++argv;
        switch (checkType(argument))
        {
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("Error: divided by 0\n");
            }
            break;
        case NUMBER:
            push(atoi(argument));
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Error: Unknown command %s\n", argument);
            break;
        }
    }
    
    printf("Value : %f \n", pop());


    return 0;
}

void push(double input)
{
    if (bufferSp < &valBuffer[MAXSIZE])
    {
        *bufferSp++ = input;
    }
    else
    {
        printf("Error, Full Stack\n");
    }

}

double pop(void)
{
    if (bufferSp > &valBuffer[0])
    {
        return *--bufferSp;
    }
    else
    {
        printf("Error, Empty Stack\n");
        return 0.0;
    }

}

char checkType(char s[])
{
    char c = s[0];

    while (*s++)
    {
        if (!isdigit(c) && c != '.')
        {
            return c;
        }
    } 
    return NUMBER;
}
