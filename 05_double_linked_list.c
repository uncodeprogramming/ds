#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void insertAtBeg(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    if (temp == NULL)
    {
        printf("Memory Out of Bound\n");
        return;
    }
    temp->data = data;
    temp->next = start;
    start = temp;
}

void printLL(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    insertAtBeg(5);
    insertAtBeg(6);
    insertAtBeg(7);
    insertAtBeg(7);
    insertAtBeg(7);
    insertAtBeg(7);
    insertAtBeg(7);
    insertAtBeg(8);
    printLL(start);
    return 0;
}