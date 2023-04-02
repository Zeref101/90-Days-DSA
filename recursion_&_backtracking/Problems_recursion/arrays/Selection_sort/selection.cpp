// ? .Selection sort works by repeatedly finding the minimum element from the unsorted part of the array and swapping it with the first element of the unsorted part.

#include <iostream>
using namespace std;
void f(int *arr, int size, int i)
{
    if (i == size - 1)
    {
        return;
    }
    for (int j = i + 1; j < size; j++)
    {
        if (arr[j] < arr[i])
        {
            swap(arr[i], arr[j]);
        }
    }
    f(arr, size, i + 1);
}
int main()
{
    int arr[] = {7, 2, 3, 0, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    f(arr, size, 0);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}