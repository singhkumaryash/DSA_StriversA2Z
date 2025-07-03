// Problem Statement: Given an integer N return the reverse of the given number.
// Note : If a number has trailing zeros, then its reverse will not
// include them. For e.g., reverse of 10400 will be 401 instead of 00401

// Example :

// Input:N = 12345
// Output:5432

// Solution :

#include <iostream>
#include <climits>
using namespace std;

int reverseNumber(int n)
{
    int revNum = 0;
    while (n != 0)
    {
        int ld = n % 10;
        if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10)
        {
            return 0; // this is to check if revnum get out of bound
        }
        revNum = (revNum * 10) + ld; // adds the last digit to the reversered number
        n = n / 10;
    }
    return revNum;
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Reverse of Number " << n << " is " << reverseNumber(n) << endl;
    return 0;
}

// Time Complexity :
// TC is O(log10(n)) because in the while loop we divide N by 10 until
// it becomes 0 which takes log10N iterations.