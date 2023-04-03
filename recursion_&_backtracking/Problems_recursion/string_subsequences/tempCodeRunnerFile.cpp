#include <iostream>
#include <string>
#include <vector>
using namespace std;

void subsequent(vector<string> &arr, string str)
{
    if (str.length() == 1)
    {
        arr.push_back("");
        return;
    }
    subsequent(arr, str.substr(1));
    arr.push_back(str);
    return;
}

int main()
{
    string str = "abc";
    vector<string> arr;
    subsequent(arr, str);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}