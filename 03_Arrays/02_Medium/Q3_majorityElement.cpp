// Find the Majority Element that occurs more than N/2 times

// Problem Statement: Given an array of N integers, write a program to return an
// element that occurs more than N/2 times in the given array. You may consider
// that such an element always exists in the array

// Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}
// Result: 2
// Explanation: After counting the number of times each element appears and
// comparing it with half of array size, we get 2 as result

// Solution :

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Better Approach (Hashing)
int majorityElementHashing(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > nums.size() / 2)
        {
            return it.first;
        }
    }
    return -1;
}

// Optimal (Moone's voting algorithm)
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int element;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            element = nums[i];
        }
        else if (nums[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return element;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << "The majority element with more than n/2 occurences in the array is "
         << majorityElement(arr) << endl;
    cout << "The majority element with more than n/2 occurences in the array is "
         << majorityElementHashing(arr) << endl;
    return 0;
}

// 1. Better Approach (Hashing) :
//    - Time Complexity: O(n) in best and average case and O(n^2) in worst case.
//       Single pass through array
//       Each unordered_map operation is O(1) in best and average case and O(n)
//       in worst case due to collisions.
//       *If we use map instead of unordered_map, the time complexity will be O(N*logN)
//        as the map data structure takes O(logn) time to find an element.
//
//    - Space Complexity: O(n)
//       map stores the element and their counter.

// 2. Optimal (Moone's Voting Algorithm) :
//    - Time Complexity: O(n)
//       Single pass through array
//
//    - Space Complexity: O(1)
//       No extra data structures used

// NOTE :
// - Moore's Voting Algorithm only works when the majority element is guaranteed to
//   exist (i.e., appears > n/2 times). Otherwise, for validation when the majority
//   element may or may not exist, a second pass is needed to confirm.
