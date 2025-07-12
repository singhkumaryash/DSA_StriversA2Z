// Find the number that appears once, and the other numbers twice

// Problem Statement : Given a non-empty array of integers arr, every element appears
// twice except for one. Find that single one.

// Input Format: arr[] = {4,1,2,1,2}
// Result: 4
// Explanation : In this array, only element 4 appear once and the other elements appear
// twice. So, 4 is the answer.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans ^= nums[i];
    }
    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 1, 2, 4, 4, 8};
    cout << "The number that appears only once in the array is " << singleNumber(nums);
    cout << endl;
    return 0;
}

// Time Complexity :
// TC is O(n); as we traverse through array once and xor in constant time.

// Space Complexity :
// SC is O(1); constant space complexity as we use no extra space.

// NOTE :
// Brute Force:
//   - Use two loops to count each element → O(n^2)

// Better Approach:
//   - Use HashMap to count frequencies → O(n) time and O(n) space

// Optimal Approach (This code):
//   - XOR property: a ^ a = 0, and 0 ^ a = a
//   - All duplicates cancel out, leaving the unique element