// Problem statement : You are given two integers 'n', and 'm'.
// Calculate 'gcd(n,m)', without using library functions.
// Note:
// The greatest common divisor (gcd) of two numbers 'n' and 'm'
// is the largest positive number that divides both 'n' and 'm'
// without leaving a remainder.
// Example:
// Input: 'n' = 6, 'm' = 4
// Output: 2

// Solution :

#include <bits/stdc++.h>
using namespace std;

// Brute Force (optimized) 
int GCD(int a, int b)
{
    for (int i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return 1;
}

// Optimal Approach
int findGCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (b > a)
        {
            b = b % a;
        }
        else
        {
            a = a % b;
        }
    }
    if (a == 0)
    {
        return b;
    }
    return a;
}

int main()
{
    int n1, n2;
    cout << "Enter Number 1 : ";
    cin >> n1;
    cout << "Enter Number 2 : ";
    cin >> n2;
    cout << "GCD or HCF of numbers " << n1 << " & " << n2 << " is " << findGCD(n1, n2) << endl;
    cout << "GCD or HCF of numbers " << n1 << " & " << n2 << " is " << GCD(n1, n2) << endl;
}

// Time Complexity : 

// Brute Force : O(min(n,m)) where n and m are input.

//  Optimal : O(log(min(n,m))) where n and m are input.
//            Each modulo operation reduces the size of the numbers 
//            significantly thus results in logarithmic TC.

// Space Complexity : 

// SC is O(1) as constant space is used independent of input.