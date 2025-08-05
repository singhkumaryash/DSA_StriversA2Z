// Nth Root of a Number using Binary Search

// Problem Statement : Given two numbers N and M, find the Nth root of M. The nth root of a
// number M is defined as a number X when raised to the power N equals M. If the n'th root is
// not an integer, return -1.

// Input Format: N = 3, M = 27
// Result: 3
// Explanation: The cube root of 27 is equal to 3.

// Input Format: N = 4, M = 69
// Result: -1
// Explanation: The 4th root of 69 does not exist. So, the answer is -1.

// Solution :

#include <iostream>
using namespace std;

// NOTE : The Brute force solution is to iterate from 1 to M using loop and check if mid^n == m.
//        This will also have exp() function to calculate mid^n.
//        Thus, the time complexity will be O(N * M) which is not efficient.

// OPTIMAL SOLUTION : Using Binary Search
int exp(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = ans * mid; // Calculate mid^n
        if (ans > m)
        {
            return 2;
        }
    }
    if (ans == m)
    {
        return 1;
    };
    return 0; // If mid^n < m, return 0
}

int NthRoot(int n, int m)
{
    int low = 1;
    int high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int value = exp(mid, n, m); // Uses exp function to calculate mid^n
        if (value == 1)             // if mid^n == m
        {
            return mid;
        }
        else if (value == 2) // if mid^n > m
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // if mid^n < m
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cout << "Enter the value of N : ";
    cin >> n;
    cout << "Enter the value of M : ";
    cin >> m;

    int result = NthRoot(n, m);
    if (result != -1)
    {
        cout << "The " << n << "th root of " << m << " is: " << result << endl;
    }
    else
    {
        cout << "The " << n << "th root of " << m << " does not exist." << endl;
    }

    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N * log N)
//        Binary Search is used and each iteration reduces the search space by half.
//        The exp function runs in O(N) time, thus overall complexity is O(N * log N).

//    - Space Complexity : O(1)
//        No extra space is used.
