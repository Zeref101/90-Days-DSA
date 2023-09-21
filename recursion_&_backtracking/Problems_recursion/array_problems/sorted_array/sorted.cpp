#include <iostream>
using namespace std;

bool f(int arr[], int i, int size)
{
    if (i == size - 1)
    {
        return 1;
    }
    return (arr[i] + arr[i + 1]) && f(arr, i + 1, size);
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
    int size = sizeof(arr) / sizeof(arr[0]);
    bool ques = f(arr, 0, size);
    if (ques == 1)
    {
        cout << "sorted";
    }
    else
    {
        cout << "not sorted";
    }
    return 0;
}