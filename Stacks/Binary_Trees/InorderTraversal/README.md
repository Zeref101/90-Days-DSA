# EXPLAINATION

```cpp
#include <iostream>
using namespace std;

// Define a class for the nodes in the tree
class node
{
public:
    int data; // The data stored in the node
    node *left; // Pointer to the left child node
    node *right; // Pointer to the right child node

    // Constructor for the node class
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create the tree recursively
node *createTree(node *root)
{
    // Ask the user to enter data for the root node
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    // If the data entered is -1, return NULL
    if (data == -1)
    {
        return NULL;
    }

    // Ask the user to enter data for the left child node
    cout << "Enter data for left of " << data << endl;
    root->left = createTree(root->left);

    // Ask the user to enter data for the right child node
    cout << "Enter data for right of " << data << endl;
    root->right = createTree(root->right);

    // Return the root node
    return root;
}

// Function to print the tree in inorder traversal
void inorder(node* root)
{
    // If the root node is NULL, return
    if(root == NULL)
    {
        return;
    }

    // Recursively print the left subtree
    inorder(root->left);

    // Print the data of the current node
    cout<<root->data<<" ";

    // Recursively print the right subtree
    inorder(root->right);
}

// Main function to create the tree and print it in inorder traversal
int main()
{
    node *root = NULL;

    // Create the tree recursively
    root = createTree(root);

    // Print the tree in inorder traversal
    inorder(root);

    // Return 0 to indicate successful program execution
    return 0;
}
```
