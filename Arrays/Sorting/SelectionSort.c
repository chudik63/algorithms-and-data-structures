#include <stdio.h>

void selectionSort(int *arr, int size)
{   
    int min;
    for (int start = 0; start < size - 1; start++)
    {   
        min = start;
        for (int i = start + 1; i < size; i++)
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
    }
    

}

int main() 
{
    int arr[] = {5, 0, 3, -1, 2};
    int size = sizeof(arr)/sizeof(*arr);
    selectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}