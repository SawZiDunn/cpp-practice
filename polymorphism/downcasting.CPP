#include <iostream>
#include <typeinfo>

class Shape
{
public:
    virtual double getArea() const { return 0.0; } // Virtual function for polymorphism
    virtual ~Shape() = default;                    // Virtual destructor
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override { return 3.14159 * radius * radius; }
    void setRadius(double r) { radius = r; } // Circle-specific method
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : side(s) {}
    double getArea() const override { return side * side; }
};

int main()
{
    // Create a Circle object and store it as a Shape pointer (upcasting, automatic)
    Shape *shapePtr = new Circle(5);

    // Try to downcast shapePtr to Circle* using dynamic_cast
    Circle *circlePtr = dynamic_cast<Circle *>(shapePtr);

    if (circlePtr)
    { // Check if the cast succeeded
        std::cout << "Successfully downcast to Circle. Area: " << circlePtr->getArea() << std::endl;
        circlePtr->setRadius(10); // Access Circle-specific method
        std::cout << "New area after setting radius to 10: " << circlePtr->getArea() << std::endl;
    }
    else
    {
        std::cout << "Downcasting failed—shapePtr is not a Circle." << std::endl;
    }

    // Now try with a Square object to show failure
    delete shapePtr; // Clean up the Circle
    shapePtr = new Square(4);

    // square obj to shape ptr -> shapePtr to circle ptr, err
    circlePtr = dynamic_cast<Circle *>(shapePtr);
    if (circlePtr)
    {
        std::cout << "Successfully downcast to Circle." << std::endl;
    }
    else
    {
        std::cout << "Downcasting failed—shapePtr is a Square, not a Circle." << std::endl;
    }

    delete shapePtr; // Clean up the Square
    return 0;
}