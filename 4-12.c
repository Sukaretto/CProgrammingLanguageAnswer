/*
    ecursive version of itoa that convert an integer into string
*/

#include <stdio.h>

void itoaRecursive(int, char[], int count);

int main(void)
{

    int x = 232171;
    int y = -23214;
    char xStr[100] = {'\0'};
    char yStr[100] = {'\0'};
    
    itoaRecursive(x, xStr, 5);
    itoaRecursive(y, yStr, 5);
    printf("Input is %d, itoa is %s\n", x, xStr);
    printf("Input is %d, itoa is %s\n", y, yStr);


    return 0;
}

void itoaRecursive(int x, char str[], int count)
{

    if (x < 0)
    {
        str[0] = '-';
        x = -x;
    }
    
    str[count] = x % 10 + '0';
    
    if (x / 10)
    {
        count--;
        printf("COUNT IS %d\n",count);
        itoaRecursive(x / 10, str, count);
    }

}
