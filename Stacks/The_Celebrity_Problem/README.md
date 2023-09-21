# QUESTION

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

## EXPLAINATION

```cpp
class Solution {
public:
    // Function to check if person a knows person b.
    bool knows(vector<vector<int>>& M, int a, int b) {
        if (M[a][b] == 1) {
            return true;
        } else {
            return false;
        }
    }

    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;
        
        // Push all people onto the stack initially.
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Keep eliminating people until only one person remains in the stack.
        while (s.size() != 1) {
            int a = s.top(); // Take the top person.
            s.pop();
            int b = s.top(); // Take the next person from the top.
            s.pop();

            // If person a knows person b, then b cannot be the celebrity.
            // Push person b back into the stack.
            if (knows(M, a, b)) {
                s.push(b);
            }
            // If person a doesn't know person b, then a cannot be the celebrity.
            // Push person a back into the stack.
            else {
                s.push(a);
            }
        }

        int candidate = s.top(); // Potential celebrity.

        int row_count = 0;
        bool row_check = false;

        // Checking the candidate's row for any acquaintance.
        for (int i = 0; i < n; i++) {
            if (M[candidate][i] == 0) {
                row_count++;
            }
        }

        // If the row count is equal to n, it means the candidate has no acquaintances in his row.
        // Mark row_check as true.
        if (row_count == n) {
            row_check = true;
        }

        int col_count = 0;
        bool col_check = false;

        // Checking the candidate's column for any acquaintance.
        for (int i = 0; i < n; i++) {
            if (M[i][candidate] == 1) {
                col_count++;
            }
        }

        // If the column count is equal to n-1, it means the candidate is acquainted with all other people in his column.
        // Mark col_check as true.
        if (col_count == n - 1) {
            col_check = true;
        }

        // If both row_check and col_check are true, then the candidate is the celebrity.
        // Return the candidate index.
        if (row_check && col_check) {
            return candidate;
        } else {
            return -1; // No celebrity found.
        }
    }
};

```
