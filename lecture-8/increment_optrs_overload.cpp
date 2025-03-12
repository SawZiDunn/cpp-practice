#include <iostream>

class Counter {
private:
    int value;

public:
    Counter() : value(0) {}

    Counter(int initialValue) : value(initialValue) {}

    // Overload the prefix increment operator
    Counter& operator++() {   
        value+=2;
        return *this;   // this is a pointer that refers to the current object instance of a class
    }

    // Overload the postfix increment operator
    Counter operator++(int) {  
        Counter temp = *this;
        value+=2;
        return temp;
    }

    // Overload the prefix decrement operator
    Counter& operator--() {
        value-=2;
        return *this;
    }

    // Overload the postfix decrement operator
    Counter operator--(int) {
        Counter temp = *this;
        value-=2;
        return temp;
    }

    // Friend function to output the value of the Counter
    friend std::ostream& operator<<(std::ostream& os, const Counter& counter) {
        os << counter.value;
        return os;
    }
};

int main() {
    Counter count(10);

    std::cout << "Initial value: " << count << std::endl;

    // Use the overloaded prefix increment
    ++count;
    std::cout << "After prefix increment: " << count << std::endl;

    // Use the overloaded postfix increment
    count++;
    std::cout << "After postfix increment: " << count << std::endl;

    // Use the overloaded prefix decrement
    --count;
    std::cout << "After prefix decrement: " << count << std::endl;

    // Use the overloaded postfix decrement
    count--;
    std::cout << "After postfix decrement: " << count << std::endl;

    return 0;
}
