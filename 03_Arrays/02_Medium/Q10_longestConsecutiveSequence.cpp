// Longest Consecutive Sequence in an Array

// Problem Statement : You are given an array of ‘N’ integers. You need to find the length
// of the longest sequence which contains the consecutive elements.

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its
// length is 4.

// Solution :

#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;

bool linearSearch(vector<int> nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return true;
        }
    }
    return false;
}

// Brute Force
int longestConsecutiveBruteForce(vector<int> nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int longest = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        int count = 1;
        while (linearSearch(nums, x + 1) == true)
        {
            x++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}

// Better Approach
int longestConsecutiveBetter(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int currentCounter = 0;
    int lastSmallest = INT_MIN;
    int longest = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] - 1 == lastSmallest)
        {
            currentCounter++;
            lastSmallest = nums[i];
        }
        else if (lastSmallest != nums[i])
        {
            currentCounter = 1;
            lastSmallest = nums[i];
        }
        longest = max(longest, currentCounter);
    }
    return longest;
}

// Optimal Approach
int longestConsecutiveOptimal(vector<int> nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << "The length of the longest sequence which contains the consecutive elements is "
         << longestConsecutiveBetter(arr) << endl;
    cout << "The length of the longest sequence which contains the consecutive elements is "
         << longestConsecutiveBruteForce(arr) << endl;
    cout << "The length of the longest sequence which contains the consecutive elements is "
         << longestConsecutiveOptimal(arr) << endl;

    return 0;
}

// Brute Force :
//    - Time Complexity: O(n^2) as we iterate and search linearly.
//
//    - Space Complexity: O(1), constant space complexity.

// Better Approach (Sorting):
//    - Time Complexity: O(n log n) + O(n) = O(n log n)
//         - O(n log n) for sorting the array.
//         - O(n) to traverse the sorted array once.
//
//    - Space Complexity: O(1) if sorting in-place, else O(n) if sort uses auxiliary space.

// Optimal Approach (Using Unordered Set):
//    - Time Complexity: O(N) + O(2*N) ≈ O(3*N) ~ O(N), where N = size of array
//         - O(N) for inserting all elements into the unordered_set.
//         - For each start of a sequence, we only traverse each number once.
//         - Overall each number is visited at most twice.
//         - *If we use set (instead of unordered_set), time complexity becomes O(N log N)
//            due to O(log N) time for insert/find in set.
//
//    - Space Complexity: O(N) for storing elements in the unordered_set.
