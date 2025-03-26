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

    virtual ~Animal() // virtual destructor for proper clean up

    {
        cout << "Animal Destructor called" << endl;
    }

    virtual void speak()
    {
        cout << "Some generic animal sound" << endl;
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

    // override virtual function from base class

    void speak() override
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    // Dog dog{};
    // base class pointer pointing to child class object
    Animal *animal = new Dog(); // &dog
    animal->speak();            // calls Dog::speak(), not Animal::speak() due to polymorphism
    delete animal;

    return 0;
}