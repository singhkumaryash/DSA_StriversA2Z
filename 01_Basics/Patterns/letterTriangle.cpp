// Problem statement : Aryan and his friends are very fond of patterns.
// For a given integer ‘N’,they want to make the Increasing Letter Triangle.
// Example:
// Input: ‘N’ = 3
// Output:
// A
// A B
// A B C

// Solution :

#include <bits/stdc++.h>
using namespace std;

void nLetterTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j <= 'A' + i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Letter Triangle Pattern : " << endl;
    nLetterTriangle(n);
    return 0;
}