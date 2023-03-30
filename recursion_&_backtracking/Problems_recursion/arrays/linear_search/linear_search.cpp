#include <iostream>
using namespace std;

int f(int arr[], int target, int start, int size)
{
    if (start == size)
    {
        return -1;
    }
    if (arr[start] == target)
    {
        return start;
    }
    return f(arr, target, start + 1, size);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "enter target:\n";
    cin >> target;
    cout << f(arr, target, 0, n);
    return 0;
}