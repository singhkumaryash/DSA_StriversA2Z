// Problem statement : Sam is curious about symmetric patterns, so he decided to create one.
// For every value of ‘N’, return the symmetry as shown in the example.
// Example:
// Input: ‘N’ = 3
// Output:
// *         *
// * *     * *
// * * * * * *
// * *     * *
// *         *

// Solution :

#include <bits/stdc++.h>
using namespace std;

// void symmetry(int n)
// {
//     for (int i = 0; i < 2 * n; i++)
//     {
//         int star = i + 1;
//         int space = 2 * n - i;
//         if (i >= n)
//         {
//             star = 2 * n - i - 1;
//             space = 2 * (i - n - 1);
//         }

//         for (int x = 0; x < star; x++)
//         {
//             cout << "* ";
//         }
//         for (int y = 0; y <= space; y++)
//         {
//             cout << " ";
//         }
//         for (int z = 0; z < star; z++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }
void symmetry(int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        int stars = i + 1;
        int space = 2 * (n - i - 1);
        if (i >= n)
        {

            stars = 2 * n - i;
            space = 2 * (i - n);
        }
        // Left stars
        for (int j = 0; j < stars; j++)
        {
            cout << "* ";
        }

        // Middle space (use "  " for width match)
        for (int j = 0; j < space; j++)
        {
            cout << "  ";
        }

        // Right stars
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
    cout << "Symmetry Pattern : " << endl;
    symmetry(n);
    return 0;
}