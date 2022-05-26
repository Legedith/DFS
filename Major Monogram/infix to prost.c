// Get user to enter the completed infix expression
// Write a function to replace all right brackets with their corresponding operator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// create a stack
char stack[100];
int top = -1;

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char pop()
{
    if (isEmpty())
    {
        return '\0';
    }
    else
    {
        top--;
        return stack[top + 1];
    }
}
void push(char item)
{
    top++;
    stack[top] = item;
}
void main()
{
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Print the infix expression
    printf("\nThe infix expression is: %s\n", infix);

    int i = 0;
    while (infix[i] != '\0')
    {
        // printf("here %c\n", infix[i]);

        // if it is a operand, print to console
        // if it is an operator, push to stack
        // if it is ')', pop from stach and print to console
        if (infix[i] >= 'a' && infix[i] <= 'z')
        {
            printf("%c", infix[i]);
        }
        else if (infix[i] == ')')
        {
            printf("%c", pop());
        }
        else if(infix[i] == '(')
        {
            // do nothiung
        }
        else
        {
            push(infix[i]);
        }
        i++;
    }
}