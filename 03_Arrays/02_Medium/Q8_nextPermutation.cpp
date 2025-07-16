// Next Permutation

// A permutation of an array of integers is an arrangement of its members into a sequence
// or linear order.

// The next permutation of an array of integers is the next lexicographically greater
// permutation of its integer. More formally, if all the permutations of the array are
// sorted in one container according to their lexicographical order, then the next
// permutation of that array is the permutation that follows it in the sorted container.
// If such arrangement is not possible, the array must be rearranged as the lowest possible
// order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a
// lexicographical larger rearrangement.

// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int i = nums.size() - 2;
    int breakpoint = -1;
    while (i >= 0)
    {
        if (nums[i] < nums[i + 1])
        {
            breakpoint = i;
            break;
        }
        i--;
    }
    if (breakpoint == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int j = nums.size() - 1; j > breakpoint; j--)
    {
        if (nums[j] > nums[breakpoint])
        {
            swap(nums[j], nums[breakpoint]);
            break;
        }
    }
    reverse(nums.begin() + breakpoint + 1, nums.end());
}

int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    cout << "Array : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    nextPermutation(arr);
    cout << "Next Permutation : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    next_permutation(nums.begin(), nums.end()); // stl function
    cout << "Using Stl : {";
    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    return 0;
}

// Time Complexity :
// TC is O(3N), where N = size of the given array
// Finding the break-point, finding the next greater element, and reversal at the end
// takes O(N) for each, where N is the number of elements in the input array. This sums
// up to 3*O(N) which is approximately O(3N).

// Space complexity :
// SC is O(1); constant space complexity.