#include <iostream>
#include <vector>
using namespace std;

vector<int> f(int arr[], int target, int start, int size, vector<int> v)
{
    if (start == size)
    {
        return v;
    }
    if (arr[start] == target)
    {
        v.push_back(start);
    }
    return f(arr, target, start + 1, size, v);
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
    vector<int> vec = f(arr, target, 0, n, vector<int>());
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}