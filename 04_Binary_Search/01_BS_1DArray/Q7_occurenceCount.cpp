// Count Occurrences in Sorted Array

// Problem Statement : You are given a sorted array containing N integers and a number X,
// you have to find the occurrences of X in the given array.

// Input:  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
// Output: 4
// Explanation: 3 is occurring 4 times in
// the given array so it is our answer.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// BRUTE FORCE
// Time Complexity  : O(n);
// Space Complexity : O(1);
int countOccurrencesBruteForce(vector<int> &nums, int target)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            count++;
        }
    }
    return count;
}

// OPTIMAL APPROACH (Binary Search)
int countOccurrences(vector<int> &nums, int target)
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
        return 0; // if no first occurence exist then no last occurence exists, thus count is 0
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
    return (last - first + 1);
}

int main()
{
    vector<int> nums = {2, 2, 3, 3, 3, 3, 4};
    int target = 3;
    cout << target << " occurs " << countOccurrences(nums, target) << " times in the array." << endl;
    return 0;
}

// OPTIMAL APPROACH : Time and Space Complexity

//    - Time Complexity : O(log N)
//        The binary search for first occurence and the binary search for last occurence
//        are both O(log N).
//        Hence, total time is O(log N + log N) = O(log N).

//    - Space Complexity : O(1)
//      No extra space is used.