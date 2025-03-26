#include <iostream>
#include <iomanip> // For formatting manipulators

using namespace std;

int main() {
    int integerValue = 1000;
    double doubleValue = 0.0947628;

    // ----- Display Original Format -----
    cout << "Original Format:\n";
    cout << "Flags: " << cout.flags() << endl; // Display current flags
    cout << "Values: " << integerValue << '\t' << doubleValue << endl; 

    // ----- Modify Formatting -----
    ios_base::fmtflags originalFormat = cout.flags(); // Store original state

    cout << "\nModified Format:\n";
    cout << "Original Flags: " << cout.flags() << endl; // Show flags before modification
    cout << showbase << oct << scientific;  // Set new formatting options
    cout << "Values: " << integerValue << '\t' << doubleValue << endl; 
    cout << "Modified Flags: " << cout.flags() << endl; // Show flags before modification

    // ----- Restore Original Formatting -----
    cout.flags(originalFormat); // Restore original format

    cout << "\nRestored Format:\n";
    cout << "Flags: " << cout.flags() << endl; 
    cout << "Values: " << integerValue << '\t' << doubleValue << endl; 

    return 0;
}
