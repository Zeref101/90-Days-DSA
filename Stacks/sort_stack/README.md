# EXPLAINATION

```cpp
#include <bits/stdc++.h> 

// Function to insert an element in a sorted manner into the stack
void sortInsert(stack<int> &stack, int val)
{
    // If the stack is empty or the top element of the stack is less than the value to be inserted
    if ((stack.empty()) || (!stack.empty() && stack.top() < val))
    {
        // Push the value into the stack
        stack.push(val);
        return;
    } 

    // If the top element of the stack is greater than or equal to the value to be inserted
    int n = stack.top();
    stack.pop();

    // Recursively call sortInsert to find the correct position for the value
    sortInsert(stack, val);

    // Once the correct position is found, push the previously removed element back into the stack
    stack.push(n);
    return;
}

// Function to sort the stack using recursion
void sortStack(stack<int> &stack)
{
    // Base case: if the stack is empty, return
    if (stack.empty())
    {
        return;
    }

    // Remove the top element of the stack
    int val = stack.top();
    stack.pop();

    // Recursively call sortStack to sort the remaining elements in the stack
    sortStack(stack);

    // Call sortInsert to insert the removed element in the correct sorted position within the stack
    sortInsert(stack, val);
}
```

* The sortStack function uses a recursive approach to sort the stack. It repeatedly removes the top element from the stack and recursively calls itself to sort the remaining elements. Then, it uses the sortInsert function to insert the removed element in the correct sorted position within the stack.
