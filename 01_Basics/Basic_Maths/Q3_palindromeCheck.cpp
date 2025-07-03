// Problem Statement: Given an integer N, return true if it is a
// palindrome else return false.

// A palindrome is a number that reads the same backward as forward.
// For example, 121, 1331, and 4554 are palindromes because they
// remain the same when their digits are reversed

// Example 1:
// Input:N = 4554
// Output:Palindrome Number

// Solution :

#include <bits/stdc++.h>
using namespace std;
int reverseNumber(int n)
{
    int revNum = 0;
    while (n != 0)
    {

        int ld = n % 10;
        if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10)
        {
            return 0;
        }
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }
    return revNum;
}
bool palindrome(int n)
{
    if (n < 0)
    {
        return false;
    }
    int revNum = reverseNumber(n);
    if (revNum == n)
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
    cout << "The Number " << n << " is " << (palindrome(n) ? "a Palindrome" : "not a Palindrome.") << endl;
    return 0;
}

// Time Complexity :
// TC is O(log10(n)) because in the while loop we divide N by 10 until
// it becomes 0 which takes log10N iterations.