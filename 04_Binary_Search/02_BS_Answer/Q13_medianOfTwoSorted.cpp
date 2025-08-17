// Median of Two Sorted Arrays of different sizes

// Problem Statement : Given two sorted arrays arr1 and arr2 of size m and n respectively,
// return the median of the two sorted arrays. The median is defined as the middle value
// of a sorted list of numbers. In case the length of the list is even, the median is the
// average of the two middle elements.

// Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
// Result: 3.5
// Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length
// of the merged list is even, the median is the average of the two middle elements. Here two
// medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

// Solution :

#include <iostream>
#include <vector>
#include <climits>   // for INT_MIN and INT_MAX
#include <algorithm> // for max and min functions
using namespace std;

// NOTE * => All three solutions are 100% on LeetCode and are accepted.

// Approach 1: Merge both arrays and find the median
// Time Complexity: O(m + n), where m and n are the sizes of the two arrays.
// Space Complexity: O(m + n), for storing the merged array.
double findMedianUsingMergeVector(vector<int> &nums1, vector<int> &nums2)
{
    vector<double> mergedArray;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            mergedArray.push_back(nums1[i]);
            i++;
        }
        else
        {
            mergedArray.push_back(nums2[j]);
            j++;
        }
    }
    while (i < nums1.size())
    {
        mergedArray.push_back(nums1[i]);
        i++;
    }
    while (j < nums2.size())
    {
        mergedArray.push_back(nums2[j]);
        j++;
    }
    if (mergedArray.size() % 2 == 0)
    {
        double median = (mergedArray[mergedArray.size() / 2] + mergedArray[(mergedArray.size() / 2) - 1]) / 2.0;
        return median;
    }
    else
    {
        return mergedArray[mergedArray.size() / 2];
    }
}

// Approach 2: Using Merge but not using extra space
// Time Complexity: O(m + n), where m and n are the sizes of the two arrays.
// Space Complexity: O(1), as we are not using any extra space for merging.
// This approach is similar to the first one but avoids using an extra array to store the merged array.
double findMedianUsingMergeCount(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0;
    int j = 0;
    int index1 = (((nums1.size() + nums2.size()) / 2) - 1);
    int index2 = ((nums1.size() + nums2.size()) / 2);
    double element1 = -1;
    double element2 = -1;
    int count = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            if (count == index1)
            {
                element1 = nums1[i];
            }
            if (count == index2)
            {
                element2 = nums1[i];
            }
            i++;
            count++;
        }
        else
        {
            if (count == index1)
            {
                element1 = nums2[j];
            }
            if (count == index2)
            {
                element2 = nums2[j];
            }
            j++;
            count++;
        }
    }
    while (i < nums1.size())
    {
        if (count == index1)
        {
            element1 = nums1[i];
        }
        if (count == index2)
        {
            element2 = nums1[i];
        }
        i++;
        count++;
    }
    while (j < nums2.size())
    {
        if (count == index1)
        {
            element1 = nums2[j];
        }
        if (count == index2)
        {
            element2 = nums2[j];
        }
        j++;
        count++;
    }

    if (((nums1.size() + nums2.size()) % 2) == 1)
    {
        return element2;
    }
    else
    {
        return (element1 + element2) / 2.0;
    }
}

// OPTIMAL APPROACH: Binary Search
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2) // if n1 is bigger swap the arrays:
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int n = n1 + n2; // total length of both arrays

    int low = 0;
    int high = n1;
    int left = (n1 + n2 + 1) / 2; // length of left half
    // Binary search on the smaller array
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN; // left part of nums1
        int l2 = INT_MIN; // left part of nums2
        int r1 = INT_MAX; // right part of nums1
        int r2 = INT_MAX; // right part of nums2
        if (mid1 < n1)
        {
            r1 = nums1[mid1];
        }
        if (mid2 < n2)
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

        if (l1 <= r2 && l2 <= r1) // check if valid partition
        {
            // Odd length → median is max of left side
            if (n % 2 == 1)
                return max(l1, l2);

            // Even length → median is average of max(left) and min(right)
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        // If l1 is too big, move partition left
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }

        // If l2 is too big, move partition right
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << findMedianSortedArrays(a, b) << endl;
}

// OPTIMAL APPROACH : Time and Space Complexity

//    - Time Complexity : O(log min(n1, n2)); where n1 and n2 are the sizes of the two arrays.
//        The binary search is performed on the smaller of the two arrays, hence the time complexity
//        is logarithmic in the size of the smaller array.
//        THerefore, total time is  O(log min(n1, n2)).

//    - Space Complexity : O(1)
//        No extra space is used.