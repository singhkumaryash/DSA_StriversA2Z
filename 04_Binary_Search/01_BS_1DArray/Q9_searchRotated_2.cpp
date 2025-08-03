// Search Element in Rotated Sorted Array II

// Problem Statement : Given an integer array arr of size N, sorted in ascending order
// (may contain duplicate values) and a target value k. Now the array is rotated at some
// pivot point unknown to you. Return True if k is present and otherwise, return False.

// Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
// Result: True
// Explanation: The element 3 is present in the array. So, the answer is True.

// Solution :

#include <iostream>
#include <vector>
using namespace std;
bool search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Case 1: Found the target
        if (nums[mid] == target)
            return true;

        // Case 2: Edge case when mid, low, and high are equal
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
            continue;
        }

        // Case 3: Left half is sorted
        if (nums[low] <= nums[mid])
        {
            // Check if target lies in the sorted left half
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
            {
                low = mid + 1;
            }
        }
        // Case 4: Right half is sorted
        else
        {
            // Check if target lies in the sorted right half
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
            {
                high = mid - 1;
            }
        }
    }

    // Target not found
    return false;
}
int main()
{

    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 7;

    cout << (search(nums, target) ? "Target Found!" : "Target Not Found!") << endl;
    return 0;
}

// Time and Space Complexity Analysis:

// - Time Complexity:
//     - Best/Average Case: O(log N)
//         When elements are mostly unique, binary search halves the space effectively.
//     - Worst Case: O(N)
//         When many elements are duplicates (e.g., nums[low] == nums[mid] == nums[high]),
//         the algorithm degrades to linear scan as we eliminate only one element per step.
//
// - Space Complexity: O(1)
//     - No extra space used — the algorithm operates in constant space.
