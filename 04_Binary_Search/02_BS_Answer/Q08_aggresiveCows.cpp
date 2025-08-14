// Aggressive Cows : Detailed Solution

// Problem Statement : You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any
// two of them is the maximum possible.
// Find the maximum possible minimum distance.

// Input Format: N = 6, k = 4, arr[] = {0,3,4,7,10,9}
// Result: 3
// Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed
// at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make
// the minimum distance greater than 3 in any ways.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];
    for (int i = 1; i <= stalls.size() - 1; i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[stalls.size() - 1] - stalls[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossibleSolution(stalls, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    cout << "The maximum possible minimum distance is : " << aggressiveCows(stalls, k) << endl;
}

// Time and Space Complexity:

//    - Time Complexity : O(N*log(N) + (N * log(max-min))
//        To sort the array is is O(N*log(N)).
//        Everytime we check if a distance is a possible solution taking O(N).
//        Rest to calculate the maximum possible minimum distance we use binary search from 1 to
//        (maximum - minimum) of the array taking O(log(max-min)).

//    - Space Complexity : O(1)
//        No extra space is used.

// NOTE : Brute force would be to use linear search instead of binary search in
//        the function, rest same.
