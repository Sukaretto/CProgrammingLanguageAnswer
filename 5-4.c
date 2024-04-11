/*
    strend(s,t) which returns 1 if the string t occurs at the end of the string s and zero otherwise
    This assume len(s) > len(t)
*/

#include <stdio.h>

int mystrend(char *, char *);


int main(void)
{

    char a[100] = "abcdefg";
    char b[100] = "efg";
    char c[100] = "2efg";

    printf("mystrend(a,b) result is %d\n", mystrend(a,b));
    printf("mystrend(a,c) result is %d\n", mystrend(a,c));
    return 0;
}


int mystrend(char *s, char *t)
{
    char *tmp = t; // tmp pointer record t's head location

    while(*s++);
    while(*t++);
    s--;
    t--;

    while (tmp <= t)
    {
        if ((*s--) != (*t--))
        {
            return 0;
        }
    }

    return 1;
}