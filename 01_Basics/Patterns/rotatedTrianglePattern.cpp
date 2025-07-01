// Problem statement : Ninja was very fond of patterns. For a given integer
// ‘N’, he wants to make the N-Star Rotated Triangle.
// Example:
// Input: ‘N’ = 3
// Output:
// *
// **
// ***
// **
// *

/// Solution :

#include <bits/stdc++.h>
using namespace std;

void nStarTriangle(int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        int star = i;
        if (i > n)
        {
            star = 2 * n - i;
        };

        for (int j = 1; j <= star; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Rotated Triangle : " << endl;
    nStarTriangle(n);
    return 0;
}