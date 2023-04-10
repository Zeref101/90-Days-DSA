A copy constructor is a special constructor in C++ that creates a new object as a copy of an existing object. The copy constructor takes an object of the same class as a parameter and creates a new object with the same values as the parameter object.
```cpp
#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Constructor with parameters
    Person(string n, int a) {
        name = n;
        age = a;
    }

    // Copy constructor
    Person(const Person& p) {
        name = p.name;
        age = p.age;
    }
};

int main() {
    // Create an instance of the Person class using the constructor with parameters
    Person p1("Alice", 25);

    // Create a new instance of the Person class as a copy of p1 using the copy constructor
    Person p2 = p1;

    // Print the values of the member variables
    cout << "Name: " << p1.name << ", Age: " << p1.age << endl;
    cout << "Name: " << p2.name << ", Age: " << p2.age << endl;

    return 0;
}
```