/* a function of itoa, which accepts the third argument as the width of the
number. the string representation is padded with blanks in the left to get the
required width */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIMIT 1000

void itob(int n, char s[], int w);
void reverse(char s[]);

int main(void) {
    int number, width;
    char str[MAXLIMIT];

    number = -21381;
    width = 15;

    itob(number, str, width);

    printf("%s", str);

    return 0;
}

void itob(int n, char s[], int w) {
    
    int i = 0, indicate = (n < 0);

    do {
        s[i++] = (abs(n % 10)) + '0';

    } while ((n /= 10) != 0);

    if (indicate) 
    {
        s[i++] = '-';

    }
    while (i < w-1)
    {
        s[i++] = ' ';
    }
        

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[]) {
    int i, j, c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}