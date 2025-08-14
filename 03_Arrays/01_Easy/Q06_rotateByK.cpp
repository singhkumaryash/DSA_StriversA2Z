// Rotate array by K elements

// Problem Statement: Given an array of integers, rotating array of elements
// by k elements towards left.

// Input: N = 7, array[] = {1,2,3,4,5,6,7} , k=2 , right
// Output: 6 7 1 2 3 4 5
// Explanation: array is rotated to right by 2 position .

// Solution :

#include <bits/stdc++.h>
using namespace std;
void rotateArray(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[i];
    };
    for (int i = k; i < n; i++)
    {
        nums[i - k] = nums[i];
    };

    for (int i = n - k; i < n; i++)
    {
        nums[i] = temp[i - (n - k)];
    };
}
void rotateByK(vector<int> &nums, int k)
{

    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
};
int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7};
    cout << "Array befor rotating : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    rotateByK(arr, 6);
    cout << "Array after rotating : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;

    return 0;
}
// BRUTE FORCE :
// Time Complexity:
// O(n), where n is the size of the input array.
// - Copy first k elements to temp           -> O(k)
// - Shift the remaining (n - k) elements    -> O(n - k)
// - Copy temp[] back to the end             -> O(k)
// Total: O(k + (n - k) + k) = O(n)

// Space Complexity:
// O(k), because a temporary array of size k is used to store the first k elements.

// OPTIMAL :
// Time Complexity:
// O(n), where n is the number of elements in the array.
// - reverse(nums.begin(), nums.begin() + k)   -> O(k)
// - reverse(nums.begin() + k, nums.end())     -> O(n - k)
// - reverse(nums.begin(), nums.end())         -> O(n)
// Total: O(k + (n - k) + n) = O(2n) = O(n)

// Space Complexity:
// O(1), constant extra space is used for in-place swaps during reversal.
// No additional array or data structure is used.
