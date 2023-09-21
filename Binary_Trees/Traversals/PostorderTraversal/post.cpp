#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createTree(node *root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for left of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = createTree(root->right);

    return root;
}

void postorderTraverse(node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root = NULL;
    root = createTree(root);

    postorderTraverse(root);
    return 0;
}