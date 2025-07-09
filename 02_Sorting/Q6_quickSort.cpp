// Problem Statement : Given an array of integers called arr, sort the array 
// in non-decreasing order using the quick sort algorithm .

// A sorted array in non-decreasing order is an array where each element is 
// greater than or equal to all preceding elements in the array

#include <bits/stdc++.h>
using namespace std;
int quickSortHelper(vector<int> &arr, int low, int high)
{

    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
};
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = quickSortHelper(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
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
    quickSort(arr, 0, arr.size() - 1);
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
// Auxiliary Stack Space : O(n) -> SC is O(n)
// (because each recursive call adds one frame to the call stack)