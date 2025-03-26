#include <iostream>

class Base {
public:
    virtual ~Base() { // Virtual destructor
        std::cout << "Base class destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived class destructor" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b; // First calls Derived's destructor, then Base's destructor

    return 0;
}
