#include <stdio.h>

void quickSort(int *arr, int first, int last)
{   
    if (last <= first)
    {
        return;
    }
    int left = first;
    int right = last;
    int middle = arr[(left + right) / 2];
    do
    {
        while(arr[left] < middle)
        {
            left++;
        }
        while(arr[right] > middle)
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
    } while(left < right);

    quickSort(arr, first, right);
    quickSort(arr, left, last);
    
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