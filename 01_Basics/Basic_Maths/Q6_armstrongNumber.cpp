// Problem Statement : Given an integer N, return true it is an Armstrong number
// otherwise return false.

// An Amrstrong number is a number that is equal to the sum of its own digits each
// raised to the power of the number of digits

// Solution :

#include <bits/stdc++.h>
using namespace std;

bool isArmstrongNumber(int n)
{
    int digitCount = (log10(n)) + 1;
    int temp = n;
    int sum = 0;
    while (temp != 0)
    {
        int lastDigit = temp % 10;
        temp = temp / 10;
        sum = sum + pow(lastDigit, digitCount);
    }
    if (sum == n)
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "The number " << n << " is " 
    << (isArmstrongNumber(n) ? "a Armstrong Number." : "not a Armstrong Number.") 
    << endl;
    return 0;
}

// Time Complexity : 

// TC is O(log10(n)) as we run the loop for digits time, which is log10(n)+1.
// Other operation are constant time so does not constitue to Big 0.

// Space Complexity : 

// SC is o(1) as constant space is used for storage.
