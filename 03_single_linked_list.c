#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insertAtBeg(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = data;
    temp->next = start;
    start = temp;
}

void insertAtend(int data)
{
    struct node *temp, *ptr;
    ptr = start;
    temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = data;
    temp->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insertAtPos(int data, int pos)
{
    struct node *temp, *ptr;
    ptr = start;
    temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = data;
    if (pos == 0)
    {
        temp->next = start;
        start = temp;
        return;
    }
    int j = 0;
    while (j != pos - 1)
    {
        ptr = ptr->next;
        j++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteBeg()
{
    start = start->next;
}

void deleteEnd()
{
    struct node *temp;
    temp = start;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

void printLL(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
}

void deletePos(int pos)
{
    struct node *temp;
    temp = start;
    if (pos == 0)
    {
        start = start->next;
        return;
    }
    int j = 0;
    while (j != pos - 1)
    {
        temp = temp->next;
        j++;
    }
    temp->next = temp->next->next;
}

void printNext(struct node *head)
{
    struct node *ptr = head;
    while (ptr == NULL)
    {
        printf("%d->", *(ptr->next));
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    insertAtBeg(30);
    insertAtBeg(40);
    insertAtend(50);
    insertAtPos(60, 1);
    insertAtPos(70, 0);
    printLL(start);
    deleteBeg();
    deleteEnd();
    printLL(start);
    deletePos(1);
    deletePos(1);
    printLL(start);
    //printNext(start);
}