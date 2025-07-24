// Count inversions in an array

// Problem Statement : Given an array of N integers, count the inversion of the
// array.

// What is an inversion of an array? Definition: for all i & j < size of array,
// if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// Input Format : N = 5, array[] = {5,4,3,2,1}
// Result : 10
// Explanation : we have a reverse sorted array and we will get the maximum inversions
// as for i < j we will always find a pair such that A[j] < A[i]. Example: 5 has index
// 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which will
// satisfy out conditions and for reverse sorted array we will get maximum inversions
// and that is (n)*(n-1) / 2.For above given array there is 4 + 3 + 2 + 1 = 10 inversions.

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// BRUTE FORCE
int inversionCountBruteForce(vector<int> &arr)
{
    int count = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int merge(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            count += (mid - left + 1); // if (a[left]>a[right]) we add no. of element to it's right to answer
            temp.push_back(arr[right]);
            right++;
        };
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return count;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
    {
        return count;
    }
    int n = arr.size();

    int mid = low + (high - low) / 2;
    count += mergeSort(arr, low, mid);      // count all count from left
    count += mergeSort(arr, mid + 1, high); // count all count from right
    count += merge(arr, low, mid, high);    // count all count from final merge
    return count;
}

int inversionCountOptimal(vector<int> &arr)
{

    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{

    vector<int> arr = {5, 3, 2, 4, 1};
    cout << "The number of inversion of the array is : "
         << inversionCountBruteForce(arr)
         << endl;

    return 0;
}

// BRUTE FORCE
//
// Time Complexity :
// TC is O(n^2), as we use nested loops to compare each element with every other.
//
// Space Complexity :
// SC is O(1), no extra space is used.


// OPTIMAL APPROACH (Using Merge Sort)
//
// Time Complexity :
// TC is O(n*logn), as it's based on merge sort and we only added a counter for inversions.
//
// Space Complexity :
// SC is O(n), due to the temporary array used during merge operation and recursion stack.
