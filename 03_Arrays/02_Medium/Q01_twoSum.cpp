// Two Sum : Check if a pair with given sum exists in Array

// Problem Statement : Given an array of integers arr[] and an integer target.

// 1st variant: Return YES if there exist two numbers such that their sum is equal
// to the target. Otherwise, return NO.
// 2nd variant: Return indices of the two numbers such that their sum is equal to
// the target. Otherwise, we will return {-1, -1}.

// Note: You are not allowed to use the same element twice. Example: If the target
// is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

// Solution  :

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Brute Force
vector<int> twoSumBruuteForce(vector<int> nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                cout << "YES! pair with given sum exists in array." << endl;
                return {i, j}; // Return indices of the two numbers
            }
        }
    }
    cout << "NO! pair with given sum does not exists in array" << endl;
    return {-1, -1}; // Return {-1, -1} if no such pair exists
}

// Better Approach (Hashing)
vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mpp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        if (mpp.find(rem) != mpp.end())
        {
            ans.push_back(i);
            ans.push_back(mpp[rem]);
            cout << "YES! pair with given sum exists in array." << endl;
            return ans;
        }
        mpp[nums[i]] = i;
    }
    ans.push_back(-1);
    ans.push_back(-1);
    cout << "NO! pair with given sum does not exists in array" << endl;
    return ans;
}

// Optimal Approach (Two Pointer Technique) *only for sorted arrays or when to return yes or no*
string twoSumOptimal(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        if (nums[left] + nums[right] == target)
        {
            return "YES! pair with given sum exists in array.";
        }
        else if (nums[left] + nums[right] < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return "NO! pair with given sum does not exists in array";
}
int main()
{
    //    Brute Force Approach
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> result = twoSumBruuteForce(arr, target);
    cout << "Indices of the two numbers with given sum : { ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << "}" << endl;

    // Better Approach (Hashing)
    vector<int> arr2 = {0, 2, 6, 5, 4, 7, 1};
    int target2 = 11;
    vector<int> result2 = twoSum(arr2, target2);
    cout << "Indices of the two numbers with given sum : { ";
    for (auto it : result2)
    {
        cout << it << " ";
    }
    cout << "}" << endl;

    // Optimal (Only for Yes or No or sorted arrays)
    cout << twoSumOptimal(arr, target) << endl;
    return 0;
}

// 1. Brute Force Approach :
//    - Time Complexity: O(n^2)
//       Two nested loops traverse and check all possible pairs.
//    - Space Complexity: O(1)
//       No extra data structures used

// 2. Better Approach (Hashing) :
//    - Time Complexity: O(n*logn)
//       Single pass through array
//       Each map operation is O(log n)
//       *If we use unordered_map instead of map, the time complexity will be O(N*1)
//        as the unordered_map data structure takes O(1) time to find an element.
//        But in worst case it goes O(n) creating overall complexity of O(n^2).
//    - Space Complexity: O(n)
//       map stores the element with key as index.

// 2. Optimal (Two Pointer) *only for sorted arrays* :
//    - Time Complexity: O(n)+O(n*logn)
//       Single pass through array
//       Sorting algorithm takes O(nlog n) to sort.
//    - Space Complexity: O(1)
//       No extra data structures used

// NOTE : Hashing is the optimal solution for unsorted arrays.
//        Two pointer is the optimal solution for sorted arrays.