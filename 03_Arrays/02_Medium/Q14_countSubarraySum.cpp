// Count Subarray sum Equals K

// Problem Statement: Given an array of integers and an integer k, return the total number
// of subarrays whose sum equals k.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Input Format: N = 4, array[] = {3, 1, 2, 4}, k = 6
// Result: 2
// Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

// Solution :

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subarraySumBruteForce(vector<int> &nums, int k)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                count++;
            }
        }
    }

    return count;
}

int subarraySumOptimal(vector<int> &nums, int k)
{
    map<int, int> preSumMap;
    int count = 0;
    int sum = 0;
    preSumMap[0] = 1; // sets zero in the map
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int remaining = sum - k;
        count += preSumMap[remaining]; // adds the count if remainig prefix sum exists
        preSumMap[sum] += 1;           // updates prefix sum count
    }
    return count;
}
int main()
{
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    cout << "The total number of subarrays whose sum is k is : "
         << subarraySumBruteForce(nums, k)
         << endl;
    return 0;
}

// BRUTE FORCE

// Time Compleity :
// TC is O(n^2), as we use nested loops and find all possible subarray and count.

// Space Complexity :
// SC is O(1), as we use no extra space.

// OPTIMAL APPROACH

// Time Complexity :
// TC is O(n) + O(logn) = O(n*logn), as we iterate once and every ordered map operation
// is O(logn) in best,average and worst case.
// NOTE* : If we use unordered_map the then the TC would be O(n*1) in best and average case,
//         and would be O(n*n) in worst case due to collisons.

// Space Complexity :
// SC is O(n), because in worst case there will be n prefix sum to be stored in map.