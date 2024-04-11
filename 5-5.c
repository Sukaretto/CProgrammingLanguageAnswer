/*
* Write versions of the library functions strncpy, strncat, and
* strncmp, which operate on at most the first n characters of their argument
* strings
*/

#include <stdio.h>

void mystrncpy(char *, char *, int);
void mystrncat(char *, char *, int);
int mystrncmp(char *, char *, int);


int main(void)
{
    char cpyto[100];
    char cpyfrom[100] = "abcdefg";
    char catto[100] = "123456";
    char catfrom[100] = "abcdefg";    
    char cmp1[100] = "abcea";
    char cmp2[100] = "abcdefg";
    
    mystrncpy(cpyto, cpyfrom, 4);
    printf("Mystrncpy(to, from, 4) return %s\n", cpyto);

    mystrncat(catto, catfrom, 3);
    printf("Mystrncat(to, from, 3) return %s\n", catto);
    
    printf("Mystrncmp(cmp1, cmp2, 3) return %d\n", mystrncmp(cmp1, cmp2, 3));
    printf("Mystrncmp(cmp1, cmp2, 4) return %d\n", mystrncmp(cmp1, cmp2, 4));
    printf("Mystrncmp(cmp1, cmp2, 5) return %d\n", mystrncmp(cmp1, cmp2, 5));

    return 0;
}



void mystrncpy(char *s, char *t, int n)
{
    for (; n > 0; n--)
    {
        *s++ = *t++;
    }
}


void mystrncat(char *s, char *t, int n)
{
    while(*s++); // move pointer after \0
    s--;

    for (; n > 0; n--)
    {
        *s++ = *t++;
    }

}

int mystrncmp(char *s, char *t, int n)
{

    for (; *s == *t; s++, t++, n--)
    {
        if (*s == '\0')
        {
            return 0;
        }
    }

    if (n == 0)
    {
        return 0;
    }
    return *s - *t;


}