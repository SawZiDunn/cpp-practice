#include <iostream>
using namespace std;

int main() {
    int i = 0;
    
    // preincrement
    // Increments the value of r before it is used in the expression.
    // The updated value of r is returned.
    cout << ++i << endl; // 1
    cout << i << endl; // 1
    
    i = 0;
    // postincrement
    // Increments the value of r after it is used in the expression.
    // The original value of r is returned, and the increment occurs afterward.
    // Typically involves creating a temporary variable to store the current value of i before incrementing.

    cout << i++ << endl; // 0
    cout << i << endl; // 1

    return 0;
    
}