// Problem Statement : The Fibonacci numbers, commonly denoted F(n) form a sequence,
// called the Fibonacci sequence, such that each number is the sum of the two
// preceding ones, starting from 0 and 1. That is,
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

// Solution  :

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)  // Base Case for fib(1)=1 & fib(0)=0;
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Fibonacci(" << n << ") : " << fibonacci(n) << endl;
    return 0;
}

// Time Complexity : 

// TC = T(N-1)+T(N-2)+O(1) The number of function calls grows exponentially
// because each call results in two more recursive calls (except base cases).
// Therefor TC is O(2^n).

//Space complexity : 

// SC is O(n) because the recursion stack depth goes up to 'n' in the worst case,
// as each function call waits for the result of the next.