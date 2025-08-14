// Problem Statement: Given an integer array sorted in non-decreasing order,
// remove the duplicates in place such that each unique element appears only
// once. The relative order of the elements should be kept the same.
// If there are k elements after removing the duplicates, then the first k
// elements of the array should hold the final result. It does not matter
// what you leave beyond the first k elements.

// Note: Return k after placing the final result in the first k slots of the array.

// Input: arr[1,1,2,2,2,3,3]
// Output: arr[1,2,3,_,_,_,_]
// Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore
// return 3 after assigning [1,2,3] in the beginning of the array.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0;

    for (int j = 0; j < nums.size(); j++)
    {

        if (nums[i] != nums[j])
        {
            // swap(nums[++i], nums[j]); it is not a good practise to swap; as overwrite will save cost

            nums[++i] = nums[j]; // first we increment i then assign
        }
    }
    return i + 1; // 1 is added because size of array is last_index+1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 5, 6, 6, 7, 9, 9, 9, 9, 11};
    cout << removeDuplicates(nums) << endl;

    return 0;
}

// Time Complexity : 
// TC is O(n); where n is the number of element in the array.
// It is because we traverse the array once using for loop.

// Space Complexity :
// SC is O(1); constant space complexity.