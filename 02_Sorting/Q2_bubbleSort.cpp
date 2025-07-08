// Problem statement : Bubble Sort is one of the sorting algorithms that works
// by repeatedly swapping the adjacent elements of the array if they are not
// in sorted order.
// You are given an unsorted array consisting of N non-negative integers. Your
// task is to sort the array in non-decreasing order using the Bubble Sort algorithm

// Input: N = 6, array[] = {13,46,24,52,20,9}
// Output: 9,13,20,24,46,52
// Explanation: After sorting we get 9,13,20,24,46,52

#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    {
        bool swapped = false;
        for (int i = 0; i < n - 1; i++)  
            for (int j = 0; j < n - i - 1; j++)  // runs from i to n-1-i; where i is to ignore sorted part
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]); // check for element
                    swapped = true;
                }
                if (swapped == false) // early exit
                {
                    return arr;
                }
            }
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
    bubbleSort(arr);
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
// SC is O(1) ; constant space complexity.