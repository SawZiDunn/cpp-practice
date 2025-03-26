#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base class constructor called." << std::endl;
    }
    ~Base() {
        std::cout << "Base class destructor called." << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived class constructor called." << std::endl;
    }
    ~Derived() {
        std::cout << "Derived class destructor called." << std::endl;
    }
};

int main() {
    std::cout << "Creating an object of Derived class." << std::endl;
    Derived obj;
    std::cout << "Object of Derived class is going out of scope." << std::endl;
    return 0;
}
