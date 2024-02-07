#include <stdio.h>

void insertionSort(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    { 
        int j = i - 1;
        int t = arr[i];
        while(j >= 0 && t < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = t; 
    }
}

int main() {
    int arr[] = {5, 0, 3, -1, 2};
    int size = sizeof(arr)/sizeof(*arr);
    insertionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}