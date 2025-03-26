// Base Class Cpointer
#include <iostream>
#include <cmath> // For M_PI and pow
using namespace std;

// Base class with virtual functions for polymorphism
class Shape {
public:
    virtual double getArea() const = 0; // Pure virtual function (abstract base class)
    virtual ~Shape() {} // Virtual destructor for safe deletion
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return M_PI * pow(radius, 2); // Area = πr²
    }
};

// Derived class: Square
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}
    double getArea() const override {
        return side * side; // Area = side²
    }
};

// Function to print area using a base class pointer
void printArea(Shape* shape) {
    cout << "Area: " << shape->getArea() << endl;
}

int main() {
    // Create derived class objects
    Circle circle(5);  // Circle with radius 5
    Square square(4);  // Square with side 4

    // Use base class pointer to call printArea for different shapes (polymorphism)
    printArea(&circle);  // Works! Prints area of circle
    printArea(&square);  // Works too! Prints area of square

    // Demonstration of unsafe practice (commented out to avoid errors)
    /*
    Shape baseShape;  // Base class object
    Square* unsafePtr = &baseShape;  // Unsafe: trying to point a derived pointer at a base object
    // This would be dangerous because baseShape doesn’t have Square-specific members or behavior.
    // Uncommenting this could lead to undefined behavior or crashes if you tried to use Square-specific functionality.
    */

    return 0;
}