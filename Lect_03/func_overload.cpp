#include <iostream>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Overloaded function to add two doubles
double add(double a, double b) {
    return a + b;
}

// Overloaded function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    std::cout << "Adding two integers: " << add(1, 2) << std::endl;      // Calls int add(int, int)
    std::cout << "Adding two doubles: " << add(1.5, 2.3) << std::endl;  // Calls double add(double, double)
    std::cout << "Adding three integers: " << add(1, 2, 3) << std::endl;// Calls int add(int, int, int)

    return 0;
}
