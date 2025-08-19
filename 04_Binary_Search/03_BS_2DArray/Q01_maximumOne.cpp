// Find the row with maximum number of 1's

// Problem Statement : You have been given a non-empty grid ‘mat’ with 'n' rows and 'm'
// columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
// Your task is to find the index of the row with the maximum number of ones.
// Note: If two rows have the same number of ones, consider the one with a smaller index.
// If there's no row with at least 1 zero, return -1.

// Example :
// Input Format: n = 3, m = 3,
// mat[] =
// 1 1 1
// 0 0 1
// 0 0 0
// Result: 0
// Explanation: The row with the maximum number of ones is 0 (0 - indexed).

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach : Count the number of 1's in each row
int rowWithMax1sBruteForce(vector<vector<int>> &matrix, int n, int m)
{
    int maxCount = -1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            count += matrix[i][j];
        }
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }
    return index;
}

// Optimal Approach : Using Binary Search
// Note: Since each row is sorted, we can use binary search to find the first occurrence
// of 1 in each row, which will help us count the number of 1's.
// We use lowerBound to find the first occurrence of 1 in each row.

int lowerBound(vector<int> &row, int size, int x)
{
    int low = 0;
    int high = size - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (row[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int index = -1;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        int indexOfFirstOne = lowerBound(matrix[i], m, 1);
        int count = m - indexOfFirstOne; // counts the number of 1's in the row
        if (count > maxCount)
        {
            maxCount = count; // update maxCount if current row has more 1's
            index = i;        // update index to current row
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 1}};
    int n = 4, m = 4;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << endl;
}

// Time and Space Complexity Analysis

// 1. BRUTE FORCE
//    - Time Complexity : O(N * M)
//        Iterates through each row and each column counts the number of 1's.
//    - Space Complexity : O(1)
//        Constant space used.

// 2. OPTIMAL APPROACH (Binary Search)
//    - Time Complexity : O(N * log M)
//        Each row is processed in logarithmic time to find the first occurrence of 1.
//        Each iteration halves the search space.
//    - Space Complexity : O(1)
//        Constant space used.