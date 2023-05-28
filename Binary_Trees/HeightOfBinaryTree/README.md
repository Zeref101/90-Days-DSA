# QUESITON

Input:
     1
    /  \
   2    3
Output: 2

## EXPLAINATION

```cpp
class Solution{
    public:
    void fun(Node* node, int &count)
    {
        queue<Node*> q;
        q.push(node);
        q.push(NULL);
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp==NULL)
            {
                count++;
            }
            if(temp!=NULL)
            {
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            else if(!(q.empty()))
            {
                q.push(NULL);
            }
        }
    }
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node==NULL)
        {
            return 0;
        }
        int count =0;
        fun(node, count);
        return count;
    }
};
```
