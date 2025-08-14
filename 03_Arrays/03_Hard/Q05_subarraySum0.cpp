// Length of the longest subarray with zero Sum

// Problem Statement : Given an array containing both positive and negative integers,
// we have to find the length of the longest subarray with the sum of all elements equal
// to zero.

// Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
// Result: 5
// Explanation: The following subarrays sum to zero:
// {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
// Since we require the length of the longest subarray, our answer is 5.

// Solution :

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/* BRUTE FORCE
int longestSubarrayWithZeroSum(vector<int> arr)
{
    int maxLength = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];

            if (sum == 0)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}
*/

// BETTER APPROACH
int longestSubarrayWithZeroSum(vector<int> arr)
{
    int maxLength = 0;
    int sum = 0;
    map<int, int> preSumMap;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLength = i + 1;
        }
        int remaining = sum; // sum-k ; where k is 0.
        if (preSumMap.find(remaining) != preSumMap.end())
        {
            int length = i - preSumMap[remaining];
            maxLength = max(maxLength, length);
        }

        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLength;
}

int main()
{
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    int result = longestSubarrayWithZeroSum(arr);
    cout << "The length of the longest subarray with sum zero is: " << result << endl;
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
// - Use of ordered or unordered maps affects time complexity from O(logn) to O(n) in worst case.
