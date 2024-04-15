/* Binsearch function, by writing minimum tests inside the loop */

#include <stdio.h>
#include <stdlib.h>

int binsearch(int searchNumber, int v[], int n);

int main(void) {
    
    int arraySize = 0;

    int* ptr;
    
    printf("Input size of array\n");
    scanf("%d",&arraySize);

    ptr = (int*) malloc(arraySize * sizeof(int));

    if (ptr == NULL) {
        printf("Error, not allocate memory");
    }
    else {
        printf("Memory allocate success\n");
        for (int i = 0; i < arraySize; i++) {
            printf("Input array number, number must is ascending order\n");
            scanf("%d",&ptr[i]);
        }
        printf("You found number 5 on position %d", binsearch(5,ptr,arraySize-1));
    }

    return 0;
}

int binsearch(int searchNumber, int v[], int n) {
    
    int low, high, mid;
    low = 0;
    high = n-1;
    mid = (low+high)/2;

    while ( low < high && searchNumber != v[mid])
    {
        if (searchNumber < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low+high)/2;
    }

    if (searchNumber == v[mid])
    {
        return mid;
    }
    return -1;
}