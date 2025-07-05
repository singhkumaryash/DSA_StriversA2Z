// Problem Statement : Given a number X,  print its factorial.
// To obtain the factorial of a number, it has to be multiplied
// by all the whole numbers preceding it. More precisely X! = X*(X-1)*(X-2) … 1.

// Note: X  is always a positive number.

// Input: X = 5
// Output: 120
// Explanation: 5! = 5*4*3*2*1

// Solution :

#include <iostream>
using namespace std;

int nFactorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * nFactorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "The factorial of " << n << " is " << nFactorial(n) << endl;
    return 0;
}

// Time Complexity :

// TC is O(n) as the function is being called n times.

// Space Complexity :

// SC is O(n) because the recursion stack space would be full with
// all the function calls waiting to get completed and that would
// make it an O(N) recursion stack space
