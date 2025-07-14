// Sort an array of 0s, 1s and 2s

// Problem Statement: Given an array consisting of only 0s, 1s, and 2s.
// Write a program to in-place sort the array without using inbuilt sort functions.
// ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// Dutch National Flag Algorithm
// 0 <-> low-1    : Sorted 0s
// low <-> mid-1  : Sorted 1s
// mid <-> high   : Unsorted 0/1/2s
// high+1 <-> n-1 : Sorted 2s
void sort(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    cout << "Original array : { ";
    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    sort(nums);
    cout << "Sorted array   : { ";
    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    return 0;
}

// Time Complexity :
// TC is O(n) because every condition in th loop sort one element at a time.

// Space Complexity :
// SC is O(1) because we are not using any extra space for sorting.

// NOTE :
// Using any sorting algorithm would have been O(nlogn) at best.
// Other approaches cab be counting the number of 0s, 1s, and 2s and then filling
// the array accordingly, but that would not be in-place sorting.