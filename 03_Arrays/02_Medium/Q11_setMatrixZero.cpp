// Set Matrix Zero

// Problem Statement : Given a matrix if an element in the matrix is 0 then you
// will have to set its entire column and row to 0 and then return the matrix.

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
void markRow(vector<vector<int>> &matrix, int i, int col)
{
    for (int j = 0; j < col; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}
void markCol(vector<vector<int>> &matrix, int j, int row)
{
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void setZeroesBruteForce(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, i, col); // helper function to mark the row
                markCol(matrix, j, row); // helper function to mark the column
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// BETTER APPROACH
void setZeroesBetter(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> rowsCheck(row, 0);
    vector<int> colsCheck(col, 0);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowsCheck[i] = 1;
                colsCheck[j] = 1;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (rowsCheck[i] == 1 || colsCheck[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// OPTIMAL APPROACH
void setZeroesOptimal(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{

    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    int n = matrix.size();
    int m = matrix[0].size();
    cout << "The Original matrix is: " << endl;
    for (auto it : matrix)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    setZeroesOptimal(matrix);

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

// BRUTE FORCE :

//   Time Complexity : O((N*M)*(N + M)) + O(N*M), where N = no. of rows and M = no. of column
//   Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M).
//   Now, whenever we find any such cell we mark that row and column with -1. This process takes
//   O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
//   Another O(N*M) is taken to mark all the cells with -1 as 0 finally.

//   Space Complexity: O(1) as we are not using any extra space

// BETTER APPROACH :

//   Time Complexity: O(2*(N*M)), where N = no. of rows and M = no. of column.
//   As we are traversing the entire matrix 2 times and each traversal is taking O(N*M) time.

//   Space Complexity: O(N) + O(M), where N = no. of rows and M = no. of column.

// OPTIMAL APPROACH :

//   Time Complexity: O(2*(N*M)), where N = no. of rows and M = no. of column.
//   As we are traversing the entire matrix 2 times and each traversal is taking O(N*M) time.

//   Space Complexity: O(1) as we are not using any extra space