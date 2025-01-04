#include <iostream>

using namespace std;
void passByValue(int x);
void passByReference(int &x);

int main() {
    int x = 1;
    passByValue(x);
    
    cout << "pass by value: " << x << endl;
    passByReference(x);
    cout << "pass by reference" << x << endl;


    return 0;
}

void passByValue(int x) {
    x++;
}

// accepts the reference of the variable
// We can use const to prevent modifying the variable
void passByReference(int &x) {
    x++;
}