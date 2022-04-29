// Implement stack using arrays
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int size;
int top;
int stack[100];

int isFull()
{
    return (top == size - 1);
}
int isEmpty()
{
    return (top == -1);
}

// Push an element into the stack
void push(int element)
{
    // printf("Inside push()\n");
    if(!isFull())
    { 
        top++;
        stack[top] = element;
        // printf("\nTop: %d", top);
    }
    else
    {
        printf("Stack is full\n");
    }
}

// Pop an element from the stack
int pop()
{
    if(!isEmpty())
    {
        int element = stack[top];
        top--;
        return element;
    }
    else
    {
        printf("Stack is empty\n");
        return -1; 
    }
}



void peek()
{
    if(!isEmpty())
    {
        printf("Top element is %d\n", stack[top]);
    }
    else
    {
        printf("Stack is empty\n");
    }
}

void init()
{
    // Get the size of the stack
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    
    // Initialize the top of the stack
    top = -1;
}
void choose()
{
    int element;
    int choice;
    while (true)
    {
        // Print array top and stack
        // printf("\nTop of the stack is %d\n", top);
        printf("\nStack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
        // Get the choice from the user
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                // Get the element to be pushed
                printf("Enter the element to be pushed: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                int popped = pop();
                if(popped != -1)
                {
                    printf("Popped element is %d\n", popped);
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                return;
            default:
                printf("Wrong choice\n");
        }

    }
}
