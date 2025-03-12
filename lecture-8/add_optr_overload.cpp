#include <iostream>

class Vector
{
public:
    int x, y;

    // Constructor to initialize vector
    Vector(int x, int y) : x(x), y(y) {}

    // Overloading the + operator
    Vector operator+(const Vector &other) const
    {
        return Vector(x + other.x, y + other.y); // Vector(v1.x + v2.x, v1.y + v2.y)
    }

    // Function to display the vector
    void display() const
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

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