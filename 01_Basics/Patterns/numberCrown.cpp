// Problem statement : Aryan and his friends are very fond of the pattern.
// They want to make the Reverse N-Number Crown for a given integer' N'.
// Given 'N', print the corresponding pattern.
// Example:
// Input: ‘N’ = 3
// Output:
// 1         1
// 1 2     2 1
// 1 2 3 3 2 1

// Solution :



#include <bits/stdc++.h>
using namespace std;

void numberCrown(int n)
{
    int space = 2 * (n + 1);

    for (int i = 1; i <= n; i++)
    {

        for (int x = 1; x <= i; x++)
        {
            cout << x << " ";
        }
        for (int y = 1; y <= space; y++)
        {
            cout << "  ";
        }
        for (int z = i; z >= 1; z--)
        {
            cout << z << " ";
        }
        cout << endl;
        space = space - 2;
    }
}

int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    numberCrown(n);
    return 0;
}

// Note : Space is calculated as 2 * (n + 1) to ensure the correct spacing 
//        between the two halves of the pattern. 
//        Spaces are given two space to format the output in terminal.