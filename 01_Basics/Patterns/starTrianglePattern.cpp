// Problem statement : Ninja was very fond of patterns. For a given \
// integer ‘N’, he wants to make the N-Star Triangle.
// Example:
// Input: ‘N’ = 3
// Output:
//   *
//  ***
// *****

// Solution :

#include <bits/stdc++.h>
using namespace std;

void nStarTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < n - i - 1; x++) // n-i are the spaces; n=3, space=3-0-1=2;
        {
            cout << " ";
        }
        for (int y = 0; y < 2 * i + 1; y++) // 2*i+1 are the stars printed; n=3, stars=2*0+1=1;
        {
            cout << "*";
        }
        for (int z = 0; z < n - i - 1; z++) // n-i are the spaces; n=3, space=3-0-1=2
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
    cout << "Star Triangle : " << endl;
    nStarTriangle(n);
    return 0;
}