// Implement Upper Bound

// Problem Statement : Given a sorted array of N integers and an integer x, write a program to
// find the upper bound of x.

// The upper bound is the smallest index, where arr[index] > x. But if any such index is
// not found, the upper bound algorithm returns n i.e. size of the given array.

// Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
// Result: 4
// Explanation: Index 4 is the smallest index such that arr[4] > x.

//  Solution :

#include <iostream>
#include <vector>
using namespace std;

// BRUTE FORCE (Linear Search)
int upperBoundBruteForce(vector<int> &nums, int x)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > x)
        {
            return i;
            ;
        }
    }
    return n;
}

// OPTIMAL APPROACH (Binary Search)
int upperBound(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int index = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > x)
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
    vector<int> nums = {3, 5, 8, 15, 19};
    int x = 8;
    cout << "The upper bound is the index " << upperBound(nums, x) << endl;
    return 0;
}

// upper Bound – Time and Space Complexity Analysis

// 1. BRUTE FORCE (Linear Search)
//    - Time Complexity : O(N)
//        Single loop iterating through every element.
//    - Space Complexity : O(1)
//        Constant space used.

// 2. OPTIMAL APPROACH (Binary Search)
//    - Time Complexity : O(log N)
//        Each iteration halves the search space.
//        Runs in logarithmic time with respect to the number of elements.
//    - Space Complexity : O(1)
//        Constant space used.