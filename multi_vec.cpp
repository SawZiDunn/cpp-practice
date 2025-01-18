#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> vec = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}

    };

    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        for (auto j = (*i).begin(); j != i->end(); ++j)
        { // i -> begin()
            cout << *j << ", ";
        }

        cout << endl;
    }

    return 0;
}
