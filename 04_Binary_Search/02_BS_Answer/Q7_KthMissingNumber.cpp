// Kth Missing Positive Number

// Problem Statement : You are given a strictly increasing array 'arr' and a positive integer 'k'.
// Find the 'kth' positive integer missing from 'arr'.

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation : The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing
// positive integer is 9.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// BRUTE FORCE
int findKthPositiveBruteForce(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
            k++; // shifting k
        else
            break;
    }
    return k;
}
// Time Complexity  : O(n);
// Space Complexity : O(1);

// OPTIMAL (Using Binary Search)
int findKthPositive(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1); // counts how many numbers are missing before arr[mid]
        if (missing < k)
        {
            low = mid + 1; // kth missing is further to the right
        }
        else
        {
            high = mid - 1; // kth missing is to the left or at mid
        }
    }

    // The low and high will end up on opposite polarity.

    // After the loop, 'low' is the index where the kth missing number would fit in the array.
    // The number of missing elements before this index is less than k.
    // So, to find the actual kth missing number, we shift 'k' steps beyond this point.
    // Since 'low' represents how many values are present before this position in the array,
    // the kth missing number is at position 'low + k' in the natural number sequence.
    // Also, since low = high + 1, both (low + k) and (high + 1 + k) return the same value.

    // return (high + 1 + k); => (low-1) + 1 + k => low -1 + 1 + k;
    
    return low + k;
}

// NOTE :
// Edge case: if kth missing is before the first element (i.e., k < arr[0])
// The binary search still handles this correctly since high = -1 at end

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 1;
    cout << "The missing number is: " << findKthPositive(arr, k) << endl;
    return 0;
}

// Time and Space Complexity (OPTIMAL APPROACH)

//    - Time Complexity : O(log N)
//        Binary Search is used and each iteration reduces the search space by half.

//    - Space Complexity : O(1)
//        No extra space is used.
