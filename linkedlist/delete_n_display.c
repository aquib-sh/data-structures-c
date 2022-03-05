/* Program to show deletion of elements in a linkedlist */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node *addAtEnd(struct Node *start, int value);
struct Node *deleteFromList(struct Node *start, int value);
void display(struct Node *start);

int main()
{
    struct Node *start;
    start = NULL;

    start = addAtEnd(start, 10);
    start = addAtEnd(start, 18);
    start = addAtEnd(start, 19);
    start = addAtEnd(start, 67);
    start = addAtEnd(start, 17);
    start = addAtEnd(start, 49);

    display(start);

    start = deleteFromList(start, 17);
    display(start);

    start = deleteFromList(start, 19);
    display(start);

    start = deleteFromList(start, 67);
    display(start);

    return 0;
}

// Adds a node at the end of list
struct Node *addAtEnd(struct Node *start, int value)
{
    struct Node *tmp, *p;
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

// Deletes an element from list by it's value
struct Node *deleteFromList(struct Node *start, int value)
{
    struct Node *p, *tmp;
    p = start;

    // empty list
    if (p == NULL) {
        printf("[!] List is empty\n");
        return start;
    }

    // single element list
    if (p->link == NULL) {
        free(p);
        start = NULL;
        return start;
    }

    while (p->link != NULL) {
        if (p->link->data == value) {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    
    printf("[!] Unable to find the element\n");
    return start;
}

// Displays a linked list
void display(struct Node *start)
{
    struct Node *p;
    p = start;

    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("\n");
}
