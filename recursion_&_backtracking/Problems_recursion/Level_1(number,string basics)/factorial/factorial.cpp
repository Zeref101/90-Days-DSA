#include <iostream>
using namespace std;

int f(int n)
{
    if (n == 1)
    {
        return n;
    }
    return n * f(n - 1);
}
int main()
{
    int n = 4;
    cout << f(n);
}