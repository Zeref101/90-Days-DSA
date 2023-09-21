#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = (start + end) / 2;
    int length1 = mid - start + 1;
    int length2 = end - mid;

    int *First = new int[length1];
    int *Second = new int[length2];

    int MainArrayIndex = start;
    for (int i = 0; i < length1; i++)
    {
        First[i] = arr[MainArrayIndex++];
    }

    MainArrayIndex = mid + 1;

    for (int i = 0; i < length2; i++)
    {
        Second[i] = arr[MainArrayIndex++];
    }

    // Merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    MainArrayIndex = start;

    while (index1 < length1 && index2 < length2)
    {
        if (First[index1] >= Second[index2])
        {
            arr[MainArrayIndex++] = Second[index2++];
        }
        else
        {
            arr[MainArrayIndex++] = First[index1++];
        }
    }
    while (index1 < length1)
    {
        arr[MainArrayIndex++] = First[index1++];
    }
    while (index2 < length2)
    {
        arr[MainArrayIndex++] = Second[index2++];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}
int main()
{
    int arr[] = {4, 1, 6, 8, 12, 9, 0, 32};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, start, end);
    for (int i = start; i < end; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}