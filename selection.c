// Implement selection sort in C
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 12, 34,45,56,67,78,89,90,100};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;

}