#include <iostream>

using namespace std;

// Base class
class Shape
{
public:
    // Virtual function to enable polymorphism
    virtual void draw()
    {
        cout << "Drawing a generic shape..." << std::endl;
    }
};

// Derived class - Circle
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() override
    {
        cout << "Drawing a circle with radius " << radius << "." << endl;
    }

    void setRadius(double r)
    {
        radius = r;
    }

    double getArea() const
    {
        return 3.14 * radius * radius;
    }
};

// Derived class - Rectangle
class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : side(s) {}

    void draw() override
    {
        cout << "Drawing a square with side " << side << "." << endl;
    }

    void setSide(double s)
    {
        side = s;
    }

    double getArea() const
    {
        return side * side;
    }
};

int main()
{
    Shape *shape1 = new Circle(5.0); // Using Shape pointer for a Circle
    shape1->draw();                  // Drawing a circle with radius 5.0

    Shape *shape2 = new Square(4.0); // Using Shape pointer for a Square
    shape2->draw();                  // Drawing a square with side 4.0

    // cout << "Area of the shape2: " << shape2->getArea() << endl; // will throw error

    // Demonstrating additional behavior specific to the Circle
    Circle *circle = new Circle(3.0);
    circle->draw();                                              // Drawing a circle with radius 3.0
    cout << "Area of the circle: " << circle->getArea() << endl; // Additional behavior

    // Demonstrating additional behavior specific to the Square
    Square *square = new Square(2.0);
    square->draw();                                              // Drawing a square with side 2.0
    cout << "Area of the square: " << square->getArea() << endl; // Additional behavior

    delete shape1;
    delete shape2;
    delete circle;
    delete square;

    return 0;
}
