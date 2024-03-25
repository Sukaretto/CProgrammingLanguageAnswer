/* strindex which returns rightmost occurance */
#include <stdio.h>

#define MAXLINE 500

int strindex(char search[],char target[]);
int getline(char line[], int max);

int main(void)
{
    char line[MAXLINE];
    char pattern[MAXLINE];

    int found;

    printf("Please input line used for search\n");
    getline(line,MAXLINE);

    printf("Please input pattern used for search\n");
    getline(pattern,MAXLINE);


    found = strindex(line, pattern);

    printf("Found the right index: %d\n", found);

}



int getline(char line[], int max) {
    int c, i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }
    if (c == '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

int strindex(char search[],char target[]) {

    int i, j, k, occur = -1;

    for (i = 0; search[i]!='\0' ; i++)
    {
        for (j = i, k = 0; target[k] != '\0' && search[j] == target[k]; j++, k++)
        {
            ;
        }
        if ( k > 0 && target[k] == '\0') {
            occur = i;
        }
    }
    return occur;
}