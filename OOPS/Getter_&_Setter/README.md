```cpp
#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

public:
    // * properties
    char name[100];
    char level;

    int getHealth()
    {
        return health;
    }
    char getLevel()
    {
        return level;
    }
    void setHealth(int portion)
    {
        health = portion;
    }
    void setLevel(char l)
    {
        level = l;
    }
};

int main()
{
    Hero first;
    first.setHealth(40);
    cout << "Health of first hero: " << first.getHealth();
    return 0;
}
```
* In object-oriented programming, getter and setter methods are used to provide controlled access to the private members of a class.
* Getter methods are used to retrieve the value of a private member variable, while setter methods are used to modify the value of a private member variable.