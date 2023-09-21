#include <iostream>
using namespace std;

int f(int n, int sum)
{
    if (n == 1)
    {
        return n;
    }
    sum += n + f(n - 1, sum);
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << f(n, 0);
    return 0;
}