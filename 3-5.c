/* function itob(n,s,b), that converts the integer n into a base b character
  representation in the string s.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

void itob(int n, char s[],int baseType);
void reverse(char s[]);

int main(void) {

    int number;
    char str[MAXLINE];
    char str2[MAXLINE];

    number = 123456;

    itoa(number, str, 16);
    printf("%s\n", str);

    itoa(number, str2, 8);
    printf("%s\n", str2);

    return 0;
}

void itob(int n, char s[],int baseType) {

    int i = 0;
    char baseSymbol[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (baseType < 2 || baseType > strlen(baseSymbol))
    {
        printf("Error base.");
        return;
    }
    

   do {
        s[i++] = baseSymbol[abs(n % baseType)];   /* get next symbols */
    } while (n /= baseType);  

    if (n < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}