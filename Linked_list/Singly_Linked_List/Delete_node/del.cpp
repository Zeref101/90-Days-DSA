#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertHead(Node *&head,int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertTail(Node *&head,Node *&tail, int data)
{
    Node *newnode = new Node(data);

    // empty linked list or not
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

void insertMid(Node *&head, int position, int data)
{
    Node *temp = head;
    int count = 1;
    while (count < position-1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    Node *newnode = new Node(data);
    if(temp == NULL)
    {
        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *tail = head;
            while(tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = newnode;
        }
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void deleteNode(Node *&head, Node *&tail, int position)
{
    if(position==1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while(count < position && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            count ++;
        }
        if(curr != NULL)
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        
    }

}
void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *tail = node1;
    Node *head = node1;

    insertMid(head, 2, 11);
    insertMid(head, 3, 12);
    insertMid(head, 4, 13);
    insertMid(head, 5, 14);
    insertMid(head, 6, 15);
    insertMid(head, 4, 100);
    insertHead(head, 99);
    deleteNode(head, tail, 1);
    print(head);

   return 0;
}