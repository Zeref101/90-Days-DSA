# QUESTION

Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.
Input:
N = 8
value[] = {1, 2, 3, 4, 5, 6, 7, 8}
k = 4
Output: 5 6 7 8 1 2 3 4

## EXPLAINATION

* change the next pointer of kth node to NULL, the next pointer of the last node should point to the previous head node, and finally, change the head to (k+1)th node. So we need to get hold of three nodes: kth node, (k+1)th node, and last node.
Traverse the list from the beginning and stop at kth node. store k’s next in a tem pointer and point k’s next to NULL then start traversing from tem and keep traversing till the end and point end node’s next to start node and make tem as the new head.

```cpp
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* tail = head;
        while(!(tail->next == NULL))
        {
            tail = tail->next;
        }
        Node* temp = head;
        while(k>1)
        {
            temp = temp->next;
            k--;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
```
