# EXPLAINATION

```cpp
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

```

* This is a C++ implementation of a stack using a linked list.
* The Node class is defined first, which contains a data integer and a next pointer to the next node in the linked list.
* The Stack class is then defined, which has a head pointer to the top of the stack, a tail pointer to the bottom of the stack, and top and size integers to keep track of the current position and maximum size of the stack, respectively.
* The push function takes an integer data as input, creates a new Node with that data, and adds it to the end of the linked list, updating tail accordingly.
* The pop function removes the last Node in the linked list and updates both tail and top.
* The peek function returns the data stored in the last Node in the linked list (i.e., the top of the stack), or -1 if the stack is empty.
* The isempty function returns a boolean indicating whether the stack is empty or not.
* In main, a Stack object is created with a maximum size of 5. Various integers are pushed onto the stack using the push function, and the top value is printed using the peek function. One integer is popped off the stack using the pop function, and the top value is printed again. Several more integers are pushed onto the stack, including one that causes a stack overflow (the size of the stack has already reached its maximum). Finally, the isempty function is used to check if the stack is empty or not.
