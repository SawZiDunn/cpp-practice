#include <iostream>
using namespace std;

class Point
{
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload the + operator to add two Point objects.
    Point operator+(Point p)
    {
        Point temp;
        // this - right, p left of +
        temp.x = this->x + p.x;
        temp.y = this->y + p.y;
        return temp;
    }
};

int main()
{
    Point p1(10, 5), p2(2, 4);
    Point p3 = p1 + p2; // Calls the overloaded + operator : p1.operator+(p2)
    cout << "Sum of points: (" << p3.x << ", " << p3.y << ")" << endl;
    return 0;
}
