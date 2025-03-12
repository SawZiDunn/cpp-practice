#include <iostream>
#include <cstring>
#include <string>
#include <limits>
using namespace std;

int main()
{
    string a;
    string b;

    cout << "String a: ";
    getline(cin, a);

    // no need to use this if we use getline
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "String b: ";
    getline(cin, b);

    cout << endl;

    cout << "a: " << a << endl;
    ;
    cout << "b: " << b;

    return 0;
}