// Problem Statement : Given an integer N, print the following pattern :
// Here, N = 5.
// Examples:
// Input Format: N = 3
// Result:
// C
// B C
// A B C

// Solution :

#include <bits/stdc++.h>
using namespace std;

void alphaTriangle(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (char alpha = ('A' + n - 1) - i; alpha <= ('A' + n - 1); alpha++)
        {
            cout << alpha << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Alpha Triangle Pattern : " << endl;
    alphaTriangle(n);
    return 0;
}

// Note : 'A'+n-1 denotes the nth letter; i.e. E for input 5.
//         The inner loop  condition says to print from 'A'+n-1-i to 'A'+n-1;
//         as the '-i' starts the alpha from the character needed.