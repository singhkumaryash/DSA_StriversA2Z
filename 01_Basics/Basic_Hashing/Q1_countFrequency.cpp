// Problem Statement : Given an array nums of size n which may contain
// duplicate elements, return a list of pairs where each pair contains
// a unique element from the array and its frequency in the array.

// You may return the result in any order, but each element must appear
// exactly once in the output.

// Input: nums = [1, 2, 2, 1, 3]
// Output: [[1, 2], [2, 2], [3, 1]]

// Explanation:
// 1 appears 2 times
// 2 appears 2 times
// 3 appears 1 time
// Order of output can vary.

// Solution :

#include <bits/stdc++.h>
using namespace std;

// Using an Hash Array to count frequency
void frequencyCountArray(int arr[], int size)
{

    int hash[13] = {0}; // the number in arr are in range 0-12.
    for (int i = 0; i < size; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < 13; i++)
    {
        if (hash[i] > 0)
        {

            cout << i << "->" << hash[i] << endl;
        }
    }
}

// Using a Map to count frequency

void frequencyCount(int arr[], int size)
{
    unordered_map<int, int> freqMap;
    for (int i = 0; i < size; i++)
    {
        freqMap[arr[i]]++;
    }
    for (auto it : freqMap)
    {
        cout << it.first << "->" << it.second << endl;
    }
}

int main()
{
    int arr[] = {1, 7, 8, 9, 1, 2, 8, 4, 5, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Frequency Count Using Map : " << endl;
    frequencyCount(arr, size);

    cout << "Frequency Count Using Hash Array : " << endl;
    frequencyCountArray(arr, size);

    return 0;
}

// Time Complexity :

// Hash Array :
// TC = O(n) + O(k) ; where n = Array Size & k = Hash Array Size

// Map :
// TC = O(n) + O(u) ; where n = Array Size & u = Unique Numbers in Array

// Space Complexity :

// Hash Array :
// SC = O(1) because in hash array the range of number decides hash size
// which is constant.

// Map :
// SC = 0(u) where u = Unique Numbers in Array.Because the map stores each
// unique number and its frequency