#include<iostream>
using namespace std;


int main() {
    int factor{3};
    // capture by reference
    auto multiply = [&factor] (int x) -> int {
        return x * factor;
    };

    factor = 5;
    cout << multiply(3) << endl; // 15


 
    return 0;
}