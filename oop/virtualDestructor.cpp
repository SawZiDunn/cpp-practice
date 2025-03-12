#include <iostream>

using namespace std;

class Animal
{
public:
    Animal() {}

    /*virtual destructor ensures child class's destructor is also called when
    parent class pointer is deleted manually when it's allocated on heap with 'new'.
    if allocated on stack, both parent, child destructors are called, virtual destuctor is useless.
    */

    virtual ~Animal()

    {
        cout << "Animal Destructor called" << endl;
    }

    virtual void speak()
    {
    }
};

class Dog : public Animal
{
public:
    Dog() : Animal{} {}

    ~Dog()
    {
        cout << "Dog Destructor called!" << endl;
    }

    void speak() override
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    // Dog dog{};
    Animal *animal = new Dog(); // &dog
    delete animal;

    return 0;
}