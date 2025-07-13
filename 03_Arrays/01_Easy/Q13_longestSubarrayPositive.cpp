// Longest Subarray with given Sum K(Positives)

// Problem Statement: Given an array and a sum k, we need to print the length of the
// longest subarray that sums to k.

// Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
// Result: 3
// Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3

// Solution :

#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BRUTE FORCE (Three Loops)
// int longestSubArrayNaive(vector<int> a, int k)
// {
//     int length = 0;
//     int n = a.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             int sum = 0;
//             for (int x = i; x <= j; x++)
//             {
//                 sum += a[x];
//             }
//             if (sum == k)
//             {
//                 length = max(length, j - i + 1);
//             }
//         }
//     }
//     return length;
// }

// BRUTE FORCE (Two Loops)
int longestSubArrayBruteForce(vector<int> a, int k)
{
    int length = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == k)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

// BETTER APPROACH (HASHING) *only works for positive or non zero elemnent array*
int longestSubArrayBetter(vector<int> a, int k)
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

        // stores only first occurence of prefix sum
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLength;
}

// Optimal Approach (Two Pointers)
int longestSubArrayOptimal(vector<int> a, int k)
{
    int n = a.size();
    int left = 0;
    int right = 0;
    int sum = 0;
    int maxLength = 0;
    while (right < n)
    {
        sum += a[right];
        while (sum > k && left <= right)
        {
            sum -= a[left++];
        }
        if (sum == k)
        {
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
    }
    return maxLength;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 1, 1, 1, 1};
    int k = 4;
    cout << "The length of the longest subarray with sum " << k << " is " << longestSubArrayBruteForce(nums, k);
    cout << endl;
    cout << "The length of the longest subarray with sum " << k << " is " << longestSubArrayBetter(nums, k);
    cout << endl;
    cout << "The length of the longest subarray with sum " << k << " is " << longestSubArrayOptimal(nums, k);
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

// 3. Two Pointers (Optimal for Positives):
//    - Time Complexity: O(2*n)= O(n)
//       Each element is processed at most twice (once by left, once by right)
//    - Space Complexity: O(1)
//       Only counters and pointers used, no extra data structures

// NOTES :
// - Hashing works efficiently when array elements are positive or non-zero.
// - Two Pointer method is most efficient but only works for strictly positive numbers.
// - Use of ordered or unordered maps affects time complexity from O(logn) to O(n) in worst case.
