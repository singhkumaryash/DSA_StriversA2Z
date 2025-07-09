// Problem Statement : Given a sequence of numbers ‘ARR’. Your task is to return a
// sequence of ‘ARR’ in non-descending order with help of the merge sort algorithm.

// Merge Sort Algorithm -

// Merge sort is a Divide and Conquer based Algorithm. It divides the input array
// into two-parts, until the size of the input array is not ‘1’. In the return
// part, it will merge two sorted arrays a return a whole merged sorted array.

#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high)
{

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
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int n = arr.size();

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{

    vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    cout << "Array befor sorting : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Array after sorting : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    return 0;
}

// Time Complexity :
// TC is O(nlog2(n)) in worst, average and best case, where
// n is the number of elements in the array.

// Space Compexity :
// SC is O(n) ; where n is size of array.