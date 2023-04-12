#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // ? constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//  ? new node create
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    // cout << (*node1).data << endl;
    // cout << (*node1).next << endl;
    Node *head = node1;
    // cout << (*head).data << endl;
    // cout << (*head).next << endl;

    InsertAtHead(head, 12);
    print(head);
    return 0;
}