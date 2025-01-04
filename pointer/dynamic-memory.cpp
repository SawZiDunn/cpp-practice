#include<iostream>

using namespace std;

int main() {
    char *pGrades = nullptr;
    cout << "Enter the array size: ";
    int size;
    cin >> size;
    // pNum stores the memory address of a char array in the heap
    pGrades = new char[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter Grade: ";
        char grade;
        cin >> grade;
        pGrades[i] = grade;
        // *(pGrades + i) = grade;
    }

    // print array
    for (int i = 0; i < size; i++) {
        // pGrades[i]
        cout << *(pGrades + i) << endl;
    }

    // manually delete the allocated memory
    delete[] pGrades;


    
    return 0;
}