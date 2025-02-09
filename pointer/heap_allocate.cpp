#include <iostream>

using namespace std;

int main()
{
    int *pNum = nullptr;
    // pNum stores the memory address of an int in the heap
    pNum = new int;
    *pNum = 25;

    // or
    // int *pNum = new int(25);

    // or
    int *pNum = new int;
    *pNum = 25;

    cout << "Memory Address: " << pNum << endl;
    ;
    cout << "Value: " << *pNum << endl; // 25

    // manually delete the allocated memory
    delete pNum;

    return 0;
}