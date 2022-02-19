/* Program to understand nested structs */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[20];
    int roll_no;

    struct date {
        int day;
        int month;
        int year;
    }birthday;
};

void printBirthDate(struct student *stu) 
{
    printf("%s was born on %d/%d/%d\n", 
            stu->name,
            stu->birthday.day,
            stu->birthday.month,
            stu->birthday.year
            );
}

int main()
{
    struct student stu;
    strcpy(stu.name,"Aquib");
    stu.roll_no = 5;
    stu.birthday.day = 1;
    stu.birthday.month = 6;
    stu.birthday.year = 2000;

    printBirthDate(&stu);

    return 0;
}

