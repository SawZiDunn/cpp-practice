#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> myList = {"hello", "remove", "world", "remove", "example"};

    std::cout << "Original list: ";
    for (const auto& str : myList) {
        std::cout << str << " ";
    }
    std::cout << "\n";

    // Using remove_if to remove strings that are "remove"
    myList.remove_if([](const std::string& s) { return s == "remove"; });

    std::cout << "List after removing 'remove': ";
    for (const auto& str : myList) {
        std::cout << str << " ";
    }
    std::cout << "\n";

    return 0;
}
