/* Program to add elements to a linkedlist and display it's contents */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node *addAtEnd(struct Node *start, int value);
struct Node *addAtBeg(struct Node *start, int value);
struct Node *addBetween(struct Node *start, int value, int a, int b);
struct Node *addBefore(struct Node *start, int value, int a);
struct Node *addAfter(struct Node *start, int value, int a);
void display(struct Node *start);

int main()
{
    struct Node *start;
    start = NULL;
    
    start = addAtEnd(start, 10);
    display(start);

    start = addAtEnd(start, 18);
    display(start);

    start = addAtBeg(start, 890);
    display(start);

    start = addAtBeg(start, 87);
    display(start);

    start = addAtBeg(start, 0);
    display(start);

    start = addAtEnd(start, 93);
    display(start);

    start = addBetween(start, 88, 87, 890);
    display(start);

    start = addBefore(start, 69, 10);
    display(start);

    start = addBefore(start, 89, 87);
    display(start);

    start = addBefore(start, 89, 100);
    display(start);
    
    start = addAfter(start, 45, 88);
    display(start);

    return 0;
}

struct Node *addAtEnd(struct Node *start, int value)
{
    printf("[+] Adding %d\n", value);
    struct Node *p, *tmp;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = value;
    tmp->link = NULL;

    p = start;

    if (p == NULL) {
        return tmp;
    }

    while (p->link != NULL) {
        p = p->link;
    }

    p->link = tmp;

    return start;
}

struct Node *addAtBeg(struct Node *start, int value)
{
    printf("[+] Adding %d at beginning\n", value);
    struct Node *tmp;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = value;

    if (start == NULL) {
        tmp->link = NULL;
        start = tmp;
        return start;
    }

    tmp->link = start;
    start = tmp;

    return start;
}

struct Node *addBetween(struct Node *start, int value, int a, int b)
{
    printf("[+] Adding %d in between %d and %d\n", value, a, b);
    int found = 0;
    struct Node *tmp, *p;
    
    p = start;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = value;

    if (start == NULL) {
        printf("List is empty\n");
        tmp->link = start;
        start = tmp;
        return start;
    }

    while (p->link != NULL) {
        if ((p->data == a) && (p->link->data == b)) {
            found = 1;
            break;
        }
        p = p->link;
    }
    
    if (found) {
       tmp->link = p->link;
       p->link = tmp;
    }
    return start;
}

struct Node *addBefore(struct Node *start, int value, int a) 
{
    printf("[+] Adding %d before %d\n", value, a);
    int found = 0;
    struct Node *p, *tmp;
    p = start;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = value;
    
    while (p->link != NULL) {
        if (p->link->data == a) {
            found = 1; 
            break; 
        }
        p = p->link;
    }

    if (found) {
        tmp->link = p->link;
        p->link = tmp;
    }

    return start;
}

struct Node *addAfter(struct Node *start, int value, int a)
{
    printf("[+] Adding %d after %d\n", value, a);
    int found = 0;
    struct Node *tmp, *p;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = value;
    p = start;

    while (p != NULL) {
        if (p->data == a) {
            found = 1;
            break;
        }
        p = p->link;
    }

    if (found) {
        tmp->link = p->link;
        p->link = tmp;
   }
    return start;
}

void display(struct Node *start)
{
    if (start == NULL) {
        printf("List is empty\n");
    }
    struct Node *p;
    p = start;

    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p -> link;
    }
    printf("\n--------------------------------------------------\n\n");
}
