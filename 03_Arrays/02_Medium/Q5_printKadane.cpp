// Kadane's Algorithm : Maximum Subarray Sum in an Array

// Problem Statement : Given an integer array nums, find the contiguous subarray
// (containing at least one number) which has the largest sum and returns its
// sum and prints the subarray.

// Input: arr = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6

// Solution :

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// OPTIMAL (Kadene's Algorithm)
void maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;
    long long sum = 0;
    int ansStart = -1;
    int ansEnd = -1;
    int start = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += nums[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << "The subarray with maximum sum is { ";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "}" << endl;
    cout << "The maximum sum is " << maxSum << endl;
}
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArray(arr);
    return 0;
}

// Time Complexity :
// TC is O(n), as we iterate through the array once only.

// Space Complexity :
// SC is O(1), as we use no extra space.

// NOTE : Brute force approach of using loops to iterate all possible
//        subarray and finding sum can be used too. But the time
//        complexity would be O(n^2).