#include<iostream>
#include<string>

using namespace std;

int addEvenDigits(string x);
int addOddDigits(string x);
int addDigits(int x);

// Luhn algorithm
int main() {
    string number;
    cout << "Enter Card Number: ";
    getline(cin, number);
    int total = addOddDigits(number) + addEvenDigits(number);
    cout << total << endl;

    if (total % 10 == 0) {
        cout << "Valid!"<< endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}

// add evenDigits from right to left
int addEvenDigits(string x) {
    int total = 0;
    for (int i = x.size() - 2; i >= 0; i -=2) {
        total += addDigits((x[i] - '0') * 2);
    }

    return total;

}

int addDigits(int x) {
    // add single digits form an integer
    // eg. 512 -> 5 + 1 + 2 = 8
    int total = 0;
    while (x % 10 != 0) {
        total += x % 10;
        x /= 10;
    }

    return total;

}

// add odd digits from right to left
int addOddDigits(string x) {

    int total = 0;
    for (int i = x.size() - 1; i >= 0; i -= 2) {
        // We can either substract '0' or 48 from a character to convert it to an integer
        // The ASCII value of '0' is 48 in decimal value.
        total += x[i] - '0'; // - 48

    }
    return total;

}