#include<iostream>

using namespace std;

int main() {
    string name;
    int age;

    // If we us getline() after cin, that won't work.
    // So we need to pass whitespace after cin argument inside getline.
    cout << "Age: ";
    cin >> age; // Reads an integer, leaving a newline in the buffer
    cout << "Name: ";
    getline(cin >> std::ws, name); // Consumes leading whitespace and reads the full line
    return 0;
}