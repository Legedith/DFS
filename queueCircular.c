//Implement circular queue using arrays
#include <stdio.h>
#include <stdlib.h>

int head;
int tail;
int size;
int queue[100];

void enqueue(int element);
void dequeue();
int isFull();
int isEmpty();
void display();

int main()
{
	int choice, element;
	printf("Enter the size of queue: ");
	scanf("%d", &size);
	head = -1;
	tail = -1;
	while(1)
	{
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d", &element);
				enqueue(element);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid choice.\n");
				break;
		}
	}
	return 0;
}

void enqueue(int element)
{
	if(isFull())
	{
		printf("Queue is full.\n");
		return;
	}
	tail = (tail + 1) % size;
	queue[tail] = element;
    printf("Tail is %d\n", tail);
}

void dequeue()
{
	if(isEmpty())
	{
		printf("Queue is empty.\n");
		return;
	}
	head = (head + 1) % size;
}

int isFull()
{
	if((tail + 1) % size == head)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if(tail == -1)
		return 1;
	else
		return 0;
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("Queue is empty.\n");
		return;
	}
	for(i = head; i != tail; i = (i + 1) % size)
		printf("%d ", queue[i]);
	printf("%d\n", queue[i]);
}
