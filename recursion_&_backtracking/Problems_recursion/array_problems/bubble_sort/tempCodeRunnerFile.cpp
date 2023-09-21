#include <iostream>
using namespace std;

void f(int *arr[], int size)
{
    if (size == 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    f(arr, size - 1);
}

int main()
{
    int arr[] = {7, 2, 3, 0, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    f(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}