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
The size we think is 105 bytes but in the print statement we get 108 bytes this is because of padding and greedy alignement