#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    virtual void speak()
    { // Virtual function for polymorphism
        cout << "I am a Base object" << endl;
    }
    void commonFunction()
    { // Common function in the base class
        cout << "Common function in Base" << endl;
    }
    virtual ~Base() {} // Virtual destructor for safe deletion
};

// Derived class
class Derived : public Base
{
public:
    void speak() override
    { // Override the virtual function
        cout << "I am a Derived object" << endl;
    }
    void derivedFunction()
    { // Derived-class-specific function
        cout << "Derived-specific function" << endl;
    }
};

int main()
{
    // Create a Derived object
    Derived derivedObj;

    // Create a base-class pointer and assign it the address of the derived object
    Base *basePtr = &derivedObj; // Safe and common practice

    // Use the base-class pointer to access common members and virtual functions
    basePtr->commonFunction(); // Calls Base::commonFunction() ("Common function in Base")
    basePtr->speak();          // Calls Derived::speak() due to polymorphism ("I am a Derived object")

    // The base-class pointer cannot directly access derived-class-specific functions
    // basePtr->derivedFunction();  // Compilation error: 'derivedFunction' is not a member of 'Base'

    // To access derivedFunction, cast the pointer to Derived*
    // downcasting
    Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);
    if (derivedPtr)
    {
        derivedPtr->derivedFunction(); // Now works: "Derived-specific function"
    }

    return 0;
}