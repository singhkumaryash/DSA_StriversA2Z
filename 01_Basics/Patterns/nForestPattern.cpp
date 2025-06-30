// Problem statement : Sam is making a forest visualizer.
// An N-dimensional forest is represented by the pattern of size NxN filled with ‘*’.
// For every value of ‘N’, help sam to print the corresponding N-dimensional forest.
// Example:
// Input: ‘N’ = 3
// Output:
// * * *
// * * *
// * * *

// Solution :

#include <bits/stdc++.h>
using namespace std;
void nForest(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout<<"N-dimensional Forest Pattern:"<<endl;
    nForest(n);
    return 0;
}