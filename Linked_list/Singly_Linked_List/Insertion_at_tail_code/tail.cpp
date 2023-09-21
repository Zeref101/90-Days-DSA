#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertionAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp = tail;
}
void print(Node *&tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // update temp to point to the next node
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    Node *tail = node1;
    insertionAtTail(tail, 12);
    print(tail);

    return 0;
}