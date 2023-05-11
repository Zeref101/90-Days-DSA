# EXPLAINATION

![quesiton](./Screenshot%20from%202023-05-11%2018-04-48.png)

```cpp
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n); // Create a vector to store the result
    stack<int> s; // Create a stack to store elements

    s.push(-1); // Push -1 as a sentinel value to handle the case when there is no smaller element

    // Iterate over the input array in reverse order
    for(int i = n-1; i >= 0; i--)
    {
        int curr = arr[i]; // Get the current element

        // Pop elements from the stack until a smaller element than 'curr' is found
        while(s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top(); // Store the smaller element (top of stack) in the result vector
        s.push(curr); // Push 'curr' to the stack for the next iteration
    }

    return ans; // Return the resulting vector
}

int main()
{
  vector<int> arr = {2,4,12,99,6,3,1}; // Input array
  int size = arr.size(); // Get the size of the array
  vector<int> vec = nextSmallerElement(arr, size); // Call the function to get the next smaller elements
  for(auto ele:vec)
  {
    cout<<ele<<" "; // Print the elements of the resulting vector
  }
  cout<<endl;
  return 0;
}

```

* Inside the function, a stack s is created to store the elements. Initially, -1 is pushed into the stack as a sentinel value.
* The function iterates over the input vector arr in reverse order, starting from the last element.
* For each element curr, it checks if the top of the stack is greater than or equal to curr. If it is, it means that the top of the stack is the next smaller element for curr. So, it pops elements from the stack until a smaller element is found.
* After finding the next smaller element, it stores it in the corresponding position of the ans vector.
* Finally, it pushes the current element curr into the stack for the next iteration.
* Once the iteration is complete, the function returns the resulting ans vector.
