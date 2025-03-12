#include <iostream>
#include <string>
#include <iomanip>

// Define the PhoneNumber class
class PhoneNumber {
public:
    friend std::ostream& operator<<(std::ostream& output, const PhoneNumber& number);
    friend std::istream& operator>>(std::istream& input, PhoneNumber& number);

private:
    std::string areaCode; // 3-digit area code
    std::string exchange; // 3-digit exchange
    std::string line; // 4-digit line
};

// Overloaded stream insertion operator; must use std::ostream
std::ostream& operator<<(std::ostream& output, const PhoneNumber& number) {
    output << "Area code: " << number.areaCode << "\nExchange: "
           << number.exchange << "\nLine: " << number.line << "\n"
           << "(" << number.areaCode << ") " << number.exchange << "-"
           << number.line << "\n";
    return output;
}

// Overloaded stream extraction operator; must use std::istream
std::istream& operator>>(std::istream& input, PhoneNumber& number) {
    input.ignore(); // skip (
    input >> std::setw(3) >> number.areaCode; // input area code
    input.ignore(2); // skip ) and space
    input >> std::setw(3) >> number.exchange; // input exchange
    input.ignore(); // skip dash (-)
    input >> std::setw(4) >> number.line; // input line
    return input;
}

int main() {
    PhoneNumber phone; // create object phone

    std::cout << "Enter phone number in the form (555) 555-5555:" << std::endl;
    
    // Read in the phone number with cin
    std::cin >> phone;

    std::cout << "\nThe phone number entered was:\n";

    // Output the phone number with cout
    std::cout << phone;

    return 0;
}
