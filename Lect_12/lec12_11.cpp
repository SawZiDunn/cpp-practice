#include <iostream>
#include <iomanip> // Required for manipulators like setprecision, setw, setfill
using namespace std;

int main() {
    cout << "Demonstrating various stream manipulators:" << endl;

    // Setting field widths
    cout << "Field width of 10: |" << setw(10) << 123 << "|" << endl;

    // Setting precision for floating-point numbers
    cout << "Precision of 3 for floating-point numbers: " << setprecision(3) << 3.14159 << endl;

    // Setting and unsetting format state (hexadecimal)
    cout << "Hexadecimal format: " << hex << 255 << endl;
    cout << "Decimal format: " << dec << 255 << endl;

    // Setting the fill character in fields
    cout << "Field width of 10 with fill character '-': |" << setfill('-') << setw(10) << 123 << "|" << endl;

    // Flushing streams
    cout << "This is flushed immediately" << flush;

    // Inserting a newline into the output stream (and flushing the stream)
    cout << "This is on a new line" << endl;

    // Inserting a null character into the output stream
    cout << "Null character insertion->" << '\0' << "<-End" << endl;

    // Skipping white space in the input stream
    cout << "Enter a number followed by a string (with spaces): ";
    int num;
    string str;
    cin >> num; // Reads and discards leading white space
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip to the next line
    getline(cin, str); // Now read the string
    cout << "You entered number: " << num << " and string: " << str << endl;

    return 0;
}
