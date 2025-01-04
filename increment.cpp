#include <iostream>
using namespace std;

int main() {
    int r = 0;
    
    // preincrement
    // Increments the value of r before it is used in the expression.
    // The updated value of r is returned.
    cout << ++r << endl; // 1
    cout << r << endl; // 1
    
    r = 0;
    // postincrement
    // Increments the value of r after it is used in the expression.
    // The original value of r is returned, and the increment occurs afterward.
    cout << r++ << endl; // 0
    cout << r << endl; // 1

    return 0;
    
}