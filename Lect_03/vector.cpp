#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec{10,20,30,40,50};

    // Access elements
    std::cout << "First element: " << vec.front() << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    // Size and capacity
    std::cout << "Size: " << vec.size() << std::endl;

    // Check if the vector is empty
    if (!vec.empty()) {
        std::cout << "Vector is not empty" << std::endl;
    }

    // Push an element to the vector
    // vec.push_back(25);

    // Remove the last element
    vec.pop_back();

    // Iterate over the vector
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << "Element at index " << i << ": " << vec[i] << std::endl;
    }

    // vec.begin() returns the reference to the first index of the vector
    for (auto i = vec.begin(); i < data.end(); i++){
        cout<< *i << " "<<endl;
    }

    // Range-based for loop 
    for (int element : vec) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    // at
    std::cout << "Element at index 2: " << vec.at(2) << std::endl;

    // Reserve space for 10 elements
    vec.reserve(10);

    // Clear the vector
    vec.clear();
    std::cout << "Vector cleared. Size: " << vec.size() << std::endl;

    return 0;
}
