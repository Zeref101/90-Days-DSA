```cpp

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> res;
     queue<Node*> q;
     bool LeftToRight = true;
     q.push(root);
     
     while(!q.empty())
     {
         int size = q.size();
         vector<int> ans(size);
         
         for(int i=0; i<size;i++)
         {
             Node* temp = q.front();
             q.pop();
             
             int index = LeftToRight?i:size-i-1;
             ans[index] = temp->data;
             
             if(temp->left)
             {
                 q.push(temp->left);
             }
             if(temp->right)
             {
                 q.push(temp->right);
             }
         }
         LeftToRight = !LeftToRight;
         for(auto element:ans)
         {
             res.push_back(element);
         }
     
     }
     return res;
     
    }
};
```

## EXPLAINATION

* The function zigZagTraversal takes a pointer to the root node of the binary tree as input and returns a vector of integers representing the zigzag traversal.
* Inside the function, a vector res is declared to store the final result.
* A queue q is initialized to perform the level order traversal of the tree. The queue initially contains the root node.
* The variable LeftToRight is used to determine the traversal direction. It is set to true initially, indicating that the traversal starts from left to right.
* The main while loop runs until the queue q becomes empty, which means all the nodes in the tree have been processed.
* Inside the while loop, the size of the current level is stored in the variable size by getting the size of the queue.
* A vector ans is declared with size equal to the current level's size. This vector will store the elements of the current level in the zigzag order.
* A for loop runs from 0 to size-1 to process each node in the current level.
* Inside the for loop, the front node of the queue q is removed and stored in the variable temp.
* The variable index is calculated based on the current traversal direction (LeftToRight). If it is true, index is set to i, otherwise, it is set to size-i-1. This ensures that the elements are stored in the zigzag order.
* The value of temp->data (the data stored in the current node) is assigned to ans[index] to store it in the ans vector.
* If the left child of the current node exists, it is pushed into the queue q.
* If the right child of the current node exists, it is also pushed into the queue q.
* After processing all the nodes in the current level, the direction of traversal is reversed by updating LeftToRight to its opposite value.
* Finally, a range-based for loop is used to iterate over the elements of ans vector, and each element is appended to the res vector.
After the while loop finishes, the function returns the res vector containing the zigzag traversal of the binary tree.
