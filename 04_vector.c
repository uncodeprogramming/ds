#include <stdio.h>
#include <stdlib.h>
int *vector, max_size = 1, currSize = 0;
void push(int data)
{
    if (currSize == 0)
        vector = (int *)malloc(max_size * sizeof(int));
    if (currSize == max_size)
    {
        int *dummyArray = vector;
        for (int i = 0; i < currSize; i++)
        {
            dummyArray[i] = vector[i];
        }
        max_size *= 2;
        vector = (int *)malloc(max_size * sizeof(int));
        for (int i = 0; i < currSize; i++)
        {
            vector[i] = dummyArray[i];
        }
        vector[currSize] = data;
        currSize++;
        free(dummyArray);
    }
    else
    {
        vector[currSize] = data;
        currSize++;
    }
}

int pop()
{
    int data = -1;
    if (currSize > 0)
    {
        data = vector[currSize--];
    }
    return data;
}

int at(int index)
{
    if (index >= 0 && index <= currSize)
    {
        return vector[index];
    }
    return -1;
}

void display()
{
    for (int i = 0; i < currSize; i++)
    {
        printf("%d ", at(i));
    }
    printf("\n");
}

int main()
{
    push(1);
    push(3);
    push(2);
    pop();
    push(1);
    push(3);
    push(2);

    display();
    printf("Curr Size: %d Max Size: %d\n", currSize, max_size);
    // for (int i = 0; i < currSize; i++)
    // {
    //     printf("%d ", at(i));
    // }
}