#include <stdio.h>

void merge(int* arr, int left, int middle, int right)
{
    int leftcount = middle - left + 1;
    int rightcount = right - middle;

    int leftarr[leftcount];
    int rightarr[rightcount];

    for (int i = 0; i < leftcount; i++)
    {
        leftarr[i] = arr[left + i];
    }

    for (int i = 0; i < rightcount; i++)
    {
        rightarr[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < leftcount && j < rightcount) {
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        }
        else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }

    while(i < leftcount)
    {
        arr[k] = leftarr[i];
        i++;
        k++;
    }

    while(j < rightcount)
    {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int left, int right)
{   
    if (left >= right)
    {
        return;
    }
    int middle = (left + right) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    merge(arr, left, middle, right);
}

int main()
{
    int arr[] = {5, 0, 3, -1, 2};
    int size = sizeof(arr)/sizeof(*arr);
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}