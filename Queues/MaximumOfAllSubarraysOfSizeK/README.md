# QUESTION

Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

* Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
* Output:
3 3 4 5 5 5 6

```cpp
class Solution {
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k) {
        vector<int> ans; // Vector to store the maximum elements of subarrays
        deque<int> d;    // Deque to store the indices of potential maximum elements
        
        int i;
        for (i = 0; i < k; i++) {
            // Removing unwanted numbers
            while (!d.empty() && arr[d.back()] < arr[i]) {
                d.pop_back(); // Remove indices of smaller elements from the deque
            }
            d.push_back(i); // Add the current index to the deque
        }
        
        int last = 0;
        for (; i < n; ++i) {
            ans.push_back(arr[d.front()]); // Store the maximum element of the previous window
            
            // Remove elements which are not in the current window
            while (!d.empty() && d.front() <= i - k) {
                d.pop_front(); // Remove indices that are outside the current window
            }
            
            while (!d.empty() && arr[i] > arr[d.back()]) {
                d.pop_back(); // Remove indices of smaller elements from the deque
            }
            
            d.push_back(i); // Add the current index to the deque
        }
        
        ans.push_back(arr[d.front()]); // Store the maximum element of the last window
        d.pop_front(); // Remove the index of the maximum element
        
        return ans; // Return the vector containing the maximum elements of subarrays
    }
};
```
