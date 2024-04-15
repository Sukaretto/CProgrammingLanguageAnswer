/*
    Modify the programs entab and detab to accept a list of tab stops as arguments.
    Use default tab settings if there are no arguments

    Extend entab and detab to accept shothand entab -m +n
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000    /* maximum line size */
#define TABSIZE  4    /* default increment size */


int tabSize = TABSIZE;
int useSizeList = 0;
int tabSizeList[MAXLINE] = {[0 ... 999] = TABSIZE};
int fromColumn = 0;

void addCharacter(char c, char *targetToAdd, char *pLimit);
void entab(char *origin, char *result);
void detab(char *origin, char *result);

int main(int argc, char *argv[])
{
    
    char test1[MAXLINE] = "abcd\t1234\tabcde\t123";
    char test1Result[MAXLINE];

    char test2[MAXLINE] = "abcd     abcd            abcde  abc";
    char test2Result[MAXLINE];

    /* default tab stops */
    if (argc <= 1)          
    {
        tabSize = TABSIZE;
    }
    /* user provide -m +n type of tab stops range */
    else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+')
    {
        tabSize = atoi(++argv[2]);
        fromColumn = atoi(++argv[1]);
    }
    /* user provided list of tab stops */
    else
    {
        useSizeList = 1;
        int *p = &tabSizeList[0];
        while (--argc > 0) /* walk through argument list */
        {
            int size = atoi(*++argv);
            if (size <= 0)
            {
                printf("Error: Invalid tab size\n.");
                exit(1);
            }
            *p++ = size;
        }
        tabSize = tabSizeList[0];
    }
    
    detab(test1, test1Result);
    printf("Before detab:%s\nAfter  detab:%s\n",test1, test1Result);

    entab(test2, test2Result);
    printf("Before detab:%s\nAfter  detab:%s\n",test2, test2Result);


    return 0;
}


void entab(char *origin, char *result)
{
    int charCount = 0, countSpaces = 0;
    int *pTab = &tabSizeList[0];
    int accumulatePTab = *pTab;
    char *pLimit = &result[MAXLINE];
    char c;

    while (c = *origin++)
    {
        charCount++;
        if(useSizeList)
        {
            if (charCount > accumulatePTab)
            {
                int tmp = *++pTab;
                tabSize = tmp;
                accumulatePTab += tmp;
            }
        }

        if (c == ' ' && charCount >= fromColumn)
        {
            countSpaces++;
            if (countSpaces >= tabSize)
            {
                // When meet enough space, immediately put a \t
                addCharacter('#', result++, pLimit); // Use # indicate \t for easy check
                // Reset countSpace because we meet enough space to be replaced by Tab
                countSpaces = 0;
            }
        }
        else
        {
            if (countSpaces)
            {
                for (; countSpaces > 0; countSpaces--, result++)
                {
                    addCharacter(' ', result, pLimit);
                }
            }
            countSpaces = 0; // Reset countSpace since we do not meet enough space to be replaced.
            addCharacter(c, result++, pLimit);
        }
    }
    *result = '\0';
}


void detab(char *origin, char *result)
{
    int count = 0, numberSpace = 0;
    int *pTab = &tabSizeList[0];
    int accumulatePTab = *pTab;
    char *pLimit = &result[MAXLINE];
    char c;
   
    while (c = *origin++)
    {
        count++;
        if(useSizeList)
        {
            if (count > accumulatePTab)
            {
                int tmp = *++pTab;
                tabSize = tmp;
                accumulatePTab += tmp;
            }
        }

        if (c == '\t' && count >= fromColumn)
        {
            numberSpace = tabSize - ((count - 1) % tabSize); // count - 1 because /t also replace by space
            count = (numberSpace > 0) ? count-1 : count; // count need -1 if we actually replace \t with space
            while (numberSpace > 0)
            {
                addCharacter('#', result, pLimit); // Use # replace space for easy check 
                result++; 
                numberSpace--;
                count++;
            }
        }
        else
        {
            addCharacter(c, result++, pLimit);
        }

    }
    *result = '\0';
}



void addCharacter(char c, char *targetToAdd, char *pLimit)
{

    if (targetToAdd < pLimit)
    {
        *targetToAdd = c;
    }
    else
    {
        printf("Error! String over size limit when Copy/Add character %c\n", c);
    }
}