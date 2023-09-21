# QUESTION

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days.
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

## EXPLAINATION

```cpp
class Solution
{
public:
    // Function to calculate the span of stock's price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        stack<int> st;         // Create a stack to store indices of stock prices
        vector<int> ans(n);    // Create a vector to store the span values

        st.push(0);            // Push the index of the first day into the stack
        for (int i = 0; i < n; i++)
        {
            // Remove the indices from the stack for which the stock price
            // is less than or equal to the current day's price.
            while (!st.empty() && price[st.top()] <= price[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                // If the stack becomes empty, it means there is no higher
                // price to the left, so the span is the current day's index + 1.
                ans[i] = i + 1;
            }
            else
            {
                // If there is a higher price to the left, the span is the difference
                // between the current day's index and the top element of the stack.
                ans[i] = i - st.top();
            }

            st.push(i);    // Push the current day's index into the stack
        }

        return ans;    // Return the vector containing the span values
    }
};
```

* The code uses a stack to keep track of indices of stock prices. The stack stores the indices of previous days where the stock price was higher than the current day's price.
* The vector ans is initialized with size n to store the span values for each day.
* The first day's index (0) is pushed into the stack to start the iteration.
* The for loop iterates over the remaining days from index 1 to index n-1.
* Inside the loop, a while loop is used to remove the indices from the stack for which the stock price is less than or equal to the current day's price. This is done to ensure that the stack only contains indices of days with higher prices.
* If the stack becomes empty after removing elements, it means there is no higher price to the left. So, the span for the current day is the current day's index + 1.
* If the stack is not empty, there is a higher price to the left. In this case, the span for the current day is the difference between the current day's index and the top element of the stack.
* After calculating the span, the current day's index is pushed into the stack to be considered for future calculations.
* Finally, the vector ans containing the span values for all days is returned.
