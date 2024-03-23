/* expand: expand short hand notation in s1 into string s2. */

#include <stdio.h>
#define MAXLENGTH 100

void getLine(char userInput[], int maxLength);
void expand(char s[], char t[]);

int main(void) {
    char inputString[MAXLENGTH], changeString[MAXLENGTH];

    getLine(inputString, MAXLENGTH);

    expand(inputString,changeString);

    printf("%s", changeString);

    return 0;
}

void getLine(char userInput[], int maxLength) {
    int c, i;
    printf("Input User lines.\n");
    for (i = 0; i < maxLength-1 && (c = getchar()) != EOF; i++) {
        userInput[i] = c;
    }
    userInput[i] = '\0';
}

void expand(char s[], char t[]) {
    int i,j,current;

    i = j = 0;
    int expandIndicator = 0;

    while ((current = s[i]) != '\0' && s[i+1] != '\0') {
        if (s[i+1] == '-' && s[i+2] > current) {
            int tmp = s[i+2];
            while (tmp >= current) {
                t[j++] = current++;
            }
            expandIndicator = 2;
        }
        else if (expandIndicator > 0) {
            expandIndicator--;
        }
        else {
            t[j++] = current;
        }
        i++;
    }

    t[j] = '\0';
}