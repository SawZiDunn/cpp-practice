#include<iostream>
using namespace std;

// scoped enum (enum class)
// do not implicitly convert to int. Explicit casting is required.

enum class Colour {
    RED,
    GREEN,
    BLUE
};


int main() {
    Colour colour = Colour::BLUE;

    int value = static_cast<int> (colour); // Colour::BLUE
    cout << value << endl; // 2

    switch (colour) {
        case Colour::BLUE:
            cout << "BLUE" << endl;
            break;
        case Colour::RED:
            cout << "RED" << endl;
            break;
        case Colour::GREEN:
            cout << "GREEN" << endl;
            break;
    }
 
    return 0;
}