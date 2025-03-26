#include <iostream>

class Base {
public:
    int publicVar;

    Base() : publicVar(1), privateVar(2), protectedVar(3) {}

    void showAccess() {
        std::cout << "Base class access:\n";
        std::cout << "PublicVar: " << publicVar << std::endl;
        std::cout << "PrivateVar: " << privateVar << std::endl; // Accessible
        std::cout << "ProtectedVar: " << protectedVar << std::endl; // Accessible
    }

private:
    int privateVar;

protected:
    int protectedVar;
};

class Derived : public Base {
public:
    void showAccess() {
        std::cout << "Derived class access:\n";
        std::cout << "PublicVar: " << publicVar << std::endl; // Accessible
        //std::cout << "PrivateVar: " << privateVar << std::endl; // Not accessible, will cause a compile error
        std::cout << "ProtectedVar: " << protectedVar << std::endl; // Accessible
    }
};

int main() {
    Base baseObj;
    baseObj.showAccess(); // Can access public and private members within the class

    Derived derivedObj;
    derivedObj.showAccess(); // Can access public and protected members in the derived class

    std::cout << "From main:\n";
    std::cout << "PublicVar: " << baseObj.publicVar << std::endl; // Accessible
    // std::cout << "PrivateVar: " << baseObj.privateVar << std::endl; // Not accessible, will cause a compile error
    // std::cout << "ProtectedVar: " << baseObj.protectedVar << std::endl; // Not accessible, will cause a compile error

    return 0;
}
