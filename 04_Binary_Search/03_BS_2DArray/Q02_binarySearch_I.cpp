// Search in a sorted 2D matrix

// Problem Statement: You have been given a 2-D array 'matrix' of size 'N x M' where 'N' and 'M' denote
// the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing
// order. Moreover, the first element of a row is greater than the last element of the previous row
// (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the
// given 'matrix' or not.

// Input Format: N = 3, M = 4, target = 8,
// matrix[] =
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// Result: true
// Explanation: The ‘target’  = 8 exists in the 'mat' at index (1, 3).

// Solution :

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = (n * m) - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Intution : Every row is of size 'm', so when we divide by m it gives us the row index
        // and the remainder gives us the column index.

        int row = mid / m; // Calculate the row index
        int col = mid % m; // Calculate the column index
        int element = matrix[row][col];
        if (element == target)
        {
            return true;
        }
        else if (element > target)
        {
            high = mid - 1; // Move to the left half
        }
        else
        {
            low = mid + 1; // Move to the right half
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target = 9;
    cout << (searchMatrix(matrix, target) ? "True : Target found" : "False : Target not found") << endl;
}

// Time and Space Complexity Analysis

//    - Time Complexity : O(log(N * M))
//        Using binary search on the flattened version of the matrix.

//    - Space Complexity : O(1)
//        Constant space used.

// NOTE* : Other approaches like linear search or a binary search on a row and lineraly iterating every row
//         can be used, but they are not optimal.