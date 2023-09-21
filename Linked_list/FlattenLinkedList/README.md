# QUESTION

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8          50    40
|                 |
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

## EXPLAINATION

```cpp
Node* merge(Node* head1, Node* head2)
{
    Node* dummy = new Node(-1);
    Node* res = dummy;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            dummy->bottom = head1;
            head1 = head1->bottom;
        } else {
            dummy->bottom = head2;
            head2 = head2->bottom;
        }
        dummy = dummy->bottom;
    }
    if(head1) dummy->bottom = head1;
    else dummy->bottom = head2;
    
    return res->bottom;
}

Node* flatten(Node* root)
{
    if(root == NULL || root->next == NULL)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;

}
```

### merge function

* It takes two linked lists, head1 and head2, as input.
* It creates a new node called dummy with a value of -1. This node will act as a temporary placeholder.
* It creates a pointer res and sets it equal to dummy. This res pointer will keep track of the merged linked list.
* It enters a while loop that continues until either head1 or head2 becomes NULL (indicating the end of one of the linked lists).
* Inside the loop, it compares the values of the current nodes pointed to by head1 and head2.
* If the value of head1 is smaller, it adds head1 to the bottom of dummy (using the bottom pointer) and moves head1 to the next node in its linked list.
* Otherwise, if the value of head2 is smaller or equal, it adds head2 to the bottom of dummy and moves head2 to the next node in its linked list.
* After either of the above steps, it moves dummy to the next node.
* Once the while loop ends, it checks if either head1 or head2 is not NULL (meaning there are remaining nodes in one of the linked lists).
* If head1 is not NULL, it adds the remaining nodes of head1 to the bottom of dummy.
* Otherwise, if head2 is not NULL, it adds the remaining nodes of head2 to the bottom of dummy.
* Finally, it returns the merged linked list starting from res->bottom.

### flatten function

* It takes a linked list with a particular structure, root, as input.
* It first checks if root is either NULL or a single node (i.e., root->next == NULL), indicating an empty or already flattened list. In such cases, it simply returns root as it is.
* If root is not NULL and has more than one node, it calls flatten recursively on root->next to flatten the next linked list after root.
* Then, it merges the current linked list root with the flattened linked list root->next using the merge function.
* Finally, it returns the flattened and merged linked list.
