// Problem Statement : Given an array of integers arr, sort the array in non-decreasing
// order using the recursive Bubble Sort algorithm, and return the sorted array.

// You must implement Bubble Sort using recursion only.
// Do not use built-in sorting functions (sort, sorted, Arrays.sort, etc.).
// A sorted array in non-decreasing order is an array where each element is greater than
// or equal to the previous one.

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    if (n == 1)
    {
        return;
    };
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }
    if (swapped == false)
    {
        cout << "return" << endl;
        return;
    }
    bubbleSort(arr, n - 1);
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
    bubbleSort(arr, arr.size());
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