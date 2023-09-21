#include <iostream>
#include <string>
#include <vector>

using namespace std;

void subsequents(string str, vector<string> &arr)
{
    if (str.length() == 0)
    {
        arr.push_back("");
        return;
    }
    subsequents(str.substr(1), arr);
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        arr.push_back(str[0] + arr[i]);
    }
}

int main()
{
    string str = "abc";
    vector<string> arr;
    subsequents(str, arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}