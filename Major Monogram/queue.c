// simple non wrapping queue
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void main()
{
    int n;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    int queue[n];
    int front = -1;
    int rear = -1;
    while (true)
    {
        int choice;
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (rear == n - 1)
            {
                printf("Queue is full\n");
            }
            else
            {
                int item;
                printf("Enter number: ");
                scanf("%d", &item);
                rear++;
                queue[rear] = item;
            }
            break;
        case 2:
            if (front == rear)
            {
                printf("Queue is empty\n");
            }
            else
            {
                front++;
                printf("Dequeued  %d\n", queue[front]);
            }
            break;
        case 3:
            if (front == rear)
            {
                printf("Queue is empty\n");
            }
            else
            {
                int temp = front;
                temp++;
                printf("On the front we have %d\n", queue[temp]);
            }

            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}