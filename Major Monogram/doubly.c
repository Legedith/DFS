// Doubly linked list with insert and delte at start and insert at middle
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Intialize head to null
struct node *head = NULL;

void print_list()
{
    printf("\n\n-------List-------\n");
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n-------------------\n\n");
}
void insert_at_front(int a)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = head;
    temp->prev = NULL;
    if(head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
    print_list();
}

void insert_at_middle(int a)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    // case when empty list
    if (head == NULL)
    {
        head = new_node;
        new_node->data = a;
        new_node->next = NULL;
        new_node->prev = NULL;
        print_list();
        return;
    }
    // Get the size of the list
    // varaiable length
    // traverse the list while incrementing length
    // calculate middle
    // traverse to that point in list
    // insert data at that point
    // call the print fuinction to print out the list
    int length = 0;
    struct node *temp = head;
    
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    
    int middle = length/2 - 1;
    // printf("Length: %d\nMiddle: %d\n", length, middle);
    temp = head;
    for(int i = 0; i < middle; i++)
    {
        temp = temp->next;
    }
    
    printf("middle: %d\n", middle);
    
    new_node->data = a;
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;
    if(new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
    printf("Inserted %d at middle\n", a);
    print_list();

}

int delete_at_front()
{
    if (head != NULL)
    {
        int x = head->data;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        print_list();
        return x;
    }
    return -1;  
}

int delete_at_middle()
{
    // case when empty list
    if (head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }
    // Get the size of the list
    // varaiable length
    // traverse the list while incrementing length
    // calculate middle
    // traverse to that point in list
    // delete data at that point
    // call the print fuinction to print out the list
    int length = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    int middle = length/2;
    printf("Length: %d\nMiddle: %d\n", length, middle);
    temp = head;
    if (temp->next == NULL && temp->prev == NULL)
    {
        head = NULL;
    }
    for(int i = 0; i < middle; i++)
    {
        temp = temp->next;
    }
    int x = temp->data;
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Deleted %d at middle\n", x);
    print_list();
    return x;

}



void main()
{
    int choice;
    // Give user option to add or delete from list
    while (true)
    {
        printf("Enter 1 to insert at front\n");
        printf("Enter 2 to insert at middle\n");
        printf("Enter 3 to delete at front\n");
        printf("Enter 4 to print list\n");
        printf("Enter 5 to exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        printf("%d\n", choice);
        if (choice == 1)
        {
            int a;
            printf("Enter data: ");
            scanf("%d", &a);
            insert_at_front(a);
        }
        else if (choice == 2)
        {
            int a;
            printf("Enter data: ");
            scanf("%d", &a);
            insert_at_middle(a);
        }
        else if (choice == 3)
        {
            // Delete from front
            int x = delete_at_front();
            if (x == -1)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("Deleted %d\n", x);
            }
        }
        else if (choice == 4)
        {
            print_list();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    return;
}