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
    // Brute Force : 
    // int count=0;
    // while(n>0){
    //     count++;
    //     n=n/10;
    // }
    // return count;

    return (log10(n) + 1); // Optimal 
}
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "The number of digit(s) in number " << n << " is " << countDigits(n) << endl;

    return 0;
}

// Time Complexity :
// Brute Force = O(log10(n)) because 'n' is divided by 10 in every iteration.
// Optimal = O(1) as in optimal approach arithmetic operation is evaluated.