# QUESTION

Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

## EXPLAINATION

```cpp
class Solution{
    public:
    
    int height(Node* node)
    {
        if(node == NULL)
        {
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        if(left>right)
        {
            return (left+1);
        }
        else
        {
            return (right+1);
        }
    }
    
    bool isBalanced(Node *root)
    {
        if (root == NULL) {
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
};
```
