// Given an integer n, write a function to print all numbers from
// n to 1 (inclusive) using recursion.
// You must not use any loops such as for, while, or do-while.
// The function should print each number on a separate line, in
// decreasing order from n to 1

// Input: 5
// Output:
// 5
// 4
// 3
// 2
// 1

#include <iostream>
using namespace std;

void printNumbers(int i, int n)
{
    if (1 > i)
    {
        return;
    }
    cout << i << endl;
    printNumbers(i - 1, n);
}

// Using BackTracking
void printNumberUsingBacktracking(int i, int n)
{
    if (i > n)
    {
        return;
    }
    printNumberUsingBacktracking(i + 1, n);
    cout << i << endl; // first the last function call stack is achieved and then executed
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    printNumbers(n, n);
    cout << "Using Backtracking" << endl;
    printNumberUsingBacktracking(1, n);
    return 0;
}

// Time Complexity :

// TC is O(n) as the function is being called n times and
// then it prints which is O(1).

// Space Complexity :

// SC is O(n) because the recursion stack space would be full with
// all the function calls waiting to get completed and that would
// make it an O(N) recursion stack space
