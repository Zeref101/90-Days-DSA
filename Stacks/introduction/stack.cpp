#include<iostream>
#include<stack>
using namespace std;

class Stack
{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if(size-top > 1)
        {
            top++;
            arr[top] = data;
            
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
            return arr[top];
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
    if(s.isempty())
    {
        cout<<"Its empty"<<endl;
    }
    else{
        cout<<"No its not empty"<<endl;
    }
    
    //? push
    return 0;
}
