#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertAtHead(Node*& head,Node *&tail, int d) {
    Node* newnode = new Node(d);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    }
    else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertAtTail(Node*& head, Node*& tail, int d) {
    Node* newnode = new Node(d);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertAtMid(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }
    Node* newnode = new Node(d);
    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        insertAtTail(head, tail, d);
        return;
    }
    
    if (temp->next != NULL) {
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
        return;
    }
    temp->next = newnode;
    newnode->prev = temp;
    tail = newnode;
    return;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if(position == 1)
    {
        Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        int count = 1;
        while(count < position && temp != NULL)
        {
            count ++;
            temp = temp->next;
        }
        if (temp == NULL) {
            return;
        }
        if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
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