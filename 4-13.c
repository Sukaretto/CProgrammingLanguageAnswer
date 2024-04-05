/*
    recursive version of the function reverse(s)
*/

#include <stdio.h>
#include <string.h>

void reverse(char[], char[], int);

int main(void)
{
    char input[100] = "abcdefgh";
    char output[100];

    reverse(input, output, 7);
    printf("Input string is %s, reverse string is %s \n", input, output);
    return 0;
}

void reverse(char a[], char b[], int len)
{
    if (len >= 0)
    {

        b[strlen(a)- len -1] = a[len];
        len--;
        reverse(a, b, len);
    }
    else
    {
        b[strlen(a)] = '\0';
    }

}