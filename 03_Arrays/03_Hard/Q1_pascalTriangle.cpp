// Program to generate Pascal's Triangle

// Problem Statement: This problem has 3 variations. They are stated below:

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

// In Pascal’s triangle, each number is the sum of the two numbers directly above it.

// Input: rowNum = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// Function to find combination nCr
// int nCr(int n, int c)
// {
//     long long ans = 1;
//     for (int i = 0; i < c; i++)
//     {
//         ans *= (n - 1);
//         ans /= (i - 1);
//     }
//     return ans;
// }

// Variation 1: Function to get the element at position (r, c)
int getPascalElement(int r, int c)
{
    long long ans = 1;
    int row = r - 1;
    int col = c - 1;
    for (int i = 0; i < col; i++)
    {
        ans *= (row - i);
        ans /= (i + 1);
    }
    return ans;
}

// Variation 2: Function to get the n-th row of Pascal's triangle
vector<int> generateRow(int rowNum)
{
    vector<int> Row;
    int ans = 1;
    Row.push_back(ans);
    for (int numCol = 1; numCol < rowNum; numCol++)
    {
        ans = ans * (rowNum - numCol);
        ans = ans / numCol;
        Row.push_back(ans);
    }
    return Row;
}

// Variation 3: Function to generate the first n rows of Pascal's triangle

// Brute Force :
void pascalTriangle(int rowNum)
{
    for (int row = 1; row <= rowNum; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << getPascalElement(row, col) << " ";
        }
        cout << endl;
    }
}

// Optimal Approach
vector<vector<int>> generatePascalTriangle(int rowNum)
{
    vector<vector<int>> pascalTriangle;
    for (int i = 1; i <= rowNum; i++)
    {
        pascalTriangle.push_back(generateRow(i)); // uses row generation to generate required rows
    }
    return pascalTriangle;
}

int main()
{
    // Variation 1 :
    int r = 5; // row number
    int c = 3; // col number
    int element = getPascalElement(r, c);
    cout << "The element at position (" << r << "," << c << ") is : "
         << element
         << endl;

    // Variation 2 :
    int rowNum = 5;
    vector<int> result = generateRow(rowNum);
    cout << "The row " << rowNum << " of Pascal Triangle is : { ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << "}" << endl;

    // Variation 3 :
    int row = 5;
    vector<vector<int>> triagle = generatePascalTriangle(row);
    for (auto it : triagle)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << endl;
    };
    pascalTriangle(row);

    return 0;
}

// Variation 1
// Time Complexity  : O(col)
// Space Complexity : O(1)

// Variation 2
// Time Complexity  : O(row)
// Space Complexity : O(1)

// Variation 3

// Brute Force
// Time Complexity  : O(row*row*col)
// Space Complexity : O(1)

// Optimal Approach
// Time Complexity  : O(row*row)
// Space Complexity : O(1)