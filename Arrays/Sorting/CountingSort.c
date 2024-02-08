#include <stdio.h>
#include <malloc.h>

int countingSort(int *arr, int size)
{   
    int max = arr[0];
    int sortedarray[size];
    for(int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int* count = (int* )malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < size; i++)
    {
        int place = count[arr[i]];
        count[arr[i]]--;
        sortedarray[place-1] = arr[i];
    }
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = sortedarray[i];
    }

    free(count); 
}

int main()
{
    int arr[] = {5, 0, 3, 9, 2};
    int size = sizeof(arr)/sizeof(*arr);
    countingSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}