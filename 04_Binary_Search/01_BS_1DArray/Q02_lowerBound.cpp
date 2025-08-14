// Implement Lower Bound

// Problem Statement : Given a sorted array of N integers and an integer x, write a program
// to find the lower bound of x.

// The lower bound is the smallest index, where arr[index] >= x. But if any such index is
// not found, the lower bound algorithm returns n i.e. size of the given array.

// Input Format: N = 5, arr[] = {}, x = 9
// Result: 3
// Explanation: Index 3 is the smallest index such that arr[3] >= x.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// BRUTE FORCE (Linear Search)
int lowerBoundBruteForce(vector<int> &nums, int x)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= x)
        {
            return i;
            ;
        }
    }
    return n;
}

// OPTIMAL APPROACH (Binary Search)
int lowerBound(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int index = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= x)
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
    int x = 9;
    cout << "The lower bound is the index " << lowerBound(nums, x) << endl;
    return 0;
}

// LOwer Bound – Time and Space Complexity Analysis

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