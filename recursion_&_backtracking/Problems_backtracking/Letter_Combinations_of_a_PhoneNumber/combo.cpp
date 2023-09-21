#include <iostream>
#include <string>
#include <vector>
using namespace std;

void combination(string &digits, vector<string> &ans, string subset, int index, vector<string> mapping)
{
    if (index >= digits.length())
    {
        ans.push_back(subset);
        return;
    }
    int number = digits[index] - '0';
    string value = mapping[number];
    for (int i = 0; i < value.size(); i++)
    {
        subset.push_back(value[i]);
        combination(digits, ans, subset, index + 1, mapping);
        subset.pop_back();
    }
}
int main()
{
    string digits = "23";
    vector<string> ans;
    string subset = "";
    int index = 0;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    combination(digits, ans, subset, index, mapping);
    for (int element = 0; element < ans.size(); element++)
    {
        cout << ans[element] << " ";
    }
    return 0;
}