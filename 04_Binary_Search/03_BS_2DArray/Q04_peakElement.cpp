// Find a Peak Element in a 2D Array

// A peak element in a 2D grid is an element that is strictly greater than all of its
// adjacent neighbors to the left, right, top, and bottom.
// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any
// peak element mat[i][j] and return the length 2 array [i,j].
// You may assume that the entire matrix is surrounded by an outer perimeter with the
// value -1 in each cell.

// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// Function to find the row index of the maximum element in a given column
int findMaxRow(vector<vector<int>> &mat, int n, int m, int mid)
{
    int maxValue = -1;
    int index = -1;
    for (int i = 0; i < n; i++) // linear search to find max in mid column
    {
        if (mat[i][mid] > maxValue)
        {
            maxValue = mat[i][mid];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m - 1; // Binary search on columns
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int maxRow = findMaxRow(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1; // if left element exists
        int right = mid + 1 < m ? mat[maxRow][mid + 1] : -1; // if right element exists

        // Check if the current element is a peak
        if (mat[maxRow][mid] > left && mat[maxRow][mid] > right)
        {
            return {maxRow, mid};
        }

        else if (mat[maxRow][mid] < left)
        {
            high = mid - 1; // move to left side
        }
        else
        {
            low = mid + 1; // move to right side
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {{10, 20, 15},
                               {21, 30, 14},
                               {7, 16, 32}};
    vector<int> result = findPeakGrid(mat);
    cout << "Peak Element found at: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}

// Time and Space Complexity Analysis

//    - Time Complexity : O(log(M) * N)
//        Using binary search to find the column taking O(log(m)).
//        Linear search to find the max in that column taking O(n).

//    - Space Complexity : O(1)
//        Constant space used.
