#include <iostream>
using namespace std;

int f(int arr[], int mid, int start, int end)
{
    mid = (start + end) / 2;
    if (start == mid)
    {
        return arr[mid];
    }
    end = mid - 1;
    return f(arr, mid, start, end);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int start = 0;
    int end = 6;
    int mid = (start + end) / 2;
    cout << f(arr, mid, start, end);
    return 0;
}