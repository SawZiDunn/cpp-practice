#include <iostream>
#include <limits>

using namespace std;

void clear_input_buffer();

int main()
{
    string name;
    int age;

    // If we us getline() after cin, that won't work.
    // So we need to ignore remaing buffer inside cin before using getline

    cout << "Age: ";
    cin >> age; // Reads an integer, leaving a newline in the buffer

    clear_input_buffer();

    cout << "Name: ";
    getline(cin, name); // Consumes leading whitespace and reads the full line

    cout << return 0;
}

void clear_input_buffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}