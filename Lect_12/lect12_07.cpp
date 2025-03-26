#include <iostream>
using namespace std;
int main() {
    int character;
    cout << "Before input, cin.eof() is " << cin.eof() << "\n";
    cout << "Enter a sentence + Enter + EOF (Ctrl+Z on Win, Ctrl+D on Unix):\n";
    while ((character = cin.get()) != EOF) {
        cout.put(character);
    }
    cout << "\nEOF: " << character << ", cin.eof(): " << cin.eof() << endl;
}