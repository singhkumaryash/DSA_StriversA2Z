// Problem Statement: Given an array, find the second smallest and second largest
// element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

// Input: [1,2,4,7,7,5]
// Output: Second Smallest : 2
// 	    Second Largest  : 5
// Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest
// of these is 5 and second smallest is 2

// Solution :

#include <bits/stdc++.h>
using namespace std;

int secondSmallest(vector<int> &arr)
{
    if (arr.size() < 2)
        return -1;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        if (arr[i] != smallest && arr[i] < secondSmallest)
        {
            secondSmallest = arr[i];
        }
    }
    return secondSmallest;
}
int secondLargest(vector<int> &arr)
{
    if (arr.size() < 2)
        return -1;
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        if (arr[i] != largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main()
{
    vector<int> arr = {1, 7, 11, 12};

    int sS = secondSmallest(arr);
    int sL = secondLargest(arr);
    cout << "Second smallest is " << sS << endl;
    cout << "Second largest is " << sL << endl;
    return 0;
}

// Time Complexity :
// TC is O(n) + O(n) = O(n), where n is the number of elements in the array.

// Space Complexity :
// SC is O(1), as we are using a constant amount of space.
