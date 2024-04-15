/* Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use
a Switch. Write a function for the other direction as well,converting the escape
sequences into the real characters */

#include <stdio.h>
#define MAXLENGTH 500

void getLine(char userInput[], int maxLength);
void escape(char s[], char t[]);

int main(void) {
    char inputString[MAXLENGTH], changeString[MAXLENGTH];

    getLine(inputString, MAXLENGTH);

    escape(changeString, inputString);

    printf("%s", changeString);

    return 0;
}

void getLine(char userInput[], int maxLength) {
    int c, i;
    printf("Input User lines\n");
    for (i = 0; i < maxLength-1 && (c = getchar()) != EOF; i++) {
        userInput[i] = c;
    }
    userInput[i] = '\0';
}


void escape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        switch(t[i]) {
            case '\t':
                s[j] = '\\';
                j++;
                s[j] = 't';
                break;
            case '\n':
                s[j] = '\\';
                j++;
                s[j] = 'n';
                break;
            default:
                s[j] = t[i];
                break;
        }
        j++;
        i++;
    }
    s[j] = '\0';
}
