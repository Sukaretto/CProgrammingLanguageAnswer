/*
    Rewrite readlines to store lines in an array supplied by main rather than calling alloc to maintain storage
*/

#include <stdio.h>
#include <string.h>
#define MAXLINES 1000   /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */
#define LINESIZE 1000


char lineStorage[MAXLINES];

int getline(char *s, int lim);

int readlines(char *lineptr[], char *lineStore, int maxlines);

void writelines(char *lineptr[], int nlines);

void qsort(char *v[], int left, int right);

void swap(char *v[], int i, int j);


int main(void) {
    int nlines; /* number of input lines read */
    char *lineptr[MAXLINES];

    if ((nlines = readlines(lineptr, lineStorage, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort \n");
        return 1;
    }
}

int readlines(char *lineptr[], char *lineStore, int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    char *storageHead = lineStore;
    char *storageTail = lineStore + MAXLINES;

    nlines = 0;

    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || storageHead + len > storageTail)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(storageHead, line);
            lineptr[nlines++] = storageHead;
            storageHead += len;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getline(char *s, int lim) {
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;

    *s = '\0';

    return s - t;
}