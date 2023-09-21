#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<int>> &ans, vector<int> &subset, vector<int> &arr, int index)
{
    ans.push_back(subset);
    for (int i = index; i < arr.size(); i++)
    {
        subset.push_back(arr[i]);
        backtrack(ans, subset, arr, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> subset(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> subset;
    backtrack(ans, subset, arr, 0);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> res = subset(arr);
    for (auto subset : res)
    {
        for (auto num : subset)
        {
            cout << num;
        }
        cout << endl;
    }
    return 0;
}