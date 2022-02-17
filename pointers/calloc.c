/* Program to understand the use of calloc function */

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *p, n, i;
    
    // n of intergers users want
    printf("Enter the number of intergers you want: ");
    scanf("%d", &n);

    // using calloc
    p = (int *)calloc(n, sizeof(int));

    // get values from user
    for (i = 0; i < n; ++i) {
        printf("Enter a number: ");
        scanf("%d", (p + i));
    }

    // print the values taken from user
    for (i = 0; i < n; ++i) {
        printf("You entered: ");
        printf("%d\n", *(p + i));
    }
    
    free(p);

    return 0;
}
