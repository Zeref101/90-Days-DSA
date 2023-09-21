```cpp
#include<iostream>
using namespace std;

// Define a Node class for the linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor for the Node class
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor for the Node class
    ~Node()
    {
        // Recursively delete the next node until the end of the linked list is reached
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

// Function to insert a new node at the head of the linked list
void insertAtHead(Node *&head, int data)
{
    // Create a new node with the given data
    Node *temp = new Node(data);

    // Set the next pointer of the new node to the current head of the linked list
    temp->next = head;

    // Set the head of the linked list to the new node
    head = temp;
}

// Function to insert a new node at a given position in the linked list
void insertAtMid(Node *&head, int position, int data)
{
    // Start at the head of the linked list
    Node *temp = head;

    // Keep track of the current position in the linked list
    int count = 1;

    // Traverse the linked list until the desired position is reached
    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // If the position is greater than the length of the linked list, insert at the end
    if (temp == NULL)
    {
        // Create a new node with the given data
        Node *newNode = new Node(data);

        // If the linked list is empty, set the head to the new node
        if (head == NULL)
        {
            head = newNode;
        }
        // Otherwise, traverse the linked list to the end and set the next pointer of the last node to the new node
        else
        {
            Node *tail = head;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = newNode;
        }
    }
    // Otherwise, insert the new node at the given position
    else
    {
        // Create a new node with the given data
        Node *newNode = new Node(data);

        // Set the next pointer of the new node to the next pointer of the current node
        newNode->next = temp->next;

        // Set the next pointer of the current node to the new node
        temp->next = newNode;
    }
}

// Function to insert a new node at the tail of the linked list
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // Create a new node with the given data
    Node *newNode = new Node(data);

    // If the linked list is empty, set the head and tail to the new node
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    // Otherwise, set the next pointer of the current tail to the new node, and update the tail pointer to the new node
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to delete a node at a given position in the linked list
void deleteNode(int position, Node *&head)
{
    // If the position is 1, delete the head node
    if (position == 1)
    {
        // Save a pointer to the current head node
        Node *temp = head;

        // Set the head of the linked list to the next node
        head = head->next;

        // Set the next pointer of the current head node to NULL
        temp->next = NULL;

        // Delete the current head node
        delete temp;
    }
    // Otherwise, traverse the linked list to the node before the one to be deleted, and update the next pointer
    else
    {
        // Start at the head of the linked list
        Node *curr = head;

        // Keep track of the previous node
        Node *prev = NULL;

        // Keep track of the current position in the linked list
        int count = 1;

        // Traverse the linked list until the desired position is reached
        while (count < position && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        // If the desired position is found, update the next pointer of the previous node to the next node, and delete the current node
        if (curr != NULL)
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}
// Function to print the linked list
void print(Node *head)
{
    // Start at the head of the linked list
    Node *temp = head;

    // Traverse the linked list and print each node's data
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Print a newline character at the end of the output
    cout << endl;
}

// Main function
int main()
{
    // Create the first node of the linked list
    Node *node1 = new Node(10);

    // Set the head and tail pointers to the first node
    Node *tail = node1;
    Node *head = node1;

    // Insert nodes at various positions in the linked list
    insertAtMid(head, 2, 11);
    insertAtMid(head, 3, 12);
    insertAtMid(head, 4, 13);
    insertAtMid(head, 5, 14);
    insertAtMid(head, 6, 15);
    insertAtMid(head, 4, 100);
    insertAtHead(head, 99);

    // Delete a node from the linked list
    deleteNode(1, head);

    // Print the linked list
    print(head);

    // Return 0 to indicate successful execution of the program
    return 0;
}
```