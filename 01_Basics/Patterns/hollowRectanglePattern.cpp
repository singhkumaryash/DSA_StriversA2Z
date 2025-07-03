// Problem statement : Ninja has been given a task to print the required star pattern
// and he asked your help for the same.
// You must return an ‘N’*’N’ matrix corresponding to the given star pattern.
// Example:
// Input: ‘N’ = 4
// Output:
// ****
// *  *
// *  *
// ****

// Solution :

#include <bits/stdc++.h>
using namespace std;

void hollowRectangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Hollow Rectangle Pattern : " << endl;
    hollowRectangle(n);
    return 0;
}
