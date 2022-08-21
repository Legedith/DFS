// Implement a stack using linked lists.

// Using the implemented stack write program to convert an infix expression to postfix expression.

// Input/Output Specification:
// -Input expression will consists of single letter variables and integer constants
// -Only binary operators +, -, *, / and % will be allowed
// -brackets () can be used in the infix expression
// -Operator precedence is same as the C language
// -You can assume that infix expression is a valid infix expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node* next;
};
// Create stack using linked list
struct node* createStack()
{
    struct node* top = NULL;
    return top;
}
// Check if stack is empty
int isEmpty(struct node* top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// Push an element to stack
void push(struct node** top, char data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}
// Pop an element from stack
char pop(struct node** top)
{
    if(isEmpty(*top))
    {
        return -1;
    }
    else
    {
        struct node* temp = *top;
        *top = (*top)->next;
        char popped = temp->data;
        free(temp);
        return popped;
    }
}
// Peek the top element of stack
char peek(struct node* top)
{
    if(isEmpty(top))
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}
// Return the precedence of an operator
int precedence(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    else if(ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
// Convert infix to postfix
char* infixToPostfix(char* infix)
{
    struct node* stack = createStack();
    int i = 0;
    int j = 0;
    char* postfix = (char*)malloc(sizeof(char) * 100);
    while(infix[i] != '\0')
    {
        if(infix[i] == '(')
        {
            push(&stack, infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[j] = pop(&stack);
                j++;
            }
            if(!isEmpty(stack) && peek(stack) != '(')
            {
                return "Invalid Expression";
            }
            else
            {
                pop(&stack);
            }
        }
        else if(infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= '0' && infix[i] <= '9')
        {
            postfix[j] = infix[i];
            j++;
        }
        else
        {
            while(!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
            {
                postfix[j] = pop(&stack);
                j++;
            }
            push(&stack, infix[i]);
        }
        i++;
    }
    while(!isEmpty(stack))
    {
        postfix[j] = pop(&stack);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    // Input:
    // a + b * c + (d * e + f) * 10
    // Output:
    // abc*+de*f+10*+
    // Input string with spaces
    char infix[100];
    printf("Enter infix expression: ");
    gets(infix);
    
    printf("Postfix expression is %s", infixToPostfix(infix));
    return 0;
}
