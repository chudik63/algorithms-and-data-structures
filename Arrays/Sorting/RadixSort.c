#include <stdio.h>
#include <malloc.h>

int getMax(int* arr, int size)
{
    int max = arr[0];
    for(int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int countingSort(int *arr, int size, int key)
{   
    int max = getMax(arr, size);
    int sortedarray[size];
    int* count = (int* )malloc((max + 1) * sizeof(int));

    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    
    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / key) % 10]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < size; i++)
    {
        int place = count[(arr[i] / key) % 10];
        sortedarray[place-1] = arr[i];
        count[(arr[i] / key) % 10]--;
    }
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = sortedarray[i];
    }

    free(count); 
}

void radixSort(int *arr, int size)
{
    int max = getMax(arr, size);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, size, exp);
    }
}



int main()
{
    int arr[] = {5, 0, 3, 9, 2};
    int size = sizeof(arr)/sizeof(*arr);
    radixSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}