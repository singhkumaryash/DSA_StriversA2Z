// Find the Smallest Divisor Given a Threshold

// Problem Statement : You are given an array of integers 'nums' and an integer i.e. a threshold
// value 'threshold'. Your task is to find the smallest positive integer divisor, such that upon
// dividing all the elements of the given array by it, the sum of the division's result is less
// than or equal to the given threshold value.

// Input Format: N = 5, arr[] = {1,2,3,4,5}, limit = 8
// Result: 3
// Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor.
// The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all the elements
// of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is equal to 7 <= 8 i.e. the
// threshold value. So, 3 is the minimum possible answer.

// Solution :

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// check if the given divisor is possible solution or not
bool isPossible(vector<int> &nums, int threshold, int divisor)
{
    long long sum = 0;
    for (auto it : nums)
    {
        sum += ceil((double)it / divisor); // double to avoid integer division before ceil
    }
    if (sum <= threshold)
        return true;
    else
        return false;
}

// find maximum of nums array 
int maxOfNums(vector<int> &nums)
{
    int ans = INT_MIN;
    for (auto it : nums)
    {
        ans = max(ans, it);
    }
    return ans;
}

// to find smallest divisor
int smallestDivisor(vector<int> &nums, int threshold)
{
    int low = 1;
    int high = maxOfNums(nums);
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(nums, threshold, mid) == true)
        {
            ans = mid; // if possible store answer and move to left to find minimum
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int threshold = 8;
    cout << "Smallest Divisor : " << smallestDivisor(nums, threshold) << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N + (N * log(max(nums)))
//        To find maximum of the array is O(N).
//        Everytime we check if a divisor is a possible solution taking O(N).
//        Rest to calculate smallest divisor we use binary search from 1 to
//        maximum of the array taking O(log(max(nums)).

//    - Space Complexity : O(1)
//        No extra space is used.

// NOTE : Brute force would be to use linear search instead of binary search in
//        smallest divisor function, rest same.
