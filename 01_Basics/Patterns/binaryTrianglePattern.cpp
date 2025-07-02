// Problem statement : Aryan and his friends are very fond of the pattern.
// For a given integer ‘N’, they want to make the N-Binary Number Triangle.
// You are required to print the pattern as shown in the examples below.
// Example:
// Input: ‘N’ = 3
// Output:
// 1
// 0 1
// 1 0 1

// Solution  :

#include <bits/stdc++.h>
using namespace std;

void nBinaryTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int num = 0;
        if (i % 2 == 0)
        {
            num = 1;
        };
        for (int j = 1; j <= i; j++)
        {
            cout << 1 - num << " ";
            num = 1 - num;
            ;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Binary Triangle : " << endl;
    nBinaryTriangle(n);
    return 0;
}