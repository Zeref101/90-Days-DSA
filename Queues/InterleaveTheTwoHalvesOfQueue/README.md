# QUESTION

Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.
Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20

```cpp  
#include <bits/stdc++.h> 
#include<queue>
using namespace std;
void interLeaveQueue(queue < int > & q) {
    int size = q.size();
    int mid = size/2;

    queue<int> temp;
    
    for(int i=0;i<mid;i++)
    {
        temp.push(q.front());
        q.pop();
    }

    while(!(q.empty() && temp.empty()))
    {
        cout<<temp.front()<<" ";
        temp.pop();
        cout<<q.front()<<" ";
        q.pop();
    }
}
```
