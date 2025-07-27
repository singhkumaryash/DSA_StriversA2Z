// Floor and Ceil in Sorted Array

// Problem Statement: You are given an sorted array arr of n integers and an integer x.
// Find the floor and ceiling of x in arr[0..n-1].The floor of x is the largest element
// in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
// Result: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// Solution:

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1;
    int floor = -1, ceil = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == x)
        {
            return {x, x}; // both floor and ceil are x
        }
        else if (nums[mid] < x)
        {
            floor = nums[mid]; // can be floor
            low = mid + 1;
        }
        else
        {
            ceil = nums[mid]; // can be ceil
            high = mid - 1;
        }
    }

    return {floor, ceil};
}

int main()
{
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;
    pair<int, int> result = getFloorAndCeil(nums, x);
    cout << "Floor: " << result.first << ", Ceil: " << result.second << endl;
    return 0;
}

// Time Complexity and Space Complexity:

//    - Time Complexity : O(log N)
//        The binary search for floor and the binary search for ceil are both O(log N).
//        Hence, total time is O(log N + log N) = O(log N).

//    - Space Complexity : O(1)
//      No extra space is used, only a few variables are used for calculations.
