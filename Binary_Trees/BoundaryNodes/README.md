# QUESTION

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

* Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree.
* Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
* Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

```cpp
class Solution {
public:
    void traverseLeft(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        ans.push_back(root->data);
        if (root->left) {
            traverseLeft(root->left, ans);
        } else {
            traverseLeft(root->right, ans);
        }
    }

    void traverseLeafNodes(Node* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
        }
        traverseLeafNodes(root->left, ans);
        traverseLeafNodes(root->right, ans);
    }

    void traverseRight(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        if (root->right) {
            traverseRight(root->right, ans);
        } else {
            traverseRight(root->left, ans);
        }
        ans.push_back(root->data);
    }

    vector<int> boundary(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        ans.push_back(root->data);
        // left nodes
        traverseLeft(root->left, ans);
        // leaf nodes
        // left leaf nodes
        traverseLeafNodes(root->left, ans);
        // right leaf nodes
        traverseLeafNodes(root->right, ans);
        // right nodes
        traverseRight(root->right, ans);
        return ans;
    }
};
```
