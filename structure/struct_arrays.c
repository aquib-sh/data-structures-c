/* Program to understand working with arrays of struct */

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
    int i;
    struct student room[CLASS_STRENGTH] = {
        {"Aquib", 5, 97},
        {"Mustafa", 19, 80},
        {"Deepak", 9, 60}
    }; 

    // using -> operator
    strcpy(room[3].name, "Sahil");
    room[3].roll_no = 6;
    room[3].marks = 70;

    // using . operator
    // . has more precedence than * so we would use () to use them.
    strcpy(room[4].name, "Saish");
    room[4].roll_no = 4;
    room[4].marks = 65;

    for (i = 0; i < CLASS_STRENGTH; ++i) {
        displayStudentInfo(&room[i]);
    }

    return 0;
}
