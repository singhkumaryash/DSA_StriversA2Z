// Problem statement : Sam is curious about Alpha-Ramp, so he decided to create Alpha-Ramp of different sizes.
// An Alpha-Ramp is represented by a triangle, where alphabets are filled from the top in order.
// For every value of ‘N’, help sam to return the corresponding Alpha-Ramp.
// Example:
// Input: ‘N’ = 3
// Output:
// A
// B B
// C C C

// Solution :

#include <bits/stdc++.h>
using namespace std;

void alphaRamp(int n)
{
    char alpha = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << alpha << " ";
        }
        cout << endl;
        alpha++;
    }
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Aplha Ramp Pttern : " << endl;
    alphaRamp(n);
    return 0;
}