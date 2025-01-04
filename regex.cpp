#include <iostream>
#include <regex>
using namespace std;

int main() {
    regex format("^[0-9]+$");
    string x = "5897456a";
    if (regex_match(x, format)) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }
    
    
}