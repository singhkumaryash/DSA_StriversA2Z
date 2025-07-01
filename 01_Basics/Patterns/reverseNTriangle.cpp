// Problem statement : Aryan and his friends are very fond of the pattern.
// For a given integer ‘N’, they want to make the Reverse N-Number Triangle.
// Example:
// Input: ‘N’ = 3
// Output:
// 1 2 3
// 1 2
// 1

// Solution :

#include <bits/stdc++.h>
using namespace std;

void nNumberTriangle(int n)
{

    for (int i = n; i > 0; i--)
    {

        for (int j = 1; j <= i; j++)
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
    cout << "Reverse Number Triangle : " << endl;
    nNumberTriangle(n);
    return 0;
}