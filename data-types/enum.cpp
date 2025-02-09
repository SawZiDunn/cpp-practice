#include<iostream>
using namespace std;

// unscoped enum (traditional enum)

// Enumerators are implicitly converted to int.
// Enumerators are in the global or enclosing namespace scope.
// The first item of enum has a value of 0 by default.
// We can also change it.

enum Status {
    PENDING = 25,
    COMPLETE, // 26
    NOT_STARTED // 27
};


int main() {
    Status status = COMPLETE;

    switch (status) {
        case 25:
            cout << "Task is pending!" << endl;
            break;
        case 26:
            cout << "Task is pending!" << endl;
            break;
        case 27:
            cout << "Task is pending!" << endl;
            break;
    }
        


 
    return 0;
}