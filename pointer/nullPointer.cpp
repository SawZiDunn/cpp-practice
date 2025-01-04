#include<iostream>
using namespace std;

int main(){
    int i = 45;
    // int *ptr = &i;
    // or
    int *ptr = nullptr;
    ptr = &i;
    
    // We need to be carefult to not dereference a null pointer
    // that will cause undefined behaviour

    if (ptr == nullptr) {
        cout << "Assignment Failed!" << endl;
    } else {
        cout << *ptr << endl;
    }

    return 0;
}