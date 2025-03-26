// Nested Class
#include <iostream>

class Base {
private:
    int privateVar = 10;

protected:
    int protectedVar = 20;

public:
    int publicVar = 30;

    // Declare a forward declaration of the Derived class
    class Derived;

    // Declare the Derived class as a friend
    friend class Derived;
};

// Definition of the Derived class
class Base::Derived : public Base {
public:
    void accessBaseMembers() {
        // Can access Base's private and protected members due to friend declaration
        std::cout << "Base PrivateVar: " << privateVar << std::endl;
        std::cout << "Base ProtectedVar: " << protectedVar << std::endl;
        std::cout << "Base PublicVar: " << publicVar << std::endl;
    }
};

int main() {
    Base::Derived derivedObj;
    derivedObj.accessBaseMembers();  // Access private, protected, and public members of Base

    return 0;
}
