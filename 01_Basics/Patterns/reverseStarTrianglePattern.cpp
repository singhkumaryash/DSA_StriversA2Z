// Problem statement : Ninja was very fond of patterns. For a given integer
// ‘N’, he wants to make the Reverse N-Star Triangle.
// Example:
// Input: ‘N’ = 3
// Output:
// *****
//  ***
//   *

// Solution :

#include <bits/stdc++.h>
using namespace std;

void nStarTriangle(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int x = 0; x < n - i; x++)
        {
            cout << " ";
        }
        for (int y = 0; y < 2 * i - 1; y++)
        {
            cout << "*";
        }
        for (int z = 0; z < n - i; z++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Reverse Star Triangle : " << endl;
    nStarTriangle(n);
    return 0;
}