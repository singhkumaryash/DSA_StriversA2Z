// Search in a row and column-wise sorted matrix

// Problem Statement: You have been given a 2-D array 'matrix' of size 'N x M' where 'N' and 'M'
// denote the number of rows and columns, respectively. The elements of each row and each
// column are sorted in non-decreasing order.
// But, the first element of a row is not necessarily greater than the last element of the
// previous row (if it exists).
// You are given an integer ‘target’, and your task is to find if it exists in the given 'matrix' or not.

// Input Format: N = 5, M = 5, target = 14
// matrix[] =
// 1   4   7   11  15
// 2   5   8   12  19
// 3   6   9   16  22
// 10  13  14  17  24
// 18  21  23  26  30

// Result: true
// Explanation: Target 14 is present in the cell (3, 2)(0-based indexing) of the matrix. So, the answer is true.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    int col = m - 1;
    while (row < n && col >= 0)
    {
        int element = matrix[row][col];
        if (element == target)
            return true; // found the target
        else if (element < target)
            row++; // Move down to a bigger element
        else
            col--; // Move left to a smaller element
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 14;
    cout << (searchMatrix(matrix, target) ? "True : Target found" : "False : Target not found") << endl;
    return 0;
}

// Time and Space Complexity Analysis

//    - Time Complexity : O(N + M)
//        We are starting traversal from (0, M-1), and at most, we can end up being in the cell (M-1, 0).
//        So, the total distance can be at most (N+M). Thus, the time complexity is O(N+M).

//    - Space Complexity : O(1)
//        Constant space used.

// NOTE* : Other approaches like linear search or a binary search on a row and lineraly iterating every row
//         can be used, but they are not optimal.