#include<iostream>
using namespace std;

int main() {
    // declaring an int array of length 5
    // length is mandatory
    int arr0[100];
    cout << arr0 << endl; // same address with &arr0[0]

    // fill(begin, end, value)
    // fille accepts memory address for begin and end value
    // end is exclusive
    fill(arr0, arr0 + 50, 50);
    fill(arr0 + 50, arr0 + 100, 100);

    // for each loop
    for (int i : arr0) {
        cout << i << endl;
    }

    // declaring and initializing an array
    // length can be omitted
    // int arr[] = {1, 2, 3, 4, 5};
    // string arr2[] = {"a", "sdfsdafdsaf", "adss", "asdasd"};
    // string x = "Hello World"; // takes 32 bytes of memory

    // cout << "Size of string x: " << sizeof(x) << endl;
    // cout << "Size of string: " << sizeof(string) << endl;
    // cout << "Size of arr2: " << sizeof(arr2) << endl;
    // cout << "Length of arr2: " << sizeof(arr2) / sizeof(arr2[0]) << endl;

 
    return 0;
}

void acceptArray()