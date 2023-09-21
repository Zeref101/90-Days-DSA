# EXPLAINATION

```cpp
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

```

* The given code is an implementation of a Stack data structure using an array in C++.
* The code begins by including the necessary headers and defining the namespace.
* A Stack class is defined, which has three member variables: an integer array to store the stack elements (arr), an integer top to keep track of the top element index, and an integer size to store the maximum size of the stack.
* The Stack constructor is defined, which takes the maximum size of the stack as an argument. Inside the constructor, the arr array is initialized with the given size, and the top variable is set to -1 to indicate that the stack is initially empty.
* The push() method is defined to add an element to the stack. It takes the data to be added as an argument. If there is space in the stack (i.e., the difference between size and top is greater than 1), the top index is incremented and the new element is added to the arr array at the updated top index. If there is no space in the stack, a "Stack Overflow" message is printed to the console.
* The pop() method is defined to remove the top element from the stack. If the top index is greater than or equal to 0 (i.e., there is at least one element in the stack), the top index is decremented to remove the top element. If the stack is empty (i.e., top is -1), a "Stack Underflow" message is printed to the console.
* The peek() method is defined to return the top element of the stack without removing it. If the stack is not empty (i.e., top is greater than or equal to 0), the top element at index top of the arr array is returned. If the stack is empty, a "Stack is empty" message is printed to the console, and -1 is returned.
* The isempty() method is defined to check whether the stack is empty. It returns true if the top index is -1 (i.e., the stack is empty) and false otherwise.
* In the main() function, a Stack object s is created with a maximum size of 5.
* Elements are added to the stack using the push() method, and the top element is printed using the peek() method after each addition.
* An element is removed from the stack using the pop() method, and the top element is printed again.
* The isempty() method is called to check if the stack is empty, and a message is printed to the console accordingly.
* The program then exits with a return value of 0.
