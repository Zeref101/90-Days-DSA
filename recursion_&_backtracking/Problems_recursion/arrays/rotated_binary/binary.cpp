// ? a rotated sorted array is given and we need to apply binary search

#include <iostream>
using namespace std;

int rotated_bindary_search(int arr[], int target, int start, int end, int mid)
{
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[start] < arr[mid])
    {
        if (target >= arr[start] && target <= arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    else
    {
        if (target >= arr[mid] && target <= arr[end])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return rotated_bindary_search(arr, target, start, end, (start + end) / 2);
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
    cout << "Target?\n";
    int target;
    cin >> target;
    int start = 0;
    int end = n;
    cout << rotated_bindary_search(arr, target, start, end, (start + end) / 2);
    return 0;
}