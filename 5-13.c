/*
    Write the program tail which prints the last n lines of its input.
    By default n is 10, but it can be changed by an optional argument so that tail -n prints the last n lines.
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#define MAXLENGTH 100
#define MAXSIZE   100
#define DEAFULT   10


int mGetline(char **);


int main(int argc, char *argv[])
{
    int numLineToRead = DEAFULT;
    int len, lenCounter = 0;
    char *lineStorePtr[MAXSIZE];
    char **p = &lineStorePtr[0];
    

    if (argc == 2 && (*++argv)[0] == '-')
        numLineToRead = atoi(++*argv);
    else
    {
        printf("Usage: tail -n");
        exit(1);
    }

    if (numLineToRead < 1)
    {
        printf("Number of lines to print can't less than 1\n");
        exit(1);
    }
    
    while ((len = mGetline(p++)) > 0)
    {
        if (p > &lineStorePtr[MAXSIZE])
        {
            printf("Number of lines execeed Maximum\n");
            break;
        }
        lenCounter++;
        
    }

    printf("Finish user input\n");

    while(lenCounter > 0 && numLineToRead > 0)
    {
        printf("User input from tail is %s\n", lineStorePtr[lenCounter-1]);
        lenCounter--;
        numLineToRead--;
    }
    


    return 0;
}

int mGetline(char **s)
{
    int c, i = 0;
    char *tmpLine = malloc(sizeof(char));
    
    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        // re-allocate memory block everytime when new character coming
        if ((tmpLine = realloc(tmpLine, (i + 3)*sizeof(char))) == NULL)
        {
            printf("mGetline cannot allocate more memory\n");
            exit(1);
        }
        *(tmpLine + i) = (char) c;
    }
    
    if (i)
    {
        if (c == '\n') 
        {
            i++;
            *(tmpLine + i) = (char) c;
        }
        i++;
        *(tmpLine + i) = '\0';
        *s = tmpLine;
    }

    return i;
}