Using the  this  keyword in a constructor allows you to refer to the current object being created. Here is an example of a class with a parameterized constructor that uses the  this  keyword:  
```cpp
#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Parameterized constructor using this keyword
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

int main() {
    // Create an instance of the Person class using the parameterized constructor
    Person p("Alice", 25);

    // Print the values of the member variables
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;

    return 0;
}
```
* In this example, the  Person  class has a parameterized constructor that takes two parameters:  name  and  age . The constructor uses the  this  keyword to refer to the current object being created and initializes the  name  and  age  member variables with the values of the parameters.
* In the  main  function, an instance of the  Person  class is created using the parameterized constructor. The values of the member variables are then printed to the console using  cout . Since values were passed to the constructor, the member variables are initialized with those values.