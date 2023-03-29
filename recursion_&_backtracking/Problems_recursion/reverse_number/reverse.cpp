#include <iostream>
using namespace std;

int f(int n, int *sum)
{
    if (n == 0)
    {
        return n;
    }
    int rem = n % 10;
    *sum = *sum * 10 + rem;
    f(n / 10, sum);
    return *sum;
}

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int *ptr = &sum;
    cout << f(n, ptr) << endl;
    return 0;
}