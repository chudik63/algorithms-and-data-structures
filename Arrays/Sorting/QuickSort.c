#include <stdio.h>

void quickSort(int *arr, int start, int end)
{   
    if (end <= start)
    {
        return;
    }
    int left = start;
    int right = end;
    int pivot = arr[(left + right) / 2];
    while (left <= right)
    {
        while(arr[left] < pivot)
        {
            left++;
        }
        while(arr[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }

    quickSort(arr, start, right);
    quickSort(arr, left, end);
    
}

int main()
{
    int arr[] = {5, 0, 3, -1, 2};
    int size = sizeof(arr)/sizeof(*arr);
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}