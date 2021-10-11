#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void insert(int data)
{
    if (rear == MAX - 1)
        printf("Queue Overflow.");
    else
    {
        if (front == -1)
            front++;
        queue[++rear] = data;
    }
}

int delete ()
{
    int data;
    if (front == -1 || front > rear)
        printf("Queue Underflow.");
    else
    {
        data = queue[front];
        front++;
    }
}

int main()
{
    insert(45);
    insert(10);
    insert(30);
    insert(20);
    insert(45);
    insert(55);
    delete ();
    delete ();
    delete ();
    delete ();
    delete ();
    insert(12);
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}