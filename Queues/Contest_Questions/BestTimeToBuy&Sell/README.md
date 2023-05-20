# QUESTION

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

## EXPLAINATION

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> arr(n);

        arr[n-1] = prices[n-1];
        //  getting the auxilary array
        for(int i=n-2;i>=0;i--)
        {
            if(prices[i]>=arr[i+1])
            {
                arr[i] = prices[i];
            }
            else
            {
                arr[i] = arr[i+1];
            }
        }
        int max=0;
        int maxIndex=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]-prices[i]>max)
            {
                max = arr[i]-prices[i];
            }
        }
        return max;

    }
};
```
