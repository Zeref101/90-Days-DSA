#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(const vector<int> &nums, vector<int> &subset, vector<vector<int>> &subsets, int index)
{
    if (index == nums.size())
    {
        subsets.push_back(subset);
        return;
    }
    // Exclude current element
    generateSubsets(nums, subset, subsets, index + 1);
    // Include current element
    subset.push_back(nums[index]);
    generateSubsets(nums, subset, subsets, index + 1);
    subset.pop_back();
}

vector<vector<int>> subsets(const vector<int> &nums)
{
    vector<vector<int>> subsets;
    vector<int> subset;
    generateSubsets(nums, subset, subsets, 0);
    return subsets;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = subsets(nums);
    for (const auto &subset : subsets)
    {
        for (const auto &num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}