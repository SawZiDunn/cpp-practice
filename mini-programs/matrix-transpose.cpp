#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> getMatrixTranspose(const vector<vector<int>> &matrix);

int main()
{
    vector<vector<int>> matrix = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    vector<vector<int>> result = getMatrixTranspose(matrix);

    cout << "Transposed Matrix: " << endl;
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

vector<vector<int>> getMatrixTranspose(const vector<vector<int>> &matrix)
{
    vector<vector<int>> result;
    for (size_t i = 0; i < matrix[0].size(); ++i) // column
    {
        vector<int> row;
        for (size_t j = 0; j < matrix.size(); ++j) // row
        {
            row.push_back(matrix[j][i]);
        }

        result.push_back(row);
    }

    return result;
}