# QUESTION

Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
Input :
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output :
-8 0 -6 -6

## EXPLAINATION

```cpp
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    // Create a deque to store the indices of negative elements in the current window
    deque<long long int> d;
    // Create a vector to store the first negative integer in each window
    vector<long long> ans;

    // Process the first window
    for (int i = 0; i < K; i++)
    {
        // If the current element is negative, add its index to the deque
        if (A[i] < 0)
        {
            d.push_back(i);
        }
    }

    // Check if the deque is empty
    if (!(d.empty()))
    {
        // If the deque is not empty, store the first negative integer in the ans vector
        ans.push_back(A[d.front()]);
    }
    else
    {
        // If the deque is empty, store 0 in the ans vector
        ans.push_back(0);
    }

    // Process the remaining windows
    for (int i = K; i < N; i++)
    {
        // Remove the front element of the deque if it is outside the current window
        if (!(d.empty()) && i - d.front() >= K)
        {
            d.pop_front();
        }

        // Add the current element's index to the deque if it is negative
        if (A[i] < 0)
        {
            d.push_back(i);
        }

        // Check if the deque is empty
        if (d.size() > 0)
        {
            // If the deque is not empty, store the first negative integer in the ans vector
            ans.push_back(A[d.front()]);
        }
        else
        {
            // If the deque is empty, store 0 in the ans vector
            ans.push_back(0);
        }
    }

    // Return the ans vector containing the first negative integer in each window
    return ans;
}

```
