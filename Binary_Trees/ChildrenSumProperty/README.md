# QUESTION
Given a binary tree, the task is to check for every node, its value is equal to the sum of values of its immediate left and right child. For NULL values, consider the value to be 0.

## EXPLAINATION

```cpp
void changeTree(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    int child = 0;
    if (root->left!= NULL) {
        child += root->left->data;
    }
    if (root->right!= NULL) {
        child += root->right->data;
    }
    if (child >= root->data) {
        root->data = child;
    } else {
        root->left->data = root->data;
        root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int returnChild = 0;
    if (root->left!= NULL) {
        returnChild += root->left->data;
    }
    if (root->right!= NULL) {
        returnChild += root->right->data;
    }
    if (!(root->left == NULL && root->right == NULL)) {
        root->data = returnChild;
    }
}
```
