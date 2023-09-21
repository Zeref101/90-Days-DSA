# QUESTION

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.
![question-input-output](./Screenshot%20from%202023-06-04%2012-25-24.png)

```cpp
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int> > > node;
        queue<pair<Node*, pair<int,int> > > q;
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!(q.empty()))
        {
            pair<Node*, pair<int,int> > temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hl = temp.second.first;
            int l = temp.second.second;
            
            node[hl][l].push_back(frontNode->data);
            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left, make_pair(hl-1, l+1)));
            }
            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right, make_pair(hl+1, l+1)));
            }
        }
        for(auto i:node)
        {
            for(auto j:i.second)
            {
                for(auto k:j.second)
                {
                    {
                        ans.push_back(k);
                    }
                }
            }
        }
        return ans;
    }
};
```
