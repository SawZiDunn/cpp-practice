#include <iostream>
using namespace std;

int main() {
    const int SIZE = 80;
    char buffer[SIZE]; // Create an array of 80 characters

    cout << "Enter a sentence:\n";
    cin.read(buffer, 30);  // Use function read to input characters into buffer

    // Use functions write and gcount to display buffer characters
    cout << "\ngcount= " << cin.gcount() << endl;
    cout << "buffer = " << buffer << endl;
    cout.write(buffer, cin.gcount()+20);
    cout << endl;

    return 0;
}
