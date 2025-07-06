// Problem Statement : Given an array of n integers, find the most frequent
// and least frequent element in it.
// If there are multiple elements that appear a maximum number of times,
// find the largest of them.
// If there are multiple elements that appear a minimum number of times,
// find the smallest of them.
// Input: arr = [1, 2, 2, 3, 3, 3]
// Output: 3 1
// Explanation : The number 3 appears the 3 times. It is the most frequent element.
//               The number 1 appears the 1 times. It is the least frequent element.
//

// Solution :

#include <bits/stdc++.h>
using namespace std;

pair<int, int> frequentElements(vector<int> &arr)
{
    pair<int, int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        map[arr[i]]++;
    }

    int maxElement = 0;
    int maxFrequency = 0;

    int minFrequency = INT_MAX;
    int minElement = 0;
    for (auto it : map)
    {
        int count = it.second;
        int element = it.first;
        if (count > maxFrequency)
        {
            maxFrequency = count;
            maxElement = element;
        }
        if (count < minFrequency)
        {
            minFrequency = count;
            minElement = element;
        }
        if (count == maxFrequency && maxElement < element)
        {
            maxElement = element;
        }
        if (count == minFrequency && minElement > element)
        {
            minElement = element;
        }
    }
    ans.first = minElement;
    ans.second = maxElement;
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4};

    cout << "The most frequent element is " << frequentElements(arr).second << endl;
    cout << "The least frequent element is " << frequentElements(arr).first << endl;
    return 0;
}

// Time Complexity : 

// TC = O(n) + O(u) ; where n = Array Size & u = Unique Numbers in Array or Size of map

// Space Complexity : 

// SC = O(u) ; where u = Unique Numbers in Array, because the map stores each
// unique number and its frequency