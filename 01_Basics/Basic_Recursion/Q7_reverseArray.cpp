// oblem Statement : You are given an array. The task is to reverse the
// array and print it.

// Input: N = 5, arr[] = {5,4,3,2,1}
// Output: {1,2,3,4,5}

// Explanation: Since the order of elements gets reversed the first
// element will occupy the fifth position, the second element occupies
// the fourth position and so on.

// Solution :

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void reverseArray(int i, int arr[], int n)
{
    if (i >= n / 2)
    {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    reverseArray(i + 1, arr, n);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array : ";
    printArray(arr, n);

    reverseArray(0, arr, n);
    cout << "Reversed Array : ";
    printArray(arr, n);
    return 0;
}

// Time Complexity :

// TC is O(n/2) = O(n) as the function is called n/2 times.

// Space Complexity :

// SC is O(n/2) = O(n) because the recursion stack space would be full with
// all the function calls waiting to get completed and that would
// make it an O(n) recursion stack space
