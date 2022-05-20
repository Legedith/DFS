#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int queue[100];
int size;
int head = -1;
int tail = -1;

bool isEmpty()
{
    if (head == -1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    // if the next of tail is head after wrapping for size, then it is full
    if ((tail + 1) % size == head)
    {
        return true;
    }
    return false;
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }
    if (head == -1)
    {
        head = 0;
    }
    tail = (tail + 1) % size;
    queue[tail] = x;
}
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    int x = queue[head];
    head = (head + 1) % size;
    if ((tail+1) % size == head)
    {
        head = -1;
        tail = -1;
    }
    return x;
}

void main()
{
    // Get size from user
    printf("Enter size: ");
    scanf("%d", &size);
    while (true)
    {
        // Get operation from user
        printf("Enter operation: ");
        int operation;
        printf("\n\n\n1. Enqueue\n2. Dequeue\n3. Exit\n\n");
        scanf("%d", &operation);
        if (operation == 1)
        {
            // Get element from user
            printf("Enter element: ");
            int element;
            scanf("%d", &element);
            enqueue(element);
        }
        else if(operation == 2)
        {
            // remove element and show to user
            int removed = dequeue();
            if (removed != -1)
            {
                printf("Just removeed %d \n", removed);
            }
        }
        else if(operation == 3)
        {
            return;
        }
        else{
            printf("Please select a real input");
        }
    }


}