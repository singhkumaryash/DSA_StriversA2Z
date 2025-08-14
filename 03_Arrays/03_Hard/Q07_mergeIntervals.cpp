// Merge Overlapping Sub-intervals

// Problem Statement : Given an array of intervals, merge all the overlapping intervals and
// return an array of non-overlapping intervals.

// Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
// intervals.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BRUTE FORCE
vector<vector<int>> mergeBruteForce(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < intervals.size(); j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// OPTIMAL APPROACH
vector<vector<int>> mergeOptimal(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (auto it : intervals)
    {
        if (ans.empty() || ans.back()[1] < it[0])
        {
            ans.push_back(it);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], it[1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 18}};
    vector<vector<int>> ans = mergeOptimal(arr);
    cout << "The merged intervals are: { ";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << "}" << endl;
    return 0;
}

// BRUTE FORCE

// Time Complexity :
// TC is O(n^2 + n*logn) = O(n^2), as we sort the intervals (O(n*logn))
// and for each interval we iterate through the rest to merge (O(n)).

// Space Complexity :
// SC is O(n), as we store the merged intervals in the answer vector.
// Auxiliary space is O(1) as we do not use any extra data structures apart from the answer vector.

// OPTIMAL APPROACH

// Time Complexity :
// TC is O(n + n*logn) = O(n*logn), as we sort the intervals (O(n*logn))
// and then iterate through them once (O(n)) to merge.

// Space Complexity :
// SC is O(n), as we store the merged intervals in the answer vector.
// Auxiliary space is O(1) as we do not use any extra data structures apart from the answer vector.

