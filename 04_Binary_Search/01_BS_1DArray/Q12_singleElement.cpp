// Search Single Element in a sorted array

// Problem Statement : Given an array of N integers. Every number in the array except one
// appears twice. Find the single number in the array.

// Input Format: arr[] = {1,1,2,2,3,3,4,5,5,6,6}
// Result: 4
// Explanation: Only the number 4 appears once in the array.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int low = 1;
    int high = nums.size() - 2;
    // Edge Case : Array with only one element
    if (nums.size() == 1)
    {
        return nums[0];
    }

    // Edge Case : Element at Index 0 is the single element
    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    // Edge Case : Element at Index (N-1) is the single element
    if (nums[nums.size() - 1] != nums[nums.size() - 2])
    {
        return nums[nums.size() - 1];
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // check if mid is the single element
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }

        // check if the single element is in the right half
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
            (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
        {
            low = mid + 1;
        }

        // if not on right then singple element is on the left half
        else
        {
            high = mid - 1;
        }
    }
    // dummy return statement
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << "Single element is: " << singleNonDuplicate(nums) << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(log N)
//        Binary Search is used and each iteration reduces the search space by half.

//    - Space Complexity : O(1)
//        No extra space is used.

// NOTE* : Other approaches like using for loop or xor is also possible,
// but they will be O(N) time complexity.