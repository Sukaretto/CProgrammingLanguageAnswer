
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

#define BUFSIZE 100

#define MAXVAL 100

int sp = 0;
int bufp = 0;

double val[MAXVAL];
char buf[BUFSIZE];

int getch(void);

int getop(char[]);

void push(double);

double pop(void);

/* reverse polish calculator */

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error:zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("erro:zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[]) {
    int i, c;
    static int lastRead = 0;

    if (lastRead == 0)
    {
        c = getch();
    }
        
    else 
    {
        c = lastRead;
        lastRead = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t')
    {
        c = getch();
    }
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c; // not a number
    i = 0;
    if (c == '-' || isdigit(c)) // collect integer part along with '-'
        while (isdigit(s[++i] = c = getch()));
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';

    if (c != EOF)
    {
        lastRead = c;
    }
    
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}



int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}