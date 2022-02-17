/* Program to understand dynamic allocation of memory */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, n, i;
    printf("Enter the number integers to be entered: ");
    scanf("%d", &n);

    p = (int *)malloc(n*sizeof(int));
    if (p == NULL) {
         printf("Memory not available\n");
         exit(1);
    }

    for (i = 0; i < n; ++i) {
        printf("Enter a number: ");
        scanf("%d", (p + i));
    }

    for (i = 0; i < n; ++i) {
        printf("You entered: ");
        printf("%d\n", *(p + i));
    }

    free(p);

    return 0;
}


