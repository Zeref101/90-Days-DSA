# QUESTION

Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.

* The amount of petrol that every petrol pump has.
* Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

```cpp
class Solution{
public:
    // Function to find the starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int deficit = 0;  // Variable to track the cumulative deficit of petrol
        int balance = 0;  // Variable to track the current balance of petrol
        int start = 0;    // Variable to store the starting point
        
        for (int i = 0; i < n; i++)
        {
            balance = balance + (p[i].petrol - p[i].distance);  // Update the balance by adding petrol and subtracting distance
            
            if (balance < 0)
            {
                deficit += balance;   // Update the cumulative deficit
                start = i + 1;        // Update the starting point to the next petrol pump
                balance = 0;          // Reset the balance to zero
            }
        }
        
        if (deficit + balance >= 0)
        {
            return start;   // If the total deficit and remaining balance is non-negative, return the starting point
        }
        else
        {
            return -1;      // If it's not possible to complete the circle, return -1
        }
    }
};
```
