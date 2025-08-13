// Split Array - Largest Sum

// Problem Statement : Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array
// ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your
// task is to return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

// Input Format: N = 5, a[] = {1,2,3,4,5}, k = 3
// Result: 6
// Explanation: There are many ways to split the array a[] into k consecutive subarrays. The best
// way to do this is to split the array a[] into [1, 2, 3], [4], and [5], where the largest sum
// among the three subarrays is only 6.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <numeric>   // for accumulate
using namespace std;

// Checks if we can split nums into <= k subarrays with largest sum <= mid
bool isPossibleSolution(vector<int> &nums, int k, int mid)
{
    int subarraySum = 0;
    int subarrayCount = 1; // at least one subarray

    for (int num : nums)
    {
        if (subarraySum + num <= mid)
        {
            subarraySum += num; // continue in current subarray
        }
        else
        {
            subarrayCount++; // start new subarray
            if (subarrayCount > k || num > mid)
            {
                return false; // too many subarrays or element too big
            }
            subarraySum = num;
        }
    }
    return true;
}

// Finds the minimized largest subarray sum
int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());   // minimum possible largest sum
    int high = accumulate(nums.begin(), nums.end(), 0); // maximum possible largest sum

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossibleSolution(nums, k, mid))
        {
            high = mid - 1; // try smaller maximum sum
        }
        else
        {
            low = mid + 1; // need bigger maximum sum
        }
    }
    return low; // smallest valid maximum sum
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    int k = 3;
    cout << "The answer is: " << splitArray(a, k) << "\n";
    return 0;
}

// NOTE* : The problem is similar to book allocation and painter's partition.

// Time and Space Complexity:

//    - Time Complexity : O(N * log(max-sum))
//        Everytime we check if a subarray sum is a possible solution taking O(N).
//        Rest to calculate the minimized largest sum of the split we use
//        binary search from maximum of the array to the sum of the array taking O(log(max-sum)).

//    - Space Complexity : O(1)
//        No extra space is used.

// NOTE : Brute force would be to use linear search instead of binary search in
//        the function, rest same.