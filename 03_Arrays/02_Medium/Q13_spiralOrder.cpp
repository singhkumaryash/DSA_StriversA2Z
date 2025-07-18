// Spiral Traversal of Matrix

// Problem Statement: Given a Matrix, print the given matrix in spiral order.

// Input : Matrix[][] = {{1, 2, 3, 4},
//                       {5, 6, 7, 8},
//                       {9, 10, 11, 12},
//                       {13, 14, 15, 16}};

// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.

#include <bits/stdc++.h>
using namespace std;

vector<int> printSpiralOrder(vector<vector<int>> matrix)
{

    // Define ans array to store the result.
    vector<int> ans;

    int n = matrix.size();    // no. of nows
    int m = matrix[0].size(); // no. of columns

    // Initialize the pointers reqd for traversal.
    int top = 0;
    int left = 0;
    int bottom = n - 1;
    int right = m - 1;

    // Loop until all elements are not traversed.
    while (top <= bottom && left <= right)
    {

        // For moving left to right
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);

        top++;

        // For moving top to bottom.
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);

        right--;

        // For moving right to left.
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);

            bottom--;
        }

        // For moving bottom to top.
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);

            left++;
        }
    }
    return ans;
}

int main()
{

    vector<vector<int>> matrixrix = {{1, 2, 3, 4},
                                     {5, 6, 7, 8},
                                     {9, 10, 11, 12},
                                     {13, 14, 15, 16}};
    int n = matrixrix.size();
    int m = matrixrix[0].size();
    cout << "The Original matrixrix is: " << endl;
    for (auto it : matrixrix)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    vector<int> result = printSpiralOrder(matrixrix);

    cout << "Spiral Order : { ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << "}" << endl;

    return 0;
}

// Time Complexity :
// TC is O(row*col), as we iterate the array once only in total.

// Space Complexity :
// SC is O(n), as we use vector to store answer.