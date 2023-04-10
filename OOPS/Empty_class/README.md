```cpp
#include <iostream>
using namespace std;

class Hero
{
public:
    // * properties
    char name[100];
    int health;
    char level;
};

int main()
{
    Hero first;
    cout << "size: " << sizeof(first.level);
    return 0;
}
```