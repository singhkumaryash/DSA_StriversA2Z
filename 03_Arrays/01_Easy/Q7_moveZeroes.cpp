// Move all Zeros to the end of the array

// Problem Statement : You are given an array of integers, your task is to move
// all the zeros in the array to the end of the array and move non-negative
// integers to the front by maintaining their order.

// Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
// Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
// Explanation: All the zeros are moved to the end and non-negative integers are
// moved to front by maintaining order.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{

    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 0, 3, 0, 5, 6, 7};
    cout << "Array before moving zeroes : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    moveZeroes(arr);
    cout << "Array after moving zeroes  : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;

    return 0;
}

// Time Complexity :
// TC is O(n), where n is the size of array. As we iterate through the array once
// and do constant time operation in that.

// Space Comlexity :
// SC is O(1)  constant extra space is used for in-place swaps during traversal.
// No additional array or data structure is used.
