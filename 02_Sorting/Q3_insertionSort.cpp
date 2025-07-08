// Problem Statement: Given an array of N integers, write a program
// to implement the Insertion sorting algorithm.

// Input: N = 6, array[] = {13,46,24,52,20,9}
// Output: 9,13,20,24,46,52
// Explanation:
// After sorting the array is: 9,13,20,24,46,52

// Solution :

#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        int key = arr[i];

        while (j > 0 && key < arr[j - 1])
        {
            // swap(arr[j], arr[j - 1]); // swap takes more time
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
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
    insertionSort(arr);
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