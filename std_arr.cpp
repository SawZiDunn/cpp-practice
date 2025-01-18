#include <iostream>
#include <array>
#include <functional> // for sort()
using namespace std;

int main()
{

    array<int, 3> arr = {3, 2, 1};

    cout << *(arr.begin() + 2) << endl;

    sort(arr.begin(), arr.end()); // sort the original array
    for (auto i : arr)
    {
        cout << i << endl;
    }

    return 0;
}