#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top1;
    int top2;
    int *arr;

    Stack(int num)
    {
        size = num;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int x)
    {
        if (top1 == top2)
        {
            cout << "stack is full" << endl;
        }
        top1++;
        arr[top1] = x;
    }

    void push2(int x)
    {
        if (top1 == top2)
        {
            cout << "Stack is full" << endl;
        }
        top2--;
        arr[top2] = x;
    }

    int pop1()
    {
        if(top1==-1)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[top1--];
        }
    }

    int pop2()
    {
        if(top2==size)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else
        {
            return arr[top2++];
        }
    }
};

int main()
{
    Stack stack(4);

    stack.push1(10);
    stack.push1(20);
    stack.push2(30);
    stack.push2(40);

    cout << "The top element of stack1 is " << stack.pop1() << endl;
    cout << "The top element of stack2 is " << stack.pop2() << endl;

    return 0;
}