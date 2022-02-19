/* Program to understand working with array of struct pointers */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLASS_STRENGTH 5

struct student {
    char name[20];
    int roll_no;
    int marks;
};

void displayStudentInfo(struct student *s)
{
    printf("Name: %s\n", s->name);
    printf("Roll No: %d\n", s->roll_no);
    printf("Marks: %d\n", s->marks);
    printf("===================================\n");
}

int main()
{
    int i = 0;
    struct student *students[CLASS_STRENGTH];

    while (i < CLASS_STRENGTH) {
        students[i] = (struct student *) malloc(sizeof(struct student));
        printf("Enter Name Roll_No Marks: ");
        scanf("%s %d %d", 
                students[i]->name, 
                &(students[i]->roll_no), 
                &(students[i]->marks)
             );
        ++i;
    }

    for (i = 0; i < CLASS_STRENGTH; ++i) {
        displayStudentInfo(students[i]);
    }

    return 0;
}
