#include <iostream>
#include <string>

using namespace std;

// Without explicit (allows implicit conversion)
// With explicit (prevents implicit conversion)
class Car
{
public:
    // using {} prevents narrowing conversions like double to int
    explicit Car(const string &name, int model) : name{name}, model(model) {}

private:
    string name;
    int model;
};

int main()
{
    Car new_car1{"Honda", 3};       // ok for with explicit or without explicit
    Car new_car2("Honda", 3);       // ok for with explicit or without explicit
    Car new_car3 = Car{"Honda", 3}; // ok
    Car new_car4 = { "Honda",
                     3 } // not ok since we cannot convert explicitly
}