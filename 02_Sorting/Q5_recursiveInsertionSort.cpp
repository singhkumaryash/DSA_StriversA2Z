// Problem Statement : Given an array of integers nums, sort the array in non-decreasing
// order using the recursive Insertion Sort algorithm, and return the sorted array.

// You must implement Insertion Sort using recursion only.
// Do not use loops (like for or while) or built-in sorting functions (sort, Arrays.sort, etc.).
// A sorted array in non-decreasing order is an array where each element is greater than or
// equal to all elements that come before it

#include <bits/stdc++.h>
using namespace std;

void recursiveInsertionSort(vector<int> &arr, int n)
{
    if (n == arr.size())
    {
        return;
    }
    int i = n - 1;
    int key = arr[n];
    while (i >= 0 && key < arr[i])
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = key;
    recursiveInsertionSort(arr, n + 1);
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
    recursiveInsertionSort(arr, 1);
    cout << "Array after sorting : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    return 0;
}

// Total Iterations : n-1 ; where n is size of array.
// Total Comparisons : n(n-1)/2 in worst case ; where n is size of array.

// Time Complexity :
// TC is O(n^2) in worst, average and O(n) in best case, where
// n is the number of elements in the array.

// Space Compexity :
// Auxiliary Stack Space : O(n) -> SC is O(n)
// (because each recursive call adds one frame to the call stack)