#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> multiplyMatrix(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2);

int main()
{
    vector<vector<int>> matrix1 = {{3, -2, -1}, {2, 6, -5}, {7, 1, -8}};
    vector<vector<int>> matrix2 = {{1, 9, 8}, {0, 11, 5}, {-3, 2, -7}};

    vector<vector<int>> result = multiplyMatrix(matrix1, matrix2);

    cout << "Result: " << endl;
    for (auto &row : result)
    {
        for (int &i : row)
        {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> multiplyMatrix(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2)
{
    vector<vector<int>> result;

    if (matrix1.empty() || matrix1[0].empty())
    {
        cout << "Matrix 1 is empty!" << endl;
        return {};
    }
    else if (matrix2.empty() || matrix2[0].empty())
    {
        cout << "Matrix 2 is empty!" << endl;
        return {};
    }
    else if (matrix1[0].size() != matrix2.size())
    {
        cout << "The column number of the first Matrix must be equal to the row number of the second matrix." << endl;
        return {};
    }

    for (size_t i = 0; i < matrix1.size(); ++i) // row of first matrix
    {
        vector<int> row;
        for (size_t j = 0; j < matrix2[0].size(); ++j) // column of second matrix
        {
            int total{0};
            for (size_t k = 0; k < matrix2.size(); ++k) // row of second matrix
            {
                total += matrix1[i][k] * matrix2[k][j];
            }

            row.push_back(total);
        }
        result.push_back(row);
    }

    return result;
}