A destructor is a special member function in C++ that is called automatically when an object is destroyed. It is used to release any resources that were allocated by the object during its lifetime.
```cpp
class MyClass {
public:
    MyClass() {
        // constructor code
    }
    ~MyClass() {
        // destructor code
    }
};

int main() {
    MyClass obj; // object created
    // do something with obj
    // object destroyed automatically when it goes out of scope
    return 0;
}
```
* In this example, the destructor is called automatically when the object  obj  goes out of scope at the end of the  main  function.
* Static calls to a destructor are automatically called when the program exits, while dynamic calls to a destructor must be called manually using the  delete  keyword. For example:
```cpp
MyClass* ptr = new MyClass(); // object created dynamically
// do something with ptr
delete ptr; // destructor called manually
```
* In this example, the destructor is called manually using the delete keyword when the object pointed to by ptr is no longer needed.