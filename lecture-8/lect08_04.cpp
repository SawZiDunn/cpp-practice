#include <iostream>
#include <vector>
#include <memory>

class MyArray {
private:
    std::vector<int> data;

public:
    // Constructor to initialize the array with a given size and default value
    MyArray(int size, int defaultValue = 0) : data(size, defaultValue) {}

    // Overload the subscript operator []
    int& operator[](size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Overload the function call operator ()
    int operator)((size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Example structure for demonstrating the arrow operator ->
    struct MyStruct {
        void print() const { std::cout << "MyStruct::print() called" << std::endl; }
    };

    // Overload the arrow operator ->
    MyStruct* operator->() const {
        static MyStruct example;
        return &example;
    }

    // Overload the copy assignment operator =
    MyArray& operator=(const MyArray& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }
    // Additional functionality for demonstration
    void print() const {
        for (auto val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyArray arr(5, 10); // Create an array of size 5, initialized to 10

    // Demonstrate subscript operator []
    std::cout << "Element at index 2: " << arr[2] << std::endl;

    // Demonstrate function call operator ()
    std::cout << "Element at index 2 using operator(): " << arr(2) << std::endl;

    // Demonstrate arrow operator ->
    arr->print(); // Calls MyStruct::print()

    // Demonstrate assignment operator =
    MyArray arr2(5);
    arr2 = arr; // Copy data from arr to arr2
    std::cout << "arr2 after assignment: ";
    arr2.print();

    return 0;
}
