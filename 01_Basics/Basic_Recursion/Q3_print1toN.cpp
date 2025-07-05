// Problem Statement : Given an integer n, write a function to
// print all numbers from 1 to n (inclusive) using recursion.
// You must not use any loops such as for, while, or do-while.
// The function should print each number on a separate line, in
// increasing order from 1 to n

// Input: n = 5
// Output:
// 1
// 2
// 3
// 4
// 5

// Solution :

#include <iostream>
using namespace std;

void printNumbers(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << endl;

    printNumbers(i + 1, n);
}

// Using Backtracking
void printNumberUsingBacktracking(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    printNumberUsingBacktracking(i - 1, n); // first the last function call stack is achieved and then executed
    cout << i << endl;
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    printNumbers(1, n);
    cout << "Using Backtracking" << endl;
    printNumberUsingBacktracking(n, n);
    return 0;
}

// Time Complexity :

// TC is O(n) as the function is being called n times and
// then it prints which is O(1).

// Space Complexity :

// SC is O(n) because the recursion stack space would be full with
// all the function calls waiting to get completed and that would
// make it an O(N) recursion stack space
