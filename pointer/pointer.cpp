#include<iostream>
using namespace std;

int main(){
    int age = 20;
    int *p = &age; // stores the reference of variable age

    cout << "Memory address of the age variable is " << &age << endl;
    cout << "Memory address of the age variable is " << p << endl;

    // use *p to get the actual value, i.e, tha value the pointer is pointing
    cout << "The value of the pointer variable p " << *p << endl;

    cout << "The value of age is " << *p << endl;
    
    return 0;
}