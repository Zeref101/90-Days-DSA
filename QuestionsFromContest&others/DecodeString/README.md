```cpp
#include<bits/stdc++.h>

class Solution {
public:
    string decodeString(string s) {
        ios_base::sync_with_stdio(false);  // Optimize input/output operations
        
        stack<char> st;  // Stack to store characters
        string curr = "";  // Variable to store the current substring
        
        // Traverse the input string from right to left
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '[') {  // If a closing bracket is encountered
                string k = "";
                i--;
                
                // Extract the number before the opening bracket
                while(i >= 0 && isdigit(s[i])) {
                    k.push_back(s[i]);
                    i--;
                }
                
                reverse(k.begin(), k.end());  // Reverse the number
                int num = stoi(k);  // Convert the string number to an integer
                
                curr = "";
                while(!st.empty() && st.top() != ']') {
                    curr.push_back(st.top());  // Build the current substring
                    st.pop();
                }
                
                st.pop();  // Remove the closing bracket from the stack
                
                while(num--) {
                    // Push the characters of the current substring back into the stack
                    for(int j = curr.length() - 1; j >= 0; j--) {
                        st.push(curr[j]);
                    }
                }
                
                i++;  // Adjust the index to continue parsing the original string
                curr = "";  // Reset the current substring
            }
            else if(s[i] == ']') {
                st.push(s[i]);  // Push closing brackets into the stack
            }
            else {
                st.push(s[i]);  // Push other characters into the stack
            }
        }
        
        s = "";
        while(!st.empty()) {
            s.push_back(st.top());  // Build the final decoded string
            st.pop();
        }
        
        reverse(s.begin(), s.end());  // Reverse the string to get the correct order
        
        return s;
    }
};

```