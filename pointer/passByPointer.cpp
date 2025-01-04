// Example program
#include <iostream>
using namespace std;

void passByPointer(int *x);
int main()
{
    int x = 2;
    passByPointer(&x);
    cout << x << endl;
     
}

void passByPointer(int *x) {
    // cout << x << endl;
    (*x)++;
}