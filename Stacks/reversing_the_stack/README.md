# EXPLAINATION

```cpp
// This function inserts an integer value at the bottom of a given stack
void insertAtBottom(stack<int> &stack, int val)
{
    // If the stack is empty, simply push the value onto the stack
    if(stack.empty())
    {
        stack.push(val);
        return;
    }
    // Otherwise, pop the top element off the stack and store it in a variable
    int num = stack.top();
    stack.pop();
    // Recursively call the function to insert the new value at the bottom of the stack
    insertAtBottom(stack, val);
    // Push the original top element back onto the stack
    stack.push(num);
}

// This function reverses the order of elements in a given stack
void reverseStack(stack<int> &stack) {
    // If the stack is empty, simply return
    if(stack.empty())
    {
        return;
    }
    // Otherwise, pop the top element off the stack and store it in a variable
    int val = stack.top();
    stack.pop();
    // Recursively call the function to reverse the remaining elements in the stack
    reverseStack(stack);
    // Insert the original top element at the bottom of the stack
    insertAtBottom(stack, val);
}

```
