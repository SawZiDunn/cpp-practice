#include <iostream>
using namespace std;

// static polymorphism

// Function to add two integers
int add(int a, int b)
{
    return a + b;
}

// Overloaded function to add two doubles
double add(double a, double b)
{
    return a + b;
}

// Overloaded function to add three integers
int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    cout << "Sum of 2 and 3: " << add(2, 3) << endl;         // Calls the first function
    cout << "Sum of 1.1 and 2.2: " << add(1.1, 2.2) << endl; // Calls the second function
    cout << "Sum of 1, 2, and 3: " << add(1, 2, 3) << endl;  // Calls the third function
    return 0;
}
