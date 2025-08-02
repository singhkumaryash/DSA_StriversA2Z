// Search Element in a Rotated Sorted Array

// Problem Statement:
// Given an integer array 'arr' of size N, sorted in ascending order (with distinct values),
// and a target value 'k'. The array is rotated at some pivot point unknown to you.
// Find the index at which 'k' is present. If 'k' is not present, return -1.

// Input Example:
// arr = [4,5,6,7,0,1,2,3], k = 0
// Output: 4 (as 0 is present at index 4)

#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Elimination Method
// Directly use binary search while checking which half is sorted at each step.
int searchUsingElimination(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // If found
        if (arr[mid] == k)
            return mid;

        // Check if left half is sorted
        if (arr[low] <= arr[mid])
        {
            // Check if target lies in the left half
            if (arr[low] <= k && k <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else
        {
            // Check if target lies in the right half
            if (arr[mid] <= k && k <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1; // If not found
}

//  Approach 2: Pivot Method

// Standard binary search
int binarySearch(vector<int> &nums, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
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
    return -1;
}

// Find pivot index (smallest element's index)
int findPivot(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= nums[0])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

// Main search function using pivot
int search(vector<int> &nums, int target)
{
    int pivot = findPivot(nums);

    // If target lies in the second half
    if (target >= nums[pivot] && target <= nums[nums.size() - 1])
    {
        return binarySearch(nums, pivot, nums.size() - 1, target);
    }
    // Else target lies in the first half
    return binarySearch(nums, 0, pivot - 1, target);
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int k = 0;

    // ----- Approach 1 -----
    int index1 = searchUsingElimination(arr, k);
    cout << "[Approach 1] Elimination Method: ";
    if (index1 != -1)
        cout << "Element found at index: " << index1 << endl;
    else
        cout << "Element not found" << endl;

    // ----- Approach 2 -----
    int index2 = search(arr, k);
    cout << "[Approach 2] Pivot + Binary Search: ";
    if (index2 != -1)
        cout << "Element found at index: " << index2 << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

// Time and Space Complexity Analysis:

//  APPROACH 1 : Elimination Method

//    - Time Complexity : O(log N)
//        Binary Search is used and each iteration reduces the search space by half.

//    - Space Complexity : O(1)
//        No extra space is used.

//  APPROACH 2 : Pivot Method

//    - Time Complexity : O(log N)
//        Binary Search = O(log N) ; Find Pivot = O(log N)
//        Hence, total time is O(log N + log N) = O(log N).

//    - Space Complexity : O(1)
//        No extra space is used.