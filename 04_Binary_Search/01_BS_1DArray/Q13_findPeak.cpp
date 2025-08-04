// Peak element in Array

// Problem Statement : Given an array of length N. Peak element is defined as the element
// greater than both of its neighbors. Formally, if 'arr[i]' is the peak element,
// 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak
// element in the array. If there are multiple peak numbers, return the index of any peak number.

// Note: For the first element, the previous element should be considered as negative infinity
// as well as for the last element, the next element should be considered as negative infinity.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();

    // Edge Case : if the array has only one element
    if (n == 1 || (nums[0] > nums[1]))
    {
        return 0;
    }

    // Edge Case : if the array is sorted descending
    if (nums[0] > nums[1])
    {
        return 0;
    }

    // Edge Case : if the array is sorted ascending
    if (nums[n - 1] > nums[n - 2])
    {
        return n - 1;
    }

    // starting with 1 and n-2 to avoid out of bound
    int low = 1;
    int high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // peak element
        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
        {
            return mid;
        }
        // if the mid is on right side of the peak element
        else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
        {
            low = mid + 1;
        }

        // if the mid is on left side of the peak element
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << "Peak element index is: " << findPeakElement(nums) << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(log N)
//        Binary Search is used and each iteration reduces the search space by half.

//    - Space Complexity : O(1)
//        No extra space is used.