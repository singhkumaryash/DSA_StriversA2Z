// Problem Statement : Given an integer N, check whether it is prime or not.
// A prime number is a number that is only divisible by 1 and itself and
// the total number of divisors is 2.

// Input:N = 2
// Output:True

// Solution

#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{

    int factorCount = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factorCount++;

            if (i != n / i)
            {
                factorCount++;
            }
        }
    }
    if (factorCount == 2)
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
    cout << "The number " << n << (isPrime(n) ? " is a Prime number." : " is not a Prime Number.") << endl;
    return 0;
}

// Time Complexity :

// TC is O(sqrt(n)) where n is the input number. The loop iterates up to
// the square root of n performing constant time operations at each step.

// Space Complexity :

// SC is O(1) as the space complexity remains constant and independent of
// the input size.