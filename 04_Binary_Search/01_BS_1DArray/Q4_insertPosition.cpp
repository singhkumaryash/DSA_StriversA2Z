// Search Insert Position

// Problem Statement : You are given a sorted array arr of distinct values and a target value x.
// You need to search for the index of the target value in the array.

// If the value is present in the array, then return its index. Otherwise, determine the index
// where it would be inserted in the array while maintaining the sorted order.

// Input Format: arr[] = {1,2,4,7}, x = 6
// Result: 3
// Explanation: 6 is not present in the array. So, if we will insert 6 in the
// 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

//  Solution :

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int index = nums.size();
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) // the if and else if conditions can be merged together too
        {
            index = mid;
            return index;
        }
        else if (nums[mid] > target)
        {
            index = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {1, 2, 4, 7};
    int target = 6;
    int result = searchInsert(nums, target);
    cout << "The index of the target value is: " << result << endl;

    // STL function can also be used to find the position
    // int pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    // cout << "The index of the target value is: " << pos << endl;

    return 0;
}

// Time Complexity and Space Complexity:

//    - Time Complexity : O(log N)
//        Each iteration halves the search space.
//        Runs in logarithmic time with respect to the number of elements.
//    - Space Complexity : O(1)
//        Constant space used.