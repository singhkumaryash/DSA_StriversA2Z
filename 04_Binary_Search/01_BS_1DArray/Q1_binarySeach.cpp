// Binary Search

// Problem Statement : Given an array of integers nums which is sorted in ascending order,
// and an integer target, write a function to search target in nums. If target exists, then
// return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// Binary Search
int binarySearch(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
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

// Binary Search Using Recursion
int recursiveBinarySearchHelper(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] > target)
    {
        return recursiveBinarySearchHelper(nums, low, mid - 1, target);
    }
    else
    {
        return recursiveBinarySearchHelper(nums, mid + 1, high, target);
    }
}

int recursiveBinarySearch(vector<int> &nums, int target)
{
    return recursiveBinarySearchHelper(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    int target1 = 6;
    int index1 = binarySearch(nums1, target1);
    if (index1 != -1)
    {

        cout << "The target " << target1 << " is found at index " << index1 << endl;
    }
    else
    {
        cout << "The target " << target1 << " is not found. " << endl;
    }
    vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    int target2 = 9;
    int index2 = recursiveBinarySearch(nums2, target2);
    if (index2 != -1)
    {

        cout << "The target " << target2 << " is found at index " << index2 << endl;
    }
    else
    {
        cout << "The target " << target2 << " is not found. " << endl;
    }

    return 0;
}

// Binary Search – Time and Space Complexity Analysis

// 1. Iterative Binary Search:
//    - Time Complexity: O(log N)  ~log base 2
//        Each iteration halves the search space.
//        Runs in logarithmic time with respect to the number of elements.
//    - Space Complexity (excluding output): O(1)
//        Constant space used – no extra memory except loop variables.
//    - Note: Most efficient approach with minimal memory usage.

// 2. Recursive Binary Search:
//    - Time Complexity: O(log N)  ~log base 2
//        Same halving logic as iterative approach.
//    - Space Complexity (excluding output): O(log N)
//        Due to recursive call stack – one frame for each level of recursion.
//    - Note: Elegant but uses more memory due to recursion.
//            Can cause stack overflow for very large input sizes.
