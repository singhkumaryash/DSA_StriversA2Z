// Problem Statement : Given an array of integers nums, return the value
// of the largest element in the array

// Input: nums = [3, 3, 0, 99, -40]
// Output: 99
// Explanation: The largest element in array is 99

#include <bits/stdc++.h>
using namespace std;
int largestElement(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > ans)
        {
            ans = nums[i];
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {0, 1, 7, 1, 4, 4, 6, 9, 8, 7};
    cout << "Largest element in the array is: " << largestElement(nums) << endl;
    return 0;
}

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of space.