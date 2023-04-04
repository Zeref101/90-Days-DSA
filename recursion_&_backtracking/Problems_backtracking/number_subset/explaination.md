```cpp
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
```
* In the backtrack function, we add an element to the subset vector by calling subset push_back(nums[i]) . This adds the i th element of the nums vector to the subset vector.

* After we have explored all possible subsets that include the  i -th element, we want to remove it from the  subset  vector and try the next element. We do this by calling  subset.pop_back() , which removes the last element from the  subset  vector.

* By removing the last element from the  subset  vector, we are effectively undoing the previous choice and trying the next choice. This allows us to explore all possible subsets of the input array.

* For example, suppose we have an input array  nums = [1, 2, 3] . When we first call the  backtrack  function, the  subset  vector is empty. We then add the first element of  nums  to the  subset  vector by calling  subset.push_back(nums[i]) , where  i = 0 . This gives us  subset = [1] .

* We then recursively call the  backtrack  function with the updated  subset  vector and the next index to consider, which is  i + 1 = 1 . This generates all possible subsets that include the first element of  nums .

* After we have explored all possible subsets that include the second element of  nums , we want to remove it from the  subset  vector and try the next element. We do this by calling  subset.pop_back() , which removes the last element from the  subset  vector. This gives us  subset = [] .
*  We then add the third element of  nums  to the  subset  vector by calling  subset.push_back(nums[i]) , where  i = 2 . This gives us  subset = [3] .
*  We then recursively call the  backtrack  function with the updated  subset  vector and the next index to consider, which is  i + 1 = 3 . This generates all possible subsets that include the third element of  nums . 
* After we have explored all possible subsets that include the third element of  nums , we want to remove it from the  subset  vector and try the next element. We do this by calling  subset.pop_back() , which removes the last element from the  subset  vector. This gives us  subset = [] . 
 
At this point, we have explored all possible subsets of the input array, so we return the result vector containing all possible subsets.