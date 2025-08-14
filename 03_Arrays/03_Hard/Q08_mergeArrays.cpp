// Merge two Sorted Arrays Without Extra Space

// Problem statement : Given two sorted arrays arr1[] and arr2[] of sizes n and m in
// non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains
// the first N elements and modify arr2 so that it contains the last M elements.

// Input:
// n = 4, arr1[] = [1 4 8 10]
// m = 5, arr2[] = [2 3 9]

// Output:
// arr1[] = [1 2 3 4]
// arr2[] = [8 9 10]

// Explanation: After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeBruteForce(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0;
    int j = 0;
    vector<int> merged;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            merged.push_back(nums1[i]);
            i++;
        }
        else
        {
            merged.push_back(nums2[j]);
            j++;
        }
    }
    while (i < m)
    {
        merged.push_back(nums1[i]);
        i++;
    }
    while (j < n)
    {
        merged.push_back(nums2[j]);
        j++;
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < m)
            nums1[i] = merged[i];
        else
            nums2[i - m] = merged[i];
    }
}

// OPTIMAL 1 TWO POINTERS APPROACH
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = m - 1;
    int right = 0;
    while (left >= 0 && right < n)
    {
        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            right++;
            left--;
        }
        else
        {
            break;
        }
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

// OPTIMAL 2 USING GAP METHOD
void mergeUsingGap(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int total = m + n;
    int gap = (total + 1) / 2;
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < total)
        {
            if (left < m && right < m)
            {
                if (nums1[left] > nums1[right])
                {
                    swap(nums1[left], nums1[right]);
                }
            }
            else if (left < m && right >= m)
            {
                if (nums1[left] > nums2[right - m])
                {
                    swap(nums1[left], nums2[right - m]);
                }
            }
            else if (left >= m && right >= m)
            {
                if (nums2[left - m] > nums2[right - m])
                {
                    swap(nums2[left - m], nums2[right - m]);
                }
            }
            left++;
            right++;
        }
        if (gap == 1) // Important to break when gap is 1 to avoid infinite loop
            break;
        gap = (gap + 1) / 2;
    }
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {0, 2, 6, 8, 9};
    mergeUsingGap(nums1, nums1.size(), nums2, nums2.size());
    cout << "Merged Arrays: " << endl;
    cout << "nums1 : ";
    cout << "{ ";
    for (auto it : nums1)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    cout << "nums2 : " << "{ ";
    for (auto it : nums2)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    return 0;
}

// BRUTE FORCE APPROACH

// Time Complexity :
// TC is O((n + m) + (n + m)), for traversing and adding to sorted array and then
// placing back in the array.

// Space Complexity :
// SC is O(n + m), additional space used for creating the merged array.


// OPTIMAL APPROACH 1 (Two-Pointer + Sort)

// Time Complexity :
// TC is O(min(n, m) + n*log(n) + m*log(m)) ≈ O(n*log(n) + m*log(m)),
// as we swap elements using two pointers and sort both arrays individually.

// Space Complexity :
// SC is O(1), as merging and sorting is done in-place without using extra space.


// OPTIMAL APPROACH 2 (Gap Method / Shell Sort Inspired)

// Time Complexity :
// TC is O((n + m) * log(n + m)), due to gap method where gap reduces by half each iteration,
// and at most the inner loop can run for O(n + m).

// Space Complexity :
// SC is O(1), as the merging is done in-place without any extra space.
