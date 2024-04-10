#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 1000
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;


int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*
    Exercise 5-1
*/
int getint( int *pn)
{
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c!= EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return EOF;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    if (!isdigit(c))
    {
        printf("Invalid Input after + or - sign \n");
        return EOF;
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int getfloat(double *pn)
{
    int c, sign;
    double power;

    while (isspace(c = getch()));

    if (!isdigit(c) && c!= EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return EOF;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    if (!(isdigit(c)))
    {
        printf("Invalid Input after + or - sign \n");
        return 0;
    }
    
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;

    if(c == '.')
    {
        c = getch();
        if (!isdigit(c))
        {
            printf("Invalid Input after .\n");
            return EOF;
        }
    }
    
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
        power *= 10;
    }

    if (c != EOF)
        ungetch(c);

    *pn = *pn / power;


    return c;
}


int main(void)
{
    int n,j;
    int array1[SIZE] = {0};
    double array2[SIZE];

    for (n = 0; n < SIZE && getint(&array1[n]) != EOF; n++);
    printf("Print array1\n");
    for (int i = 0; i < n; i++)
        printf("%d ", array1[i]);

    memset(buf, '\0', sizeof(buf));
    bufp = 0;

    printf("\nInput float number for array2\n");
    for (j = 0; j < SIZE && getfloat(&array2[j]) != EOF; j++);
    printf("Print array2\n");
    for (int i = 0; i < j; i++)
        printf("%f ", array2[i]);
}