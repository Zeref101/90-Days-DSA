# EXPLAINTION

* The question that the above code is solving is the "Largest Rectangle in Histogram" problem. The goal is to find the maximum area of a rectangle that can be formed within a given histogram, where the histogram is represented by an array of non-negative integers. Each bar in the histogram represents the height of the bar, and the width of each bar is assumed to be 1. The task is to find the largest rectangular area that can be formed within the histogram.

```cpp
class Solution {
public:
    vector<int> nextSmallerElements(vector<int> &heights, int size)
    {
        vector<int> ans(size);
        stack<int> s;
        s.push(-1);
        for(int i=size-1;i>=0;i--)
        {
            int curr = heights[i];
            while(s.top()!= -1 && heights[s.top()]>=curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElements(vector<int> &heights, int size)
    {
        vector<int> ans(size);
        stack<int> s;
        s.push(-1);
        for(int i=0 ;i<size;i++)
        {
            int curr = heights[i];
            while(s.top()!= -1 && heights[s.top()]>=curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> nextSmaller = nextSmallerElements(heights, size);
        vector<int> prevSmaller = prevSmallerElements(heights, size);
        int area = INT_MIN;
        for(int i = 0; i<size;i++)
        {
            if(nextSmaller[i] == -1)
            {
                nextSmaller[i] = size;
            }
            int b = nextSmaller[i]-prevSmaller[i]-1;
            int l = heights[i];

            int new_area = l*b;
            area = max(area, new_area);
        }
        return area;

    }
}
```

## nextSmallerElements function

* This function takes a vector of heights (representing the histogram) and the size of the histogram as input.
* It initializes an empty vector called ans to store the result.
* It also uses a stack called s to keep track of the indices of elements in the heights vector.
* The stack s is initially pushed with -1 to mark the end of the histogram.
* The function then iterates through the heights vector in reverse order (from the last element to the first).
* For each element, it compares it with the top of the stack (s.top()).
* If the element is smaller than or equal to the element at the top of the stack, it pops elements from the stack until it finds an element smaller than the current element or the stack becomes empty.
* After the while loop, it assigns the index of the element at the top of the stack (or -1 if the stack is empty) to the corresponding index in the ans vector.
* Finally, it pushes the current index into the stack.
* Once the loop ends, it returns the ans vector containing the indices of the next smaller elements for each element in the heights vector.

## prevSmallerElements function

* This function is similar to the nextSmallerElements function, but it calculates the indices of the previous smaller elements.
* It also uses a stack called s to keep track of the indices of elements in the heights vector.
* The stack s is initially pushed with -1 to mark the start of the histogram.
* The function then iterates through the heights vector from the first element to the last.
* For each element, it compares it with the top of the stack (s.top()).
* If the element is smaller than or equal to the element at the top of the stack, it pops elements from the stack until it finds an element smaller than the current element or the stack becomes empty.
* After the while loop, it assigns the index of the element at the top of the stack (or -1 if the stack is empty) to the corresponding index in the ans vector.
* Finally, it pushes the current index into the stack.
* Once the loop ends, it returns the ans vector containing the indices of the previous smaller elements for each element in the heights vector.

## LargestRectangleArea function

* This function takes a vector of heights as input.
* It calculates the size of the histogram by getting the size of the heights vector.
* It then calls the nextSmallerElements function and stores the result in the nextSmaller vector.
* Similarly, it calls the prevSmallerElements function and stores the result in the prevSmaller vector.
* It also initializes a variable called area to store the maximum area, initially set to INT_MIN (a very small value).
* After obtaining the nextSmaller and prevSmaller vectors, the function proceeds with a loop that iterates through each element of the heights vector.
* For each element, it performs the following steps:
* If the corresponding value in the nextSmaller vector is -1, it means there is no element to the right that is smaller than the current element. In this case, the index is set to the size of the histogram.
* It calculates the width of the rectangle by subtracting the index of the previous smaller element (obtained from the prevSmaller vector) from the index of the next smaller element (obtained from the nextSmaller vector) and subtracting 1. This gives the number of bars between the two indices, which represents the width of the rectangle.
* It then assigns the height of the current element to the variable l.
* The new area is calculated by multiplying the height (l) with the width (b).
* If the new area is greater than the current maximum area (area), it updates the area variable.
* After the loop ends, it returns the maximum area (area).
