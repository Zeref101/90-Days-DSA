```cpp
class Solution{
  public:
    int missing(vector<int>& array, int n)
    {
        // one term missing so n++
        int total = (n*(n+1))/2;
        for(auto num:array)
        {
            total -= num;
        }
        return total;
    }
    
    int missingNumber(vector<int>& array, int n) {
        int num = missing(array, n);
        return num;
    }
};
```