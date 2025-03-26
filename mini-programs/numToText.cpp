#include <iostream>
#include <map>
#include <vector>

#include <iostream>

using namespace std;

map<int, string> numMap{
    {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"}, {100, "hundred"}, {1000, "thousand"}};
// numMap.insert({1, "one"});
// numMap[1] = "one";

string numToText(int x)
{
    int n = to_string(x).size();
    int divider;
    vector<int> output; // 9321 -> 9, 1000, 3, 100, 20, 1

    if (x < 21)
    {
        return input;
    }
    else if (n == 2)
    {
        divider = 10;
    }
    else if (n == 3)
    {
        divider = 100;
    }
    else if (n == 4)
    {
        divider = 1000;
    }

    int temp = x;
    for (int i = 0; i < n; ++i) // 921
    {
        if (temp < 21)
        {
            output.push_back(temp);
            break;
        }
        else if (temp < 100) // if 99 -> push 90
        {
            output.push_back(temp - (temp % divider));
        }
        else // if 999 -> push 9 and 100
        {
            output.push_back(temp / divider);
            output.push_back(divider);
        }

        temp = temp % divider;
        divider /= 10;
    }

    // get result
    string result;
    for (int x : output)
    {
        if (x > 9 && x < 100)
        {
            result += "and ";
        }

        result += numMap[x] + " ";
    }

    return result;
}

int main()
{
    cout << numToText(9999) << endl;
    return 0;
}