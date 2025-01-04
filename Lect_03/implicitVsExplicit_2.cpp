#include <iostream>

class MyClass {
private:
    int value;

public:
    // Constructor that initializes 'value' with 'x'
    explicit MyClass(int x) : value(x) {

    }

    // A member function to display 'value'
    void displayValue() const {
        std::cout << "Value: " << value << std::endl;
    }
};

// Function that takes 'MyClass' object as parameter
void someFunction(MyClass obj) {
    std::cout << "Inside someFunction: ";
    obj.displayValue();
}

int main() {
    // This will implicitly convert 10 to MyClass and call someFunction
    // But, it's not allowed for explicit constructors.
    // someFunction(10);

    // This is explicit conversion.
    someFunction(MyClass(10));

    return 0;
}