// Rotate Image by 90 degree

// Problem Statement : Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BRUTE FORCE
void rotateImageBruteForce(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n - i - 1] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = ans[i][j];
        }
    }
}

// OPTIMAL APPROACH
void rotateImageOptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {

        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int n = matrix.size();

    cout << "The Original matrix is: " << endl;
    for (auto it : matrix)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    rotateImageOptimal(matrix);

    cout << "The Final matrix is: " << endl;
    for (auto it : matrix)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}

// BRUTE FORCE

//   Time Complexity  : TC is O(n^2)+O(n^2) = O(2*(n*n)), where n is the size of matrix.
//   As we traverse the array twice using nested loops. Once for answer matrix, and another
//   to copy back.

//   Space Complexity : SC is O(n), as we use ans array to store the answer matrix.

// Optimal Approach :

//   Time Complexity  : TC is O(n*n), where n is the size of matrix.

//   Space Complexity : SC is O(1), as we use no extra data structure.
