// Problem statement : Sam is curious about symmetric patterns, so he decided to create one.
// For every value of ‘N’, return the symmetry as shown in the example.
// Example:
// Input: ‘N’ = 3
// Output:
// * * * * * *
// * *     * *
// *         *
// *         *
// * *     * *
// * * * * * *

// Solution :

#include <bits/stdc++.h>
using namespace std;

void symmetry(int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        int stars = n - i;
        int space = 2 * i;
        if (i >= n)
        {
            stars = i - n + 1;
        }
        if (i >= n)
        {
            space = 2 * (2 * n - i - 1);
        }

        for (int j = 0; j < stars; j++)
        {
            cout << "* ";
        }

        for (int m = 0; m < space; m++)
        {
            cout << "  ";
        }

        for (int j = 0; j < stars; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Symmetric Void Pattern : " << endl;
    symmetry(n);
    return 0;
}
