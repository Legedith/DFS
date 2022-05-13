// implement bubble sort in C
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11, 1, 3 ,78, 324 ,23, 233};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
    
}