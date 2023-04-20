#include<iostream>
using namespace std;

// Node class to define the structure of each node in the doubly linked list
class Node {
public:
    int data;       // data stored in the node
    Node* prev;     // pointer to the previous node
    Node* next;     // pointer to the next node

    Node(int d) {   // constructor to initialize the node with data
        data = d;
        prev = NULL;
        next = NULL;
    }

    // destructor to recursively delete the nodes
    ~Node() {
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

// function to insert a new node at the head of the list
void insertAtHead(Node*& head, Node*& tail, int d) {
    Node* newnode = new Node(d);    // create a new node with the given data
    if (head == NULL) {             // if the list is empty
        head = newnode;             // set the head and tail to the new node
        tail = newnode;
    }
    else {                          // if the list is not empty
        newnode->next = head;       // set the next pointer of the new node to the current head
        head->prev = newnode;       // set the previous pointer of the current head to the new node
        head = newnode;             // set the head to the new node
    }
}

// function to insert a new node at the tail of the list
void insertAtTail(Node*& head, Node*& tail, int d) {
    Node* newnode = new Node(d);    // create a new node with the given data
    if (head == NULL) {             // if the list is empty
        head = newnode;             // set the head and tail to the new node
        tail = newnode;
    }
    else {                          // if the list is not empty
        tail->next = newnode;       // set the next pointer of the current tail to the new node
        newnode->prev = tail;       // set the previous pointer of the new node to the current tail
        tail = newnode;             // set the tail to the new node
    }
}

// function to insert a new node at a given position in the list
void insertAtMid(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {            // if the position is the head
        insertAtHead(head, tail, d);    // insert the node at the head
        return;                     // exit the function
    }
    Node* newnode = new Node(d);    // create a new node with the given data
    Node* temp = head;              // create a temporary pointer to the head
    int count = 1;                  // initialize a counter
    while (count < position - 1 && temp != NULL) { // traverse the list until the count equals the position or the end of the list is reached
        temp = temp->next;          // move to the next node
        count++;                    // increment the counter
    }
    if (temp == NULL) {             // if the end of the list is reached without finding the position
        insertAtTail(head, tail, d);    // insert the node at the tail
        return;                     // exit the function
    }
    if (temp->next != NULL) {       // if the position is not the tail
        newnode->next = temp->next; // set new node next pointer to temporory next pointer
        temp->next->prev = newnode; // set the previous pointer of next to the temporary element to the new node
        temp->next = newnode;       // set temp next pointer to new node
        newnode->prev = temp;       // set the new node prev to the temp 
        return;
    }
    temp->next = newnode;           // else set temp next pointer to newnode
    newnode->prev = temp;           // set new node prev to the temp
    tail = newnode;
    return;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if(position == 1) // if the position to delete is the first node
    {
        Node *temp = head; // create a temporary pointer to the head node
        head = head->next; // move the head pointer to the next node
        if (head != NULL) // if the new head is not NULL
            head->prev = NULL; // set its previous pointer to NULL
        temp->next = NULL; // set the next pointer of the deleted node to NULL
        delete temp; // delete the node
    }
    else // if the position to delete is not the first node
    {
        Node *temp = head; // create a temporary pointer to the head node
        int count = 1; // initialize a counter
        while(count < position && temp != NULL) // traverse the list until the count equals the position or the end of the list is reached
        {
            count ++;
            temp = temp->next;
        }
        if (temp == NULL) { // if the end of the list is reached without finding the position
            return; // exit the function
        }
        if (temp == tail) {    // if the position to delete is the last node
            tail = tail->prev; // move the tail pointer to the previous node
            tail->next = NULL; // set the next pointer of the new tail node to NULL
            temp->prev = NULL; // set the previous pointer of the deleted node to NULL
            delete temp;       // delete the node
            return;            // exit the function
        }
        temp->prev->next = temp->next; // set the next pointer of the previous node to the next node
        temp->next->prev = temp->prev; // set the previous pointer of the next node to the previous node
        temp->next = NULL;             // set the next pointer of the deleted node to NULL
        temp->prev = NULL;             // set the previous pointer of the deleted node to NULL
        delete temp;                   // delete the node
    }
}


int length(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail, 12);
    insertAtTail(head, tail, 14);
    insertAtMid(head, tail, 3, 16);
    insertAtMid(head, tail, 2, 18);
    insertAtMid(head, tail, 4, 19);
    insertAtMid(head, tail, 5, 11);
    insertAtMid(head, tail, 4, 21);
    deleteNode(head, tail, 7);
    cout << "Length of the list: " << length(head) << endl;
    cout << "Data in the list: ";
    print(head);
    cout << "head: "<< head->data<< endl;
    cout << "tail: "<< tail->data<< endl;
    return 0;
}