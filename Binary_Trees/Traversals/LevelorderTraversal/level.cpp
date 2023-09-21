#include <iostream>
#include<queue>
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

void LevelorderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!(q.empty()))
    {
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL)
        {
            cout<<endl;
            if(!(q.empty()))
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}

int main()
{
    node *root = NULL;

    // * 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1

    root = createTree(root);

    LevelorderTraversal(root);
    //? 1 
    //? 2 5 
    //? 3 4 6 7 
    return 0;
}