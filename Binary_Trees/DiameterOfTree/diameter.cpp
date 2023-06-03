#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* createTree(node* root)
{
    cout<<"Enter data"<<endl;

    int data;
    cin>>data;

    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter data for left of"<<data<<endl;
    root->left = createTree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = createTree(root->right);

    return root;
}

int height(node* root, int &ans)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = height(root->left, ans);
    int right = height(root->right, ans);
    ans = max(ans, left+right);

    return 1 + max(left,right);
}

int main()
{
    node* root = NULL;
    root = createTree(root);

    int ans = 0;
    int res = height(root, ans);
    cout<<ans<<endl;
    return 0;
}
