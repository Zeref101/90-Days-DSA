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
    // * Static allocation

    Hero first;
    first.setHealth(40);
    cout << "Health of first hero: " << first.getHealth() << endl;
    ;

    // * Dynamic allocation

    Hero *b = new Hero;
    (*b).setHealth(100);
    (*b).setLevel('A');
    cout << "Hero 'b' health: " << (*b).getHealth() << endl;
    cout << "Hero 'b' level: " << (*b).getLevel();

    return 0;
}
```
* We can also call the functions for dynamic allocation using arrow operator '->'
```cpp
b->setHealth(100);
(*b).setLevel('A');
    cout << "Hero 'b' health: " << b->getHealth() << endl;
    cout << "Hero 'b' level: " << b->getLevel();
```
## OUTPUT
Health of first hero: 40
Hero 'b' health: 100
Hero 'b' level: A