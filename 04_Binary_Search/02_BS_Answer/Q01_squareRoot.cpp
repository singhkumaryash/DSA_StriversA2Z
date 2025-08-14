// Finding Sqrt of a number using Binary Search

// Problem Statement : You are given a positive integer n. Your task is to find and return
// its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

// Note : The question explicitly states that if the given number, n, is not a perfect square,
// our objective is to find the maximum number, x, such that x squared is less than or equal
// to n (x*x <= n). In other words, we need to determine the floor value of the square root of n.

// Solution :

#include <iostream>
#include <cmath>
using namespace std;

int mySqrt(int x)
{
    if (x == 0)
    {
        return 0;
    }
    int low = 1;
    int high = x;
    int ans = -1;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;
        if (square <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter a positive integer : ";
    cin >> n;

    int result = mySqrt(n);
    cout << "The floor value of the square root of " << n << " is : " << result << endl;

    // sqrt(n); Using in-built sqrt() function

    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(log N)
//        Binary Search is used and each iteration reduces the search space by half.

//    - Space Complexity : O(1)
//        No extra space is used.

// Note: The in-built sqrt() function can also be used to find the square root of a number,
//       it returns a double value. Complexity remain same as above.