// K-th Element of two sorted arrays

// Problem Statement : Given two sorted arrays of size m and n respectively, you are tasked with finding
// the element that would be at the kth position of the final sorted array.

// Input: 'arr1' = [2, 3, 45], 'arr2' = [4, 6, 7, 8] and 'k' = 4
// Output: 6
// Explanation: The merged array will be [2, 3, 4, 6, 7, 8, 45]. The element at position '4' of this array
// is 6. Hence we return 6.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm> // for max and min functions
#include <climits>   // for INT_MIN and INT_MAX
using namespace std;

// Approach : Using Merge but not using extra space
// Time Complexity: O(m + n), where m and n are the sizes of the two arrays.
// Space Complexity: O(1), as we are not using any extra space for merging.
// This approach is similar to the merge sort but avoids using an extra array to store the merged array.
int findKthElement(vector<int> &nums1, vector<int> &nums2, int k)
{
    int i = 0;
    int j = 0;

    int count = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            if (count == k - 1)
            {
                return nums1[i];
            }

            i++;
            count++;
        }

        else
        {
            if (count == k - 1)
            {
                return nums2[j];
            }
            j++;
            count++;
        }
    }
    while (i < nums1.size())
    {
        if (count == k - 1)
        {
            return nums1[i];
        }
        i++;
        count++;
    }
    while (j < nums2.size())
    {
        if (count == k - 1)
        {
            return nums2[j];
        }

        j++;
        count++;
    }
}

// Optimal Approach : Using Binary Search
// NOTE* : The approach is similar to finding the median of two sorted arrays.
int kthElement(vector<int> &nums1, vector<int> &nums2, int n, int m, int k)
{
    if (m > n)
        return kthElement(nums2, nums1, m, n, k);
    int low = max(0, k - m);
    int high = min(k, n);
    int left = k;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN; // left part of nums1
        int l2 = INT_MIN; // left part of nums2
        int r1 = INT_MAX; // right part of nums1
        int r2 = INT_MAX; // right part of nums2
        if (mid1 < n)
        {
            r1 = nums1[mid1];
        }
        if (mid2 < m)
        {
            r2 = nums2[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            l1 = nums1[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = nums2[mid2 - 1];
        }
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2); // k-th elemnt
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return -1; // dummy return
}

// OPTIMAL APPROACH : Time and Space Complexity

//    - Time Complexity : O(log min(n1, n2)); where n1 and n2 are the sizes of the two arrays.
//        The binary search is performed on the smaller of the two arrays, hence the time complexity
//        is logarithmic in the size of the smaller array.
//        THerefore, total time is  O(log min(n1, n2)).

//    - Space Complexity : O(1)
//        No extra space is used.