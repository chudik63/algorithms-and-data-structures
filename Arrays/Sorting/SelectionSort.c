#include <stdio.h>

void selectionSort(int *arr, int size, int start)
{   
    if (start == size - 1)
    {
        return;
    }

    int min = start;
    for (int i = start; i < size; i++)
    {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }

    if (min != start) 
    {
        int t = arr[start];
        arr[start] = arr[min];
        arr[min] = t;
    }
    start++;
    selectionSort(arr, size, start);
}

int main() 
{
    int arr[] = {5, 0, 3, -1, 2};
    int size = sizeof(arr)/sizeof(*arr);
    selectionSort(arr, size, 0);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}