// Find out how many times the array has been rotated

// Problem Statement : Given an integer array arr of size N, sorted in ascending order
// (with distinct values). Now the array is rotated between 1 to N times which is unknown.
// Find how many times the array has been rotated.

// Input Format: arr = [4,5,6,7,0,1,2,3]
// Result: 4
// Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the
// array has been rotated 4 times.

// Solution :

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// OBSERVATION : The number of rotations is equal to the index of the smallest element in the rotated array.

int rotationCount(vector<int> &nums)
{

    int low = 0;
    int high = nums.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // When already sorted, the arr[low] will be the minimum and we store its index
        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            break; // when sorted and find minum, we can exit early
        }
        // left half is sorted
        else if (nums[low] <= nums[mid])
        {
            if (nums[low] < ans) // Check if the current low is the smallest and store its index
            {
                ans = nums[low];
                index = low;
            }
            // eliminate left half
            low = mid + 1;
        }
        // right half is sorted
        else
        {
            if (nums[mid] < ans) // Check if the current mid is the smallest and store its index
            {
                ans = nums[mid];
                index = mid;
            }
            // eliminate right half
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Array has been rotated " << rotationCount(nums) << " times." << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(log N)
//        Binary Search is used and each iteration reduces the search space by half.

//    - Space Complexity : O(1)
//        No extra space is used.