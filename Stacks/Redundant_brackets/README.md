# EXPLAINATION

```cpp
#include <bits/stdc++.h>
#include <stack>

// Function to check for redundant brackets
bool findRedundantBrackets(string &s)
{
    stack<char> stack; // Create a stack to store characters

    // Iterate through each character in the string
    for(int i = 0; i < s.length(); i++)
    {
        char element = s[i]; // Get the current character

        // If the character is an opening bracket or an operator (+, -, *, /), push it onto the stack
        if((element == '(') || (element == '+') || (element == '-') || (element == '*') || (element == '/'))
        {
            stack.push(element);
        }
        else if(element == ')') // If the character is a closing bracket
        {
            bool is_redundant = true; // Flag to check if the closing bracket is redundant

            // Check if there is any operator between the opening and closing brackets
            while(stack.top() != '(')
            {
                char c = stack.top();
                if((c == '+') || (c == '-') || (c == '*') || (c == '/'))
                {
                    is_redundant = false; // Found an operator, so the closing bracket is not redundant
                }
                stack.pop(); // Pop elements until the corresponding opening bracket is found
            }

            if(is_redundant)
            {
                return true; // Return true if the closing bracket is redundant
            }

            stack.pop(); // Remove the opening bracket from the stack
        }
    }

    return false; // Return false if no redundant brackets are found
}
```

## The main logic of the code is as follows

* It iterates through each character of the input string.
* If the character is an opening bracket or an operator, it is pushed onto the stack.
* If the character is a closing bracket, it checks for the presence of an operator between the corresponding opening and closing brackets.
* If no operator is found, the closing bracket is marked as redundant and removed from the stack.
* Finally, if any redundant bracket is found, the function returns true; otherwise, it returns false.
Note that the code assumes the input string is a valid expression and does not handle cases with invalid or unbalanced brackets.

![doubt](./Screenshot%20from%202023-05-10%2014-08-29.png)
