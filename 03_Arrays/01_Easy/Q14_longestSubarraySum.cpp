// Longest Subarray with sum K | [Postives and Negatives]

// Problem Statement: Given an array and a sum k, we need to print the length of the
// longest subarray that sums to k.

// Input Format: N = 4, k = 2, array[] = {-1, 0, 1, 1}
// Result: 3
// Explanation: The longest subarray with sum 1 is {-1, 0, 1, 1}. And its length is 3.

// Solution :

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE (Two Loops)
int longestSubarrayBruteForce(vector<int> a, int k)
{
    int n = a.size();
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == k)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

// OPTIMAL (Using Prefix Sum and HashMap)
int longestSubarray(vector<int> a, int k)
{
    int n = a.size();
    int sum = 0;
    int maxLength = 0;
    map<int, int> preSumMap;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxLength = i + 1;
        }
        int remaining = sum - k;
        if (preSumMap.find(remaining) != preSumMap.end())
        {
            int length = i - preSumMap[remaining];
            maxLength = max(maxLength, length);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i; // Store only the first occurrence of prefix sum
        }
    }
    return maxLength;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 1};
    int k = 2;
    cout << "The length of the longest subarray with sum " << k << " is " << longestSubarrayBruteForce(nums, k);
    cout << endl;

    return 0;
}

// 1. Brute Force Approach:
//    - Time Complexity: O(n^2)
//       Two nested loops traverse all subarrays
//    - Space Complexity: O(1)
//       No extra data structures used

// 2. Hashing (Prefix Sum) Approach:
//    - Time Complexity: O(n*logn)
//       Single pass through array
//       Each map operation is O(log n)
//    - Space Complexity: O(n)
//       Prefix sum map stores at most n unique sums

// NOTES :
// - Hashing works efficiently when array elements are positive or non-zero.
// - Use of ordered or unordered maps affects time complexity from O(logn) to O(n) in worst case.
