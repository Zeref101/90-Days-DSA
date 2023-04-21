#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtTail(Node *&tail, int position, int d)
{
    if (position == 1)
    {
        if (tail == NULL)
        {
            Node *newnode = new Node(d);
            newnode->next = newnode;
            tail = newnode;
        }
        else
        {
            Node *newnode = new Node(d);
            newnode->next = tail->next;
            tail->next = newnode;
        }
    }
    else
    {
        Node *newnode = new Node(d);
        Node *temp = tail->next;
        Node *head = tail->next;
        int count = 1;
        while (count < position-1)
        {
            count++;
            temp = temp->next;
        }
        if(temp->next == head)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            tail = newnode;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return;
    }
}

void print(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}


int main()
{
    Node *tail = NULL;
    insertAtTail(tail, 1, 9);
    insertAtTail(tail, 2, 10);
    insertAtTail(tail, 3, 11);
    insertAtTail(tail, 4, 12);
    insertAtTail(tail, 3, 0);
    insertAtTail(tail, 1, -1);
    print(tail);
    cout<<"tail: "<<tail->data;
    return 0;
}
