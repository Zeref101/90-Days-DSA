#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    // *Constructor
    
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtMid(Node *&head,int position, int data)
{
    Node* temp = head;
    int count = 1;
    while(count<position-1)
    {
        temp = temp->next;
        count++;
    }
    // * creating new node
    Node *toBeInserted = new Node(data);
    toBeInserted->next = temp->next;
    temp->next = toBeInserted;
}
void print(Node *&head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtMid(head,2,11);
    insertAtMid(head,3,12);
    insertAtMid(head,4,13);
    insertAtMid(head,5,14);
    insertAtMid(head,6,15);
    insertAtMid(head,4,100);
    print(head);
    return 0;

}