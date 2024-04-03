/**
 This file includes Exercise 4-3 to exercise 4-5
 The RPN assume input are sperate by space: Eg 5 7 + -4.7
 **/

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
double value[BUFFSIZE];
char charBuff[BUFFSIZE];

int getch(void);
void ungetch(int);
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

    // Remove pre-spaces,tabs
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (isalpha(c))
    {
        while (isalpha(s[i++] = c = getch()));
        s[i-1] = '\0';
        if (c != EOF)
        {
            ungetch(c);
        }
        return MATHFUNCTION;
    }


    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    // Exercise 4-3
    if (c == '-' || isdigit(c)) // collect integer part along with '-'
        while (isdigit(s[i++] = c = getch()));
    
    if (c == '.') // collect fraction part
        while (isdigit(s[i++] = c = getch()));
    s[i-1] = '\0';
    

    if (c != EOF)
    {
        ungetch(c);
    }
        
    if (strcmp(s, "-") == 0)
    {
        return '-';
    }

    return NUMBER;
}

void ungetch(int c) 
{
    if (charBuffSp >= BUFFSIZE)
    {
        printf("ungetch: too many characters\n"); 
    }
    else
    {
        charBuff[charBuffSp++] = c;    
    }
}

int getch(void) 
{ 
    return (charBuffSp > 0) ? charBuff[--charBuffSp] : getchar(); 
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

