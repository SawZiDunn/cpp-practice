#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

template <typename type>

bool checkPalindrone(vector<type> &vec)
{

    int n = vec.size() / 2;

    for (int i = 0; i < n; ++i)
    {
        if (*(vec.begin() + i) != *(vec.rbegin() + i))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int> vec1 = {1, 2, 2, 1};
    vector<char> vec2 = {'a', 'b', 'b', 'a', 'b'};

    cout << boolalpha << checkPalindrone(vec1) << endl;
    cout << boolalpha << checkPalindrone(vec2) << endl;
}
