// Problem statement : Ninja was very fond of patterns. For a given integer
// ‘N’, he wants to make the N-Star Diamond.
// Example:
// Input: ‘N’ = 3
// Output:
//   *
//  ***
// *****
// *****
//  ***
//   *

// Solution :

#include <bits/stdc++.h>
using namespace std;

void nStarDiamond(int n)
{
    for (int i = 0; i <= n; i++)
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
    for (int j = n; j > 0; j--)
    {
        for (int p = 0; p < n - j; p++)
        {
            cout << " ";
        }
        for (int q = 0; q < 2 * j - 1; q++)
        {
            cout << "*";
        }
        for (int r = 0; r < n - j; r++)
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
    cout << "Star Diamond : " << endl;
    nStarDiamond(n);
    return 0;
}
// Note :  First printed the upper triangle then the lower triangle which together formed diamond.