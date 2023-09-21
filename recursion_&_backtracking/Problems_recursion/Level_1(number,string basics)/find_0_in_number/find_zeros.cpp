#include <iostream>
using namespace std;

int f(int n, int &count)
{
    if (n == 0)
    {
        return 0;
    }
    int temp = n % 10;
    if (temp == 0)
    {
        count++;
    }
    f(n / 10, count);
    return count;
}

int main()
{
    int n;
    cin >> n;
    int count = 0;
    cout << f(n, count) << endl;
    return 0;
}