#include <iostream>
#include <string>

using namespace std;

int main() {
    const int SIZE = 80;

    string buffer1;
    char buffer2[SIZE];

    cout << "Enter a sentence:\n";

    // Use getline to read a full line with spaces
    getline(cin, buffer1);

    cout << "\nThe string read with getline was:\n" << buffer1 << "\n\n";

    // Optionally clear input buffer before using cin.get
    cin.ignore();

    // Use cin.get to read up to a specified number of characters
    cin.get(buffer2, SIZE - 1); // Leave space for null-terminator

    cout << "The string read with cin.get was:\n" << buffer2 << endl;

    return 0;
}
