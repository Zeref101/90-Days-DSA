# QUESTION

![question](./Screenshot%20from%202023-06-06%2021-44-45.png)

```cpp
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        
        map<int, int> node;
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!(q.empty()))
        {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int vl = temp.second;
            
            if(node.find(vl) == node.end())
            {
                node[vl] = frontNode->data;
            }
            
            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left, vl-1));
            }
            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right, vl+1));
            }
        }
        for(auto i:node)
        {
            ans.push_back(i.second);
        }
        return ans;
        
    }

};
```
