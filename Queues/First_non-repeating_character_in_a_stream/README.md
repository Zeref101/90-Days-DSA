# QUESTION

Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer

Input: A = "aabc"
Output: "a#bb"

## EXPLAINATION

```cpp
class Solution {
public:
    string FirstNonRepeating(string A) {
        unordered_map<char, int> m; // Create an unordered map to store character frequencies
        queue<char> q; // Create a queue to maintain the order of characters
        string ans = ""; // Create an empty string to store the answer
        
        for(int i = 0; i < A.length(); i++) {
            char ch = A[i]; // Get the current character from the input string
            m[ch]++; // Increment the frequency of the character in the map
            q.push(ch); // Push the character into the queue
            
            while(!q.empty()) {
                if(m[q.front()] > 1) {
                    q.pop(); // If the front character of the queue has a frequency greater than 1, remove it from the queue
                } else {
                    ans += q.front(); // If the front character of the queue has a frequency of 1, append it to the answer string
                    break;
                }
            }
            
            if(q.empty()) {
                ans += "#"; // If the queue becomes empty, append "#" to the answer string indicating no non-repeating character found
            }
        }
        
        return ans; // Return the answer string
    }
};
```
