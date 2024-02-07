#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int *arr, int size)
{
    int swapped;
    do {
        swapped = false;
        for (int i = 0; i + 1 < size; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
                swapped = true;
            }
        }
    }while(swapped);

}

int main() 
{
    int arr[] = {5, 0, 3, -1, 2};
    int size = sizeof(arr)/sizeof(*arr);
    bubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}