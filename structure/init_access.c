/* Program to understand the initialization and ways to access struct members
 * Different types of methods are used to initialize and access the struct variables 
 * for the purpose of showing that it can be done.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[10];
    int roll_no;
    int marks;
}s1, s2, s3;

void displayStudentInfo(struct student* s) {
    printf("Name: %s\n", s->name);
    printf("Roll No: %d\n", (*s).roll_no);
    printf("Marks: %d\n", s->marks);
    printf("====================================\n");
}

int main() 
{
    strcpy(s1.name, "Mustafa");
    s1.roll_no = 29;
    (&s1)->marks = 78;
    
    struct student s2 = {"Linux", 18, 82};
    struct student s3 = {"Sid", 8, 69};
    struct student s4 = {"Aquib", 5, 89};
    struct student s5;

    printf("Enter Name Roll_No Marks: ");
    scanf("%s %d %d", s5.name, &(s5.roll_no), &(s5.marks));

    displayStudentInfo(&s1);
    displayStudentInfo(&s2);
    displayStudentInfo(&s3);
    displayStudentInfo(&s4);
    displayStudentInfo(&s5);
    return 0;
}

