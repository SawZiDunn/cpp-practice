#include <iostream>
#include <list>

// Function that prints all elements in the list
void printList(const std::list<int>& lst) {
    for (int element : lst) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

int main() {
    // Creating a list of integers
    std::list<int> myList = {1, 2, 3, 4, 5};

    std::cout << "Original list: ";
    printList(myList);

    // Adding elements to the list
    myList.push_front(0); // Add at the beginning
    myList.push_back(6);  // Add at the end

    std::cout << "List after adding elements: ";
    printList(myList);

    // Removing elements from the list
    myList.pop_front();  // Remove from the beginning
    myList.pop_back();   // Remove from the end

    std::cout << "List after removing elements: ";
    printList(myList);

    return 0;
}
