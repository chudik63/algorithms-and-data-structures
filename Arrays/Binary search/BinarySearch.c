#include <stdio.h>

int binarySearch(int x, int *arr, int size)
{
    int l, mid, r;
    l = 0;
    r = size - 1;

    while (l <= r)
    {
        mid = (l+r) / 2; 
        if (arr[mid] > x)
        {
            r = mid - 1;
        } else if (arr[mid] < x) {
            l = mid + 1;
        } else {
            return mid;
        }
        
    }
    return -1;
}

int main() 
{
    int arr[] = {-5, 0, 1, 2, 3, 4, 5, 6, 7, 9, 12, 102, 120, 232, 421, 670};
    int size = sizeof(arr)/sizeof(*arr);
    int x = 3;
    int ind;
    ind = binarySearch(x, arr, size);
    printf("%d", ind);
}