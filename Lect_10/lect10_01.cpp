// Multiple Inheritance 
#include <iostream>
using namespace std;

// Base Class 1: Flyable
class Flyable {
public:
    void fly() {
        cout << "I can fly!" << endl;
    }
};

// Base Class 2: Swimmable
class Swimmable {
public:
    void swim() {
        cout << "I can swim!" << endl;
    }
};

// Derived Class: Duck (inherits from both Flyable and Swimmable)
class Duck : public Flyable, public Swimmable {
public:
    void quack() {
        cout << "Quack! Quack!" << endl;
    }
};

int main() {
    // Create an object of the Duck class
    Duck duck;

    // Call methods inherited from Flyable and Swimmable
    duck.fly();   // Output: I can fly!
    duck.swim();  // Output: I can swim!

    // Call a method specific to the Duck class
    duck.quack(); // Output: Quack! Quack!

    return 0;
}
