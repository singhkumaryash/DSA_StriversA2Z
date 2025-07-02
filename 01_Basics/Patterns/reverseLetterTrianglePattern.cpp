// Problem statement : Aryan and his friends are very fond of patterns.
// For a given integer ‘N’, they want to make the Reverse Letter Triangle.
// You must print a matrix corresponding to the given Reverse Letter Triangle.
// Example:
// Input: ‘N’ = 3
// Output:
// A B C
// A B

// Solution :

#include <bits/stdc++.h>
using namespace std;

void nLetterTriangle(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (char j = 'A'; j < 'A' + i; j++)
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
    cout << "Reverse Letter Triangle Pattern : " << endl;
    nLetterTriangle(n);
    return 0;
}