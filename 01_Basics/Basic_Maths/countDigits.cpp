// Problem statement : You are given a number 'n'.
// Return number of digits in ‘n’.

// Example:
// Input: 'n' = 123

// Output: 3

// Solution :

#include <bits/stdc++.h>
using namespace std;
int countDigits(int n)
{
    return (log10(n) + 1);
}
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "The number of digit(s) in number " << n << " is " << countDigits(n) << endl;

    return 0;
}