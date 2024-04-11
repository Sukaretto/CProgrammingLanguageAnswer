/*
    Pointer version of function strcat that copies string t to the end of s
*/
#include <stdio.h>

void strcatCustom(char *, char *);

int main(void)
{

    char to[100] = "abcdefgh";
    char from[100] = "123456";

    strcatCustom(to,from);
    printf("String after strcat is %s\n", to);

    return 0;
}


void strcatCustom(char *s, char *t)
{
    while (*s++); // reach the end of string s
    /*
        After loop, s point to
        |a| |b| |c| |d| |e| |f| |g| |h| |\0| | |
                                             ^
                                             |
    */
    s--; // move back to point to \0
    while (*s++ = *t++);// copy each character of t to s.

}