/* Program to understand self referential structures */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[20];
    struct person *son;
};

void printCompleteLineage(struct person *start)
{
    struct person *p;
    p = start;

    printf("%s ", p->name);

    while (p->son != NULL) {
        printf("-> %s ", p->son);
        p = p -> son;
    }
    printf("\n");

}

int main()
{
    struct person p1,p2,p3,p4;
    strcpy(p1.name, "Great Grand Father");
    strcpy(p2.name, "Grand Father");
    strcpy(p3.name, "Father");
    strcpy(p4.name, "Me");

    p1.son = &p2;
    p2.son = &p3;
    p3.son = &p4;
    p4.son = NULL;

    struct person *start = &p1; 
    printCompleteLineage(start);

    return 0;
}
