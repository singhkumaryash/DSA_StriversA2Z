// Problem Statement: Given an array of size n, write a program to check if the
// given array is sorted in (ascending / Increasing / Non-decreasing) order or not.
// If the array is sorted then return True, Else return False.

// Note: Two consecutive equal values are considered to be sorted.

// Input: N = 5, array[] = {1,2,3,4,5}
// Output: True.
// Explanation: The given array is sorted i.e Every element in the array is smaller
// than or equals to its next values, So the answer is True.

// Solution :

#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &arr)
{

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
};

int main()
{
    vector<int> arr = {1, 0};
    cout << "The Array is " << (isSorted(arr) ? "Sorted." : "Not Sorted.") << endl;
    return 0;
}

// Time Complexity : 
// TC is O(n); where n is the number of element in the array.
// It is because we traverse the array once using for loop.

// Space Complexity :
// SC is O(1); constant space complexity.