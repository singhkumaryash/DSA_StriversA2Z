// Problem statement : Selection sort is one of the sorting algorithms that works
// by repeatedly finding the minimum element from the unsorted part of the array
// and putting it at the beginning of the unsorted region of the array.

// You are given an unsorted array consisting of N non-negative integers.
// Your task is to sort the array in non-decreasing order using the Selection Sort algorithm.

// Input: nums = [7, 4, 1, 5, 3]
// Output: [1, 3, 4, 5, 7]
// Explanation: 1 <= 3 <= 4 <= 5 <= 7.
// Thus the array is sorted in non-decreasing order

// Solution :

#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return arr;
}

int main()
{

    vector<int> arr = {7, 1, 6, 4, 3};
    cout << "Array befor sorting : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    selectionSort(arr);
    cout << "Array after sorting : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    return 0;
}

// Total Iterations : n-1 ; where n is size of array.
// Total Comparisons : n(n-1)/2 ; where n is size of array.

// Time Complexity :
// TC is O(n^2) in worst, average and best case, where n is the number of elements in the array.

// Space Compexity :
// SC is O(1) ; constant space complexity.