#include <iostream>

class MyClass
{
public:
    int *data;

    MyClass(int value)
    {
        data = new int(value); // data point to address of int
    }

    // Deep copy assignment operator
    MyClass &operator=(const MyClass &other)
    {
        if (this != &other) // prevents self-assignment
        {
            delete data; // Avoid memory leak
            data = new int(*other.data);
        }

        return *this;
    }

    ~MyClass() { delete data; }
};

int main()
{
    // Create two MyClass objects
    MyClass obj1(5);
    MyClass obj2{10};

    // Print initial values
    std::cout << "obj1.data: " << *(obj1.data) << std::endl; // Output: 5
    std::cout << "obj2.data: " << *obj2.data << std::endl;   // Output: 10

    // Perform deep copy assignment
    obj1 = obj2;

    // Print values after assignment
    std::cout << "obj1.data after assignment: " << *obj1.data << std::endl; // Output: 10
    std::cout << "obj2.data after assignment: " << *obj2.data << std::endl; // Output: 10

    return 0;
}