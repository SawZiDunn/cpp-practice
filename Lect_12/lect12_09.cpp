#include <iostream>
using namespace std;
int main() {
    cout << "Type some text: ";
    char c = cin.peek();      // Look ahead
    cout << "Next char: " << c << "\n";
    cin.get(c);               // Extract it
    cin.putback(c);           // Put it back
    cin.ignore(2);            // Skip 2 chars
    cin.get(c);               // Get next
    cout << "After skip: " << c << endl;
}