// Problem statement : Sam is planting trees on the upper half region
// (separated by the left diagonal) of the square shared field.
// For every value of ‘N’, print the field if the trees are represented by ‘*’.
// Example:
// Input: ‘N’ = 3
// Output:
// * * *
// * *
// *

// Solution :

#include <bits/stdc++.h>
using namespace std;

void seeding(int n)
{
    int i = n;
    while (i > 0)
    {
        int j = i;
        while (j > 0)
        {
            cout << "* ";
            j--;
        }
        cout << endl;
        i--;
    }
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Seeding Pattern:" << endl;
    seeding(n);
    return 0;
}