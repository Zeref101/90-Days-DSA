#include<iostream>
using namespace std;

class Node
{
    public:
    Node *prev;
    int data;
    Node *next;

    //? constructor
    
    Node(int d)
    {
        prev = NULL;
        data = d;
        next = NULL;
    }
};

void insert(Node *&head,Node *&tail, int position, int d)
{
    if(position==1)
    {   
        Node *newnode = new Node(d);
        if(tail==NULL)
        {
            tail = newnode;
            tail->next = tail;
            tail->prev = tail;
            head = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next->prev = newnode;
            tail->next = newnode;
            newnode->prev = tail;
            head = newnode;
        }
    }
    else
    {
        Node *newnode = new Node(d);
        Node *temp = tail->next;
        
        int count = 1;
        while(count < position-1)
        {
            temp = temp->next;
            count++;
        }
        if(temp->next == head)
        {
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            tail = newnode;   
        }
        else
        {
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}
void print(Node *&tail)
{
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
    Node *head = NULL;
    insert(head, tail, 1, 1);
    insert(head, tail, 2, 2);
    insert(head, tail, 3, 3);
    insert(head, tail, 2, 5);
    print(tail);
    cout<<"tail: "<<tail->data;
    return 0;
}