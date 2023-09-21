# EXPLAINATION

```cpp
#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string str) {
  // Check if the length of the string is odd
  // If so, it's not possible to balance the parentheses
  if(str.length() % 2 != 0) {
    return -1;
  }

  // Create a stack to store the opening parentheses '{'
  stack<char> stack;

  // Traverse each character of the input string
  for (int i = 0; i < str.length(); i++) {
    char ele = str[i];

    // If the current character is an opening parenthesis '{',
    // push it onto the stack
    if (ele == '{') {
      stack.push(ele);
    }
    else {
      // If the stack is not empty and the top of the stack is an opening parenthesis,
      // pop the top element from the stack as the current closing parenthesis matches
      // with an opening parenthesis
      if (!stack.empty() && stack.top() == '{') {
        stack.pop();
      }
      else {
        // If the stack is empty or the top of the stack is not an opening parenthesis,
        // push the current closing parenthesis onto the stack
        stack.push(ele);
      }
    }
  }

  // Count the remaining unbalanced parentheses
  int a = 0; // Count of opening parentheses '{'
  int b = 0; // Count of closing parentheses '}'

  while (!stack.empty()) {
    if (stack.top() == '{') {
      b++; // Count the unbalanced opening parenthesis
    }
    else {
      a++; // Count the unbalanced closing parenthesis
    }
    stack.pop();
  }

  // Calculate the minimum cost to balance the parentheses
  int ans = (a + 1) / 2 + (b + 1) / 2;

  return ans;
}

int main() {
  string str = "{}}{{}";
  int res = findMinimumCost(str);
  cout<<res;
  return 0;
}
```
