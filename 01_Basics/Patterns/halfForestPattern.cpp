// Problem statement : Sam is making a forest visualizer. An N-dimensional
// forest is represented by the pattern of size NxN filled with ‘*’.
// An N/2-dimensional forest is represented by the lower triangle of the pattern filled with ‘*’.
// For every value of ‘N’, help sam to print the corresponding N/2-dimensional forest.
// Example:
// Input:  ‘N’ = 3
// Output:
// *
// * *
// * * *

// Solution :

#include <bits/stdc++.h>
using namespace std;
void nForest(int n)
{
    int i = 0;
    while (i != n)
    {
        for (int j = 0; j <= i; j++)
        {

            cout << "* ";
        }
        cout << endl;
        i++;
    }
}

int main()
{
    int n;
    cout << " Enter N : ";
    cin >> n;
    cout << "N/2-dimensional Forest Pattern:" << endl;
    nForest(n);
    return 0;
}