// 3 Sum : Find triplets that add up to a zero

// Problem Statement : Given an array of N integers, your task is to find unique triplets
// that add up to give a sum of zero. In short, you need to return an array of all the unique
// triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy
// the condition of summing up to zero with i!=j!=k

// Solution :

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// BRUTE FORCE
vector<vector<int>> threeSumBruteForce(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(), temp.end());
                    if (find(ans.begin(), ans.end(), temp) == ans.end())
                    {
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    return ans;
}

// BETTER
vector<vector<int>> threeSumBetter(vector<int> &nums)
{
    set<vector<int>> ansSet;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < nums.size(); j++)
        {
            int k = -(nums[i] + nums[j]);
            if (hashSet.find(k) != hashSet.end())
            {
                vector<int> temp = {nums[i], nums[j], k};
                sort(temp.begin(), temp.end());

                ansSet.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

// OPTIMAL
vector<vector<int>> threeSumOptimal(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    vector<vector<int>> ans;
    while (i < nums.size() - 2)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            i++;
            continue;
        }

        int k = nums.size() - 1;
        int j = i + 1;
        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] > 0)
            {
                k--;
            }
            else if (nums[i] + nums[j] + nums[k] < 0)
            {
                j++;
            }
            else
            {
                ans.push_back({{nums[i], nums[j], nums[k]}});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }

        i++;
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = threeSumOptimal(arr1);
    cout << "The triplet with sum 0 : {";
    for (auto it : result1)
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
//    - Time Complexity: O(N^3)
//        Three nested loops to check every possible triplet.
//        Additional O(3*log3) for sorting each triplet before insertion (negligible).
//        Also includes O(K) time for checking duplicates using find().
//    - Space Complexity (excluding output): O(1)
//        No extra data structures used during computation.
//    - Space Complexity (including output): O(K)
//        Where K is the number of unique triplets.
//    - Note: Inefficient for large N. Duplicate check using find() increases time.

// 2. Better Approach (Hash Set):
//    - Time Complexity: O(N^2)
//        Outer loop runs N times, inner loop uses hash set operations (avg O(1)).
//        Sorting each triplet (O(3*log3)) before inserting into set is negligible.
//    - Space Complexity (excluding output): O(N)
//        Hash set used for lookup + set<vector<int>> to store unique triplets.
//    - Space Complexity (including output): O(N + K)
//        Where K is the number of unique triplets.
//    - Note: Ensures uniqueness using a set. Handles duplicates well.

// 3. Optimal Approach (Two Pointers after Sorting):
//    - Time Complexity: O(N^2)
//        Array is first sorted in O(N log N).
//        Then for each element, use two-pointer scan → O(N^2) total.
//        Overall: O(N log N + N^2) ≈ O(N^2)
//    - Space Complexity (excluding output): O(1)
//        No extra data structures used beyond variables and pointers.
//    - Space Complexity (including output): O(K)
//        Where K is the number of unique triplets.
//    - Note: Best approach. Sorting enables efficient skipping of duplicates.
