// First and Last Occurrence of an Element in a Sorted Array

// Problem Statement : Given an array of integers nums sorted in non-decreasing order,
// find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Solution :

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int first = -1;
    int last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1; // continue searching to the left for the first occurrence
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (first == -1)
    {
        return {-1, -1}; // if no first occurence exist then no last occurence exists either
    }
    low = 0; // resassigned low and high for finding last occurence
    high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1; // continue searching to the right for the last occurrence
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return {first, last};
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "First Occurrence: " << result[0] << endl
         << "Last Occurrence : " << result[1] << endl;
    return 0;
}

// Time Complexity and Space Complexity:

//    - Time Complexity : O(log N)
//        The binary search for first occurence and the binary search for last occurence
//        are both O(log N).
//        Hence, total time is O(log N + log N) = O(log N).

//    - Space Complexity : O(1)
//      No extra space is used.
