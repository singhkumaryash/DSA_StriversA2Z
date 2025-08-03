// Minimum in Rotated Sorted Array

// Problem Statement: Given an integer array arr of size N, sorted in ascending order
// (with distinct values). Now the array is rotated between 1 to N times which is unknown.
// Find the minimum element in the array.

// Input Format: arr = [4,5,6,7,0,1,2,3]
// Result: 0
// Explanation : Here, the element 0 is the minimum element in the array.

// Solution :

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // When already sorted, the arr[low] will be the minimum
        if (nums[low] <= nums[high])
        {
            ans = min(ans, nums[low]);
            break; // when sorted and find minum, we can exit early
        }
        // left half is sorted
        else if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            // eliminate left half
            low = mid + 1;
        }
        // right half is sorted
        else
        {
            ans = min(ans, nums[mid]);
            // eliminate right half
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element is: " << findMin(nums) << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(log N)
//        Binary Search is used and each iteration reduces the search space by half.

//    - Space Complexity : O(1)
//        No extra space is used.