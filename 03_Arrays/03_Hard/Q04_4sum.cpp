// 4 Sum | Find Quads that add up to a target value

// Problem Statement : Given an array of N integers, your task is to find unique quads that
// add up to give a target value. In short, you need to return an array of all the unique
// quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

// Note:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// arr[a] + arr[b] + arr[c] + arr[d] == target

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Solution :

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> fourSumBruteForce(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    for (int a = 0; a < n - 3; a++)
    {
        for (int b = a + 1; b < n - 2; b++)
        {
            for (int c = b + 1; c < n - 1; c++)
            {
                for (int d = c + 1; d < n; d++)
                {
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[a], nums[b], nums[c], nums[d]};
                        sort(temp.begin(), temp.end());
                        if (find(ans.begin(), ans.end(), temp) == ans.end())
                        {
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
    }
    return ans;
}

// BETTER APPROACH
vector<vector<int>> fourSumBetter(vector<int> &nums, int target)
{
    int n = nums.size();

    set<vector<int>> ansSet;
    for (int a = 0; a < n - 2; a++)
    {
        for (int b = a + 1; b < n - 1; b++)
        {
            set<int> hashSet;
            for (int c = b + 1; c < n; c++)
            {
                int d = target - (nums[a] + nums[b] + nums[c]);
                if (hashSet.find(d) != hashSet.end())
                {
                    vector<int> temp = {nums[a], nums[b], nums[c], d};
                    sort(temp.begin(), temp.end());
                    ansSet.insert(temp);
                }
                hashSet.insert(nums[c]);
            }
        }
    }
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

// OPTIMAL
vector<vector<int>> fourSumOptimal(vector<int> &nums, int target)
{
    if (nums.size() < 4)
    {
        return {};
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();

    for (int a = 0; a < n - 1; a++)
    {
        if (a > 0 && nums[a] == nums[a - 1])
        {
            continue;
        }
        for (int b = a + 1; b < n; b++)
        {
            if (b > a + 1 && nums[b] == nums[b - 1])
            {
                continue;
            }

            int c = b + 1;
            int d = n - 1;
            while (c < d)
            {
                long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                if (sum == target)
                {
                    vector<int> temp = {nums[a], nums[b], nums[c], nums[d]};
                    ans.push_back(temp);

                    c++;
                    d--;
                    while (c < d && nums[c] == nums[c - 1])
                    {
                        c++;
                    }
                    while (c < d && nums[d] == nums[d + 1])
                    {
                        d--;
                    }
                }
                else if (sum < target)
                {
                    c++;
                }
                else if (sum > target)
                {
                    d--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = fourSumBetter(nums, target);
    cout << "The quadruplets are: {";
    for (auto it : ans)
    {
        cout << " { ";
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << "}";
    }
    cout << " }" << endl;

    // Overflow Testcase
    vector<int> nums2 = {1000000000, 1000000000, 1000000000, 1000000000};
    int target2 = 4000000000;
    vector<vector<int>> ans2 = fourSumOptimal(nums2, target);
    cout << "The quadruplets are: {";
    for (auto it : ans2)
    {
        cout << " { ";
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << "}";
    }
    cout << " }" << endl;

    return 0;
}

// 1. Brute Force:
//    - Time Complexity: O(N^4)
//        Four nested loops to check every possible quadruplet.
//        Additional O(4*log4) for sorting each quadruplet before insertion (negligible).
//        Also includes O(K) time for checking duplicates using set or vector.
//    - Space Complexity (excluding output): O(1)
//        No extra data structures used during computation.
//    - Space Complexity (including output): O(K)
//        Where K is the number of unique quadruplets.
//    - Note: Highly inefficient for large N. Avoid in real scenarios.

// 2. Better Approach (3 Loops + Hash Set):
//    - Time Complexity: O(N^3)
//        Three loops to fix a, b, and check c + d using a hash set → O(N^3).
//        Hash set operations are average O(1).
//    - Space Complexity (excluding output): O(N)
//        Hash set for checking complements.
//    - Space Complexity (including output): O(N + K)
//        K = number of unique quadruplets.
//    - Note: Improves over brute-force by avoiding 4th loop using hashing.

// 3. Optimal Approach (Sorting + Two Pointers):
//    - Time Complexity: O((N^2*N) + NlogN) = O(N^3)
//        - Sorting: O(N log N)
//        - Outer 2 loops: O(N^2)
//        - Inner two pointers: O(N)
//        → Total: O(N^3)
//    - Space Complexity (excluding output): O(1)
//        Only uses pointers and variables.
//    - Space Complexity (including output): O(K)
//        K = number of unique quadruplets.
//    - Note: Best approach. Sorting + two pointers + skipping duplicates ensures optimal performance.
