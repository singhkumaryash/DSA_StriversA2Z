// Problem statement : Given a number ‘N’, find out the sum of the
// first N natural numbers.

// Input: N=5
// Output: 15

// Solution :

#include <iostream>
using namespace std;

// Functional Recursion
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}

// Parameterized Recursion
void sum(int n, int s)
{
    if (n < 1)
    {
        cout << s;
        return;
    };
    sum(n - 1, s + n);
}

using namespace std;
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "The sum for first " << n << " natural number is ";
    sum(n, 0);
    cout << endl;
    cout << "The sum for first " << n << " natural number is " << sum(n) << endl;
    return 0;
}

// Time Complexity :

// TC is O(n) as the function is being called n times.

// Space Complexity :

// SC is O(n) because the recursion stack space would be full with
// all the function calls waiting to get completed and that would
// make it an O(N) recursion stack space
