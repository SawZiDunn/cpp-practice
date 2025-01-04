// Example program
#include <iostream>
using namespace std;

void passByReference(int &x);
int main()
{
    int x = 2;
    passByReference(x);
    cout << x << endl; // 3
     
}

void passByReference(int &x) {
    // cout << x << endl;
    x++;
}