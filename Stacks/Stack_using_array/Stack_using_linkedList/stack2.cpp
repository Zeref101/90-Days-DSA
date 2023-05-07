#include<iostream>
#include<stack>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data = d;
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

class Stack
{
    public:
    Node* head = NULL;
    Node* tail = NULL;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;

        top = -1;
    }

    void push(int data)
    {
        if(size-top > 1)
        {
            top++;
            Node* newnode = new Node(data);
            if(tail == NULL)
            {
                head = newnode;
                tail = newnode;
            }
            else{
                tail->next = newnode;
                tail = newnode;
            }
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop()
    {
        if(top>=0)
        {
            Node* temp = tail;
            if(top == 0)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                Node* prev = head;
                while (prev->next != tail)
                {
                    prev = prev->next;
                }
                tail = prev;
                tail->next = NULL;
            }
            delete temp;
            top--;
        }
        else
        {
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek()
    {
        if(top>=0)
        {
            return tail->data;
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool isempty()
    {
        if(top == -1)
        {
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
    Stack s(5);
    s.push(1);
    cout<<s.peek()<<endl;
    s.push(2);
    cout<<s.peek()<<endl;
    s.push(3);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.push(4);
    cout<<s.peek()<<endl;
    s.push(5);
    cout<<s.peek()<<endl;
    s.push(6);
    cout<<s.peek()<<endl;
    s.push(7);

    if(s.isempty())
    {
        cout<<"Its empty"<<endl;
    }
    else{
        cout<<"No its not empty"<<endl;
    }
    return 0;
}
