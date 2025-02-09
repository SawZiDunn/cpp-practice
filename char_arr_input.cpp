#include <iostream>
#include <cstring>
#include <string>
#include <limits>
using namespace std;

int main()
{
    char a[5];
    char b[5];

    cout << "String a: ";
    cin.getline(a, 5);

    if (cin.fail()) // checks if the previous cin was successful or not
    {
        cin.clear(); // clear error flags after input failed
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover input before the next one

    cout << "String b: ";
    cin.getline(b, 5);

    cout << "\n";

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}
