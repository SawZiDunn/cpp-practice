#include<iostream>
using namespace std;

template <typename T>
T multiply(T a, T b);


int main() {
    cout << multiply('5', '6') << endl;
    return 0;
}

template <typename T>
T multiply(T a, T b) {
    return a > b ? a : b;
}