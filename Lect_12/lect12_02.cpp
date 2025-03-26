#include <iostream>
#include <string>

int main() {
    std::string name = u8"Françoise"; // u8 designates UTF-8 string literal
    std::cout << "Hello, " << name << "!" << std::endl;

    return 0;
}
