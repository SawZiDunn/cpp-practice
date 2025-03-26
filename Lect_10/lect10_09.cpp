#include <iostream>

class Base {
public:
    int publicMember = 1;

protected:
    int protectedMember = 2;

private:
    int privateMember = 3;

    // Friend function to demonstrate access to Base's private member
    friend void accessBasePrivateMember(Base& b);
};

// Function to access Base's private member
void accessBasePrivateMember(Base& b) {
    std::cout << "Accessing Base privateMember: " << b.privateMember << std::endl;
}

class DerivedPublic : public Base {
public:
    void accessMembers() {
        std::cout << "DerivedPublic accessing publicMember: " << publicMember << std::endl;        // Accessible
        std::cout << "DerivedPublic accessing protectedMember: " << protectedMember << std::endl;  // Accessible
        // std::cout << "DerivedPublic accessing privateMember: " << privateMember << std::endl;  // Not Accessible
    }
};

class DerivedProtected : protected Base {
public:
    void accessMembers() {
        std::cout << "DerivedProtected accessing publicMember: " << publicMember << std::endl;        // Accessible as protected
        std::cout << "DerivedProtected accessing protectedMember: " << protectedMember << std::endl;  // Accessible
        // std::cout << "DerivedProtected accessing privateMember: " << privateMember << std::endl;  // Not Accessible
    }
};

class DerivedPrivate : private Base {
public:
    void accessMembers() {
        std::cout << "DerivedPrivate accessing publicMember: " << publicMember << std::endl;        // Accessible as private
        std::cout << "DerivedPrivate accessing protectedMember: " << protectedMember << std::endl;  // Accessible as private
        // std::cout << "DerivedPrivate accessing privateMember: " << privateMember << std::endl;  // Not Accessible
    }
};

int main() {
    Base base;
    DerivedPublic derivedPublic;
    DerivedProtected derivedProtected;
    DerivedPrivate derivedPrivate;

    std::cout << "Accessing Base publicMember from main: " << base.publicMember << std::endl; // Accessible
    //std::cout << "Accessing Base protectedMember from main: " << base.protectedMember << std::endl;
    derivedPublic.accessMembers();
    derivedProtected.accessMembers();
    derivedPrivate.accessMembers();

    // Accessing Base's private member through a friend function
    accessBasePrivateMember(base);

    return 0;
}