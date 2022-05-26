// write a program to convert infix to postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct stack
{
    int top;
    char stack[100];
};

// write the is empty function
int isEmpty(struct stack s)
{
    if(s.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/')
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



char* infixToPostfix(char* infix)
{
    struct stack s;
    s.top = -1;
    int i = 0;
    int j = 0;
    char* postfix = (char*)malloc(sizeof(char) * 100);
    while(infix[i] != '\0')
    {
        if(infix[i] == '(')
        {
            s.top++;
            s.stack[s.top] = infix[i];
        }
        else if(infix[i] == ')')
        {
            while(s.stack[s.top] != '(')
            {
                postfix[j] = s.stack[s.top];
                j++;
                s.top--;
            }
            s.top--;
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while(!isEmpty(s) && precedence(s.stack[s.top]) >= precedence(infix[i]))
            {
                postfix[j] = s.stack[s.top];
                j++;
                s.top--;
            }
            s.top++;
            s.stack[s.top] = infix[i];
        }
        else
        {
            postfix[j] = infix[i];
            j++;
        }
        i++;
    }
    while(!isEmpty(s))
    {
        postfix[j] = s.stack[s.top];
        j++;
        s.top--;
    }
    postfix[j] = '\0';
    return postfix;
}


void main()
{
    char* infix = (char*)malloc(sizeof(char) * 100);
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    char* postfix = infixToPostfix(infix);
    printf("Postfix expression: %s", postfix);
}

