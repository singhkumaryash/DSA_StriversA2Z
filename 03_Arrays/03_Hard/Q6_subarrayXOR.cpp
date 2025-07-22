// Count the number of subarrays with given xor K

// Problem Statement : Given an array of integers A and an integer B. Find the total number
// of subarrays having bitwise XOR of all elements equal to k.

// Input Format: A = [4, 2, 2, 6, 4] , k = 6
// Result: 4
// Explanation: The subarrays having XOR of their elements as 6 are
//              [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

// Solution

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// BRUTE FORCE
int subarraysWithXORBruteForce(vector<int> nums, int k)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int XOR = 0;
        for (int j = i; j < nums.size(); j++)
        {
            XOR ^= nums[j];

            if (XOR == k)
            {
                count++;
            }
        }
    }
    return count;
}

// OPTIMAL APPROACH
int subarraysWithXOROptimal(vector<int> nums, int k)
{
    map<int, int> mpp;
    int count = 0;
    int xorr = 0;
    mpp[xorr]++;
    for (int i = 0; i < nums.size(); i++)
    {
        xorr = xorr ^ nums[i];
        int required = xorr ^ k; // similar to presum
        count += mpp[required];  // adds the frequency of required xor if it exists
        mpp[xorr]++;             // stores xor and it's frequency in the map
    }
    return count;
}

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    vector<int> nums2 = {2, 1, 2, 3};
    cout << "The numer of subarrays having XOR of their elements as "
         << k << " are " << subarraysWithXOROptimal(nums, 6) << endl;

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
// SC is O(n), because in worst case there will be n required xor to be stored in map.