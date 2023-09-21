//!*Given an integer num, return the number of steps to reduce it to zero.
//*In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.//

#include <iostream>
using namespace std;

int f(int n, int steps)
{
    if (n == 0)
    {
        return steps;
    }
    if (n % 2 == 0)
    {
        return f(n / 2, steps + 1);
    }
    return f(n - 1, steps + 1);
}
int main()
{
    int n;
    cin >> n;
    cout << f(n, 0);
}