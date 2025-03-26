#include <iostream>
using namespace std;

// Forward declaration of the friend function
void friendFunction();

class Base {
private:
    int privateMember;  // Private member, accessible only within the class

public:
    Base() : privateMember(42) {}  // Constructor initializes privateMember

    // Member function to access private member
    void displayPrivateMember() {
        cout << "Private member (inside class): " << privateMember << endl;
    }

    // Declare a friend function
    friend void friendFunction(Base& obj);

    // Declare a friend class
    friend class FriendClass;
};

// Definition of the friend function
void friendFunction(Base& obj) {
    // Accessing the private member of Base from a friend function
    cout << "Private member (in friend function): " << obj.privateMember << endl;
}

// Definition of a friend class
class FriendClass {
public:
    void accessPrivateMember(Base& obj) {
        // Accessing the private member of Base from a friend class
        cout << "Private member (in friend class): " << obj.privateMember << endl;
    }
};

int main() {
    Base b;

    // Accessing private member through a member function of the class
    b.displayPrivateMember();

    // Accessing private member through a friend function
    friendFunction(b);

    // Accessing private member through a friend class
    FriendClass fc;
    fc.accessPrivateMember(b);

    // The following line would cause a compilation error because privateMember is not accessible outside the class
    // cout << b.privateMember << endl;

    return 0;
}