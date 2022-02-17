/* Program to understand the use of realloc() function */

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *p, n, i;
    int prev;

    // get the n of ints from user
    printf("How many ints do you want? ");
    scanf("%d", &n);


    // get memory from heap
    p = (int *)calloc(n, sizeof(int));
    if (p == NULL) {
        printf("Memory not available\n");
        exit(1);
    }

    // get values from user
    for (i = 0; i < n; ++i) {
        printf("Enter an int: ");
        scanf("%d", (p + i));
    }

    // index of the last int assigned in heap by user
    prev = n;   

    // print values taken
    for (i = 0; i < n; ++i) {
        printf("You entered: ");
        printf("%d\n", *(p + i));
    }

    // get the new value of n of ints from user
    printf("How many ints do you want it to be? ");
    scanf("%d", &n);

    // alter the memory chunk from heap according to new n
    p = (int *) realloc(p, n*sizeof(int));
    if (p == NULL) {
        printf("Memory not available\n");
        exit(1);
    }

    // take new values
    for (i = prev; i < n; ++i) {
        printf("Enter an int: ");
        scanf("%d", (p + i));
    }

    // print the new memory chunk values
    for (i = 0; i < n; ++i) {
        printf("New chunk val: ");
        printf("%d\n", *(p + i));
    }

    free(p);

    return 0;
}
