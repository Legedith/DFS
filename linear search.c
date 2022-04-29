// Implement linear search using arrays
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *array, int size, int element)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(array[i] == element)
        {
            return i;
        }
    }
    return -1;
}
void main()
{
    int array[100];
    int size, element, index;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &element);
    index = linearSearch(array, size, element);
    if(index == -1)
    {
        printf("Element not found.\n");
    }
    else
    {
        printf("Element found at index %d.\n", index);
    }
}