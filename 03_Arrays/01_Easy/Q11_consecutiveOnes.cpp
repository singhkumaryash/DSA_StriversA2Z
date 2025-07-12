// Count Maximum Consecutive One's in the array

// Problem Statement: Given an array that contains only 1 and 0 return the count
// of maximum consecutive ones in the array.

// Input: prices = {1, 1, 0, 1, 1, 1}
// Output: 3
// Explanation: There are two consecutive 1’s and three consecutive 1’s in the
// array out of which maximum is 3.

// Solution :

#include <iostream>
using namespace std;

int findMaxConsecutiveOnes(int nums[], int n)
{
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        if (nums[i] == 0)
        {
            maxCount = max(maxCount, count);
            count = 0;
        }
    }
    maxCount = max(maxCount, count);
    return maxCount;
}

int main()
{
    int arr[] = {0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The maximum consecutive one(s) in the array is(are) : " << findMaxConsecutiveOnes(arr, n);
    cout << endl;
    return 0;
}

// Time Complexity :
// TC is O(n) as we traverse the array once using a single for loop.
// Where n is the number of elements in the array.

// Space Complexity :
// TC is O(1) as we no extra space or data structures are used.
// Thus, space complexity is constant O(1).
