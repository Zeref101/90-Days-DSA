```cpp
#include <iostream>
using namespace std;

// Node class represents a node in the linked list
class Node
{
public:
    int data; // data stored in the node
    Node *next; // pointer to the next node in the list

    // constructor to initialize the data and next pointer of the node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// insertionAtTail function inserts a new node at the end of the list
void insertionAtTail(Node *&tail, int d)
{
    // create a new node with the given value
    Node *temp = new Node(d);

    // set the next pointer of the current tail node to point to the new node
    tail->next = temp;

    // update the tail pointer to point to the new node
    tail = temp;
}

// print function prints the values of all the nodes in the list
void print(Node *&tail)
{
    // create a temporary pointer and initialize it to point to the tail of the list
    Node *temp = tail;

    // iterate through the list using a while loop
    while (temp != NULL)
    {
        // print the value of the current node
        cout << temp->data << " ";

        // update the temporary pointer to point to the next node in the list
        temp = temp->next;
    }

    // print a newline character to separate the output from other text
    cout << endl;
}

int main()
{
    // create a new node with a value of 10 and assign it to the node1 pointer
    Node *node1 = new Node(10);

    // set the tail pointer to point to node1
    Node *tail = node1;

    // insert a new node with a value of 12 at the end of the list
    insertionAtTail(tail, 12);

    // print the values of all the nodes in the list
    print(tail);

    return 0;
}
```