//Derived-Class Member-Function Calls via Base-Class Pointers
#include <iostream>

class Base {
public:
    virtual void print() const { std::cout << "Base class print function" << std::endl; }
    virtual ~Base() {} // Virtual destructor for safe polymorphic deletion
};

class Derived : public Base {
public:
    void print() const override { std::cout << "Derived class print function" << std::endl; }
    void specificFunction() const { std::cout << "Function specific to Derived class" << std::endl; }
};

int main() {
    Base* basePtr = new Derived; // Base class pointer pointing to a derived class object

    basePtr->print(); // Calls Derived::print(), thanks to virtual function mechanism

    // To call a function specific to the Derived class, you need to safely downcast the pointer
    auto derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->specificFunction(); // Safe, as we've ensured the pointer actually points to a Derived object
    }

    delete basePtr; // Safe deletion due to virtual destructor in Base
    return 0;
}
