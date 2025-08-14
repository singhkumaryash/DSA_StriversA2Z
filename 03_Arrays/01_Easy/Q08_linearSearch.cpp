// Linear Search

// Problem Statement : Given an array, and an element num the task is to find
// if target is present in the given array or not. If present print the index
// of the element or print -1.

// Input: arr[]= 1 2 3 4 5, target = 3
// Output: 2
// Explanation: 3 is present in the 2nd index

// Solution :

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
};

int main()
{
    vector<int> arr = {1, 7, 8, 2, 4, 9, 0, 2, 11};
    int target = 0;
    int index = linearSearch(arr, target);
    if (index == -1)
    {
        cout << "The element " << target << " is not present in the array." << endl;
    }
    cout << "The element " << target << " is present at index " << index << endl;

    return 0;
}

// Time Complexity :
// TC is O(n), where n is the number of elements in the array.
// As we iterates through the array once  to find target.

// Space Complexity :
// SC is O(1), constant space complexity.