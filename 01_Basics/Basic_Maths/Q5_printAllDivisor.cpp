// Problem Statement : Given an integer N, return all divisors of N.

// A divisor of an integer N is a positive integer that divides N without
// leaving a remainder. In other words, if N is divisible by another
// integer without any remainder, then that integer is considered a divisor of N.

// Input:N = 36
// Output:[1, 2, 3, 4, 6, 9, 12, 18, 36]

// Solution :

#include <bits/stdc++.h>
using namespace std;

// Brute Force

void printDivisor(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Optimal Approach

void getDivisor(int n)
{
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    for (auto it : divisors)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "The Divisors of " << n << " are : "; // Brute Force
    printDivisor(n);
    cout << "The Divisors of " << n << " are : "; // Optimal Approach
    getDivisor(n);
    return 0;
}

// Time Complexity :

// Brute Force :
// TC is O(N) where N is the input as we iterates through each and every
// number from 1 to 'n' once to check if it is a divisor.

// Optimal Approach :
// TC is O(sqrt(N)) where N is the input as we iterates through each and
// every number from 1 to the square root of N once to check if it is a divisor.

// Space Complexity :

// SC is O(2*sqrt(N)) where N is the input as we allocate memory for an
// array to hold all the divisors. The size of this array could go to be 2*(sqrt(N)).
