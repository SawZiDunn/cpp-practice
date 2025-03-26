#include <iostream>

class Vector
{
public:
    int x, y;

    // Constructor to initialize vector
    Vector(int x, int y) : x(x), y(y) {}

    // // Overloading the + operator, other is the second vector
    // Vector operator+(const Vector &other) const
    // {
    //     return Vector(x + other.x, y + other.y); // Vector(v1.x + v2.x, v1.y + v2.y)
    // }

    // Overloading the + operator using friend
    friend Vector operator+(const Vector &v1, const Vector &v2);

    // Function to display the vector
    void display() const
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// if we use friend, implement it outside the class
// inside class is fine, but it violates the fact that it's not a member function
// it's a friend function that has access to private and protected attributes

Vector operator+(const Vector &v1, const Vector &v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y); // Vector(v1.x + v2.x, v1.y + v2.y)
}

int main()
{
    Vector v1(3, 4);
    Vector v2(1, 2);

    // Adding two vectors using the overloaded + operator
    Vector v3 = v1 + v2;

    // Displaying the results
    std::cout << "Vector 1: ";
    v1.display();
    std::cout << "Vector 2: ";
    v2.display();
    std::cout << "Vector 3 (v1 + v2): ";
    v3.display();

    return 0;
}