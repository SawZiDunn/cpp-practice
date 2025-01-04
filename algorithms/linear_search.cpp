#include<iostream>
#include<string>

using namespace std;
int linear_search(string numbers[], string key, int size);

int main() {
    string numbers[] = {"abc", "def", "ghi", "jkl"};
    string key;
    cout << "Enter your key: ";
    cin >> key;

    int size = sizeof(numbers) / sizeof(numbers[0]);
    int result = linear_search(numbers, key, size);
    if (result == -1) {
        cout << "Not Found!" << endl;
    } else {
        cout << key << " is found at index " << result <<  endl;
    }
    
    return 0;
}

int linear_search(string numbers[], string key, int size) {
    // cout << "Size of numbers: " << sizeof(numbers) << endl;
    
    for (int i = 0; i < size; i++) {
        if (numbers[i] == key) {
            return i;
        }
    }
    return -1;

}