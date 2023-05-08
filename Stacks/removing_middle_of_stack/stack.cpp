#include<iostream>
#include<stack>
using namespace std;

void removeMid(stack<int> &arr, int count, int size)
{
    if(count == size/2)
    {
        arr.pop();
        return;
    }
    int val = arr.top();
    arr.pop();
    removeMid(arr,count+1, size);
    arr.push(val);

    return;
}
void print(stack<int> &arr)
{
    while(!arr.empty())
    {
        cout<<arr.top()<<endl;
        arr.pop();
    }
    return;
}
int main()
{
    stack<int> arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);
    arr.push(5);
    arr.push(6);

    int size = arr.size();
    int count = 0;

    removeMid(arr,count, size);
    print(arr);
    
    return 0;
}
