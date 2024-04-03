#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER '0'
#define MATHFUNCTION '1'
#define BUFFSIZE 100

int valSp = 0;
int charBuffSp = 0;
char inputLine[BUFFSIZE] = {'\0'};
int inputLineSp = 0;
double value[BUFFSIZE];
char charBuff[BUFFSIZE];

int mgetline(char s[], int lenLimit);
int getop(char[]);
void push(double);
double pop(void);
void clearStack(void);
void mathFunction(char[]);

int main(void) {
    int type;
    double operand;
    double operand2nd;
    char userInput[BUFFSIZE]; 

    while ((type = getop(userInput)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(userInput));
                break;
            case MATHFUNCTION:
                mathFunction(userInput);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                operand2nd = pop();
                push(pop() - operand2nd);
                break;
            case '/':
                operand2nd = pop();
                if (operand2nd != 0.0)
                    push(pop() / operand2nd);
                else
                    printf("Error! Divided by 0 \n");
                break;
            // Exercise 4-3
            case '%':
                operand2nd = pop();
                if (operand2nd != 0.0)
                    push(fmod(pop(),operand2nd));
                else
                    printf("Error! Can't mod 0 \n");
                break;
            // Exercise 4-4 print top element without popping
            case '@':
                operand = pop();
                printf("\t%.8g\n", operand);
                push(operand);
                break;
            // Exercise 4-4 duplicate top element
            case '#':
                operand = pop();
                push(operand);
                push(operand);
            
                break;
            // Exercise 4-4 swap top two elements
            case '!':
                operand = pop();
                operand2nd = pop();
                push(operand);
                push(operand2nd);
                break;
            // Exercise 4-4 clear stack
            case '&':
                clearStack();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", userInput);
                break;
        }
    }
    return 0;
}

void push(double f) 
{
    if (valSp < BUFFSIZE)
    {
        value[valSp++] = f;
    }
    else
        printf("Error: Full stack \n");
}

double pop(void) 
{
    if (valSp > 0)
    {
        return value[--valSp];
    }
    else 
    {
        printf("Error: Empty Stack \n");
        return 0.0;
    }
}

int getop(char s[]) {
    
    int i = 1, c;
    
    if (inputLine[inputLineSp] == '\0')
    {
        if (mgetline(inputLine, BUFFSIZE) == 0) 
        {
            return EOF;
        }
        else inputLineSp = 0;
    }
    

    // Remove pre-spaces,tabs
    while ((s[0] = c = inputLine[inputLineSp++]) == ' ' || c == '\t');
    s[1] = '\0';

    if (isalpha(c))
    {
        while (isalpha(s[i++] = c = inputLine[inputLineSp++]));
        s[i-1] = '\0';

        return MATHFUNCTION;
    }


    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    // Exercise 4-3
    if (c == '-' || isdigit(c)) // collect integer part along with '-'
        while (isdigit(s[i++] = c = inputLine[inputLineSp++]));
    
    if (c == '.') // collect fraction part
        while (isdigit(s[i++] = c = inputLine[inputLineSp++]));
    s[i-1] = '\0';
    
    if (strcmp(s, "-") == 0)
    {
        return '-';
    }

    return NUMBER;
}

int mgetline(char s[], int lenLimit) {
    
    int i, c;
    for (i = 0; i < lenLimit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i++] = '\n';
    s[i] = '\0';

    return i;
}

void clearStack(void)
{
    valSp = 0;
}

// Exercise 4-5
void mathFunction(char s[])
{
    double op2;
    if (strcmp(s,"sin") == 0)
    {
        push(sin(pop()));
    }
    else if (strcmp(s,"exp") == 0)
    {
        push(exp(pop()));
    }
    else if (strcmp(s,"pow") == 0)
    {
        op2 = pop();
        push(pow(pop(),op2));
    }
    else
    {
        printf("Not support %s as math function \n",s);
    }
}

