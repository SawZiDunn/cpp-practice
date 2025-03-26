#include <iostream>
#include <thread>
#include <functional> // For std::ref

void threadFunction(int& x) {
    ++x; // Modify the passed-in argument.
}

int main() {
    int value = 0;

    std::cout << "Value before thread execution: " << value << std::endl;
    std::thread t(threadFunction, std::ref(value)); // Pass value by reference to the thread
    t.join();
    std::cout << "Value after thread execution: " << value << std::endl; // Value should be 1
    return 0;
}
