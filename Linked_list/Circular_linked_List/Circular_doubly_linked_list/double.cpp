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

void insert(Node *&tail, int position, int d)
{
    if(position==1)
    {   
        Node *newnode = new Node(d);
        if(tail==NULL)
        {
            tail = newnode;
            tail->next = tail;
            tail->prev = tail;
        }
        else
        {
            newnode->next = tail->next;
            tail->next->prev = newnode;
            tail->next = newnode;
            newnode->prev = tail;
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
        if(temp->next == tail)
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
    Node *temp = tail;
    cout << temp->data<<" ";
    while(temp->next != tail)
    {
        temp = temp->next;
        cout<<temp->data<<" ";  
    }
    cout << endl;
}
int main()
{
    Node *tail = NULL;
    insert(tail, 1, 1);
    insert(tail, 2, 2);
    insert(tail, 3, 3);
    insert(tail, 2, 5);
    print(tail);
    cout<<"tail: "<<tail->data;
    return 0;
}