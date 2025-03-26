#include <iostream>
using namespace std;
int main() {
    char buffer1[80], buffer2[80];
    cout << "Enter a sentence:\n";
    cin >> buffer1;             // Stops at whitespace
    cin.ignore(1000, '\n');     // Clear buffer
    cin.get(buffer2, 80);       // Reads until newline
    cout << "cin: " << buffer1 << "\n";
    cout << "cin.get: " << buffer2 << endl;
}
