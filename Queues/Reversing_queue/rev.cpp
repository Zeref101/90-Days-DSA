#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void function(queue<int> &q)
{
    stack<int> s;
    while (!(q.empty()))
    {
        s.push(q.front());
        q.pop();
    }
    while (!(s.empty()))
    {
        q.push(s.top());
        s.pop();
    }
    return;
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    function(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}