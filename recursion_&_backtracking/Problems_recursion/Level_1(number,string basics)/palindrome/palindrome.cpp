#include <iostream>
#include <string>
using namespace std;

string f(string n)
{
    if (n.size() == 0)
    {
        return "";
    }
    return n[n.size() - 1] + f(n.substr(0, n.size() - 1));
}

int main()
{
    string n;
    cin >> n;
    string str = f(n);
    cout << str << endl;

    return 0;
}
