# QUESTION

Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

## EXPLAINATION

```cpp
class Solution
{
    public:
    pair<bool, int> check(Node* root)
    {
        if(root == NULL)
        {
            return {true,0};
        }
        if(root->left == NULL && root->right == NULL)
        {
            return {true, root->data};
        }
        
        pair<bool,int> left = check(root->left);
        pair<bool,int> right = check(root->right);
        
        bool condition = root->data == left.second+right.second;
        
        pair<bool, int> ans;

        if(left.first && right.first && condition)
        {
            ans.first = true;
            ans.second = root->data+left.second+right.second;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
         return check(root).first;
    }
};
```
