// Leaders in an Array

// Problem Statement : Given an array, print all the elements which are leaders.
// A Leader is an element that is greater than all of the elements on its right
// side in the array.

// Input: nums = [-3, 4, 5, 1, -4, -5]

// Output: [5, 1, -4, -5]

// Explanation : -5 is the rightmost element, -4 is the largest element in the index
// range [4, 5], 1 is the largest element in the index range [3, 5] and 5 is the largest
// element in the range [2, 5].

// Solution :

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
vector<int> findLeadersBruteForce(vector<int> &a)
{
    int n = a.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] >= a[i])
            {
                isLeader = false;
                break;
            }
        }
        if (isLeader)
        {
            ans.push_back(a[i]);
        }
    }
    return ans;
}

// Optimal Approach
vector<int> findLeaders(vector<int> &a)
{
    int n = a.size();
    vector<int> ans;
    int max = a[n - 1];
    ans.push_back(max);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > max)
        {
            ans.push_back(a[i]);
            max = a[i];
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    vector<int> arr1 = {-3, 4, 5, 1, -4, -5};
    vector<int> leaders1 = findLeadersBruteForce(arr1);
    cout << "The leaders in the array 1 are : { ";
    for (int i = 0; i < leaders1.size(); i++)
    {
        cout << leaders1[i] << " ";
    }
    cout << "}" << endl;
    vector<int> arr2 = {4, 2, 1, 3, 0};
    vector<int> leaders2 = findLeaders(arr2);
    cout << "The leaders in the array 2 are : { ";
    for (int i = 0; i < leaders2.size(); i++)
    {
        cout << leaders2[i] << " ";
    }
    cout << "}" << endl;
    return 0;
}

// BRUTE FORCE :
// Time Complexity :
// TC is O(n^2), as we iterate array using nested loops.

// Space Complexity :
// SC is O(n), as in worst there will be n leaders(reverse sorted array).

// OPTIMAL APPROACH :
// Time Complexity :
// TC is O(n), as we iterate array once.

// Space Complexity :
// SC is O(n), as in worst there will be n leaders(reverse sorted array).