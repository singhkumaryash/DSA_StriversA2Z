#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// BRUTE FORCE
vector<int> majorityElementBrute(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ans.size() == 2) // if 2 elements are found we return as maximum 2 majority element can only be there
        {
            return ans;
        }

        if (find(ans.begin(), ans.end(), nums[i]) != ans.end()) // if element already exists then we continue to next
        {
            continue;
        }

        int count = 0;
        // Iterate through each element to test it as a potential majority candidate.
        for (int j = i; j < nums.size(); j++)
        // NOTE: The inner loop (j) starts from the current index 'i'. This logic works because
        // when the outer loop 'i' encounters the *first* occurence of a majority element,
        // the forward scan from that point is guaranteed to find all of its occurrences,
        // thus correctly exceeding the n/3 threshold. The check at the top prevents
        // re-processing elements that have already been added to the answer.

        // The more generalised way is to start j with 0;
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
            if (count > nums.size() / 3) // if element count becomes more than n/3 we add and break to next
            {
                ans.push_back(nums[i]);
                break;
            }
        }
    }
    return ans;
}

// BETTER APPROACH
vector<int> majorityElementBetter(vector<int> &nums)
{
    vector<int> ans;
    unordered_map<int, int> countMap;
    int minOcuurence = nums.size() / 3 + 1;
    for (int i = 0; i < nums.size(); i++)
    {
        countMap[nums[i]]++;
        if (countMap[nums[i]] == minOcuurence)
        {
            ans.push_back(nums[i]);
        }

        if (ans.size() == 2)
        {
            break;
        }
    }

    // for (auto it : countMap) // this can also be used to iterate map separately
    // {
    //     if (it.second > nums.size() / 3 && ans.size() <= 2)
    //     {
    //         ans.push_back(it.first);
    //     }
    // }

    return ans;
}

// OPTIMAL APPROACH
vector<int> majorityElementOptimal(vector<int> &nums)
{
    int count1 = 0;
    int count2 = 0;
    int el1;
    int el2;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count1 == 0 && nums[i] != el2)
        {
            count1 = 1;
            el1 = nums[i];
        }
        else if (count2 == 0 && nums[i] != el1)
        {
            count2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1)
        {
            count1++;
        }
        else if (nums[i] == el2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    int c1 = 0;
    int c2 = 0;
    int minOccurence = nums.size() / 3 + 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
        {
            c1++;
        }
        else if (nums[i] == el2)
        {
            c2++;
        }
    }
    if (c1 >= minOccurence)
    {
        ans.push_back(el1);
    }
    if (c2 >= minOccurence)
    {
        ans.push_back(el2);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 2, 3, 3, 2, 1, 1, 1};
    vector<int> result = majorityElementBetter(arr);

    cout << "The majority elements with more than n/3 occurrences in the array are: { ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << "}" << endl;

    return 0;
}

// 1. Brute Force :
//    - Time Complexity: O(n^2)
//       Nested loop for iterating every elment and counter.
//
//    - Space Complexity: O(1)
//       No extra data structures used

// 2. Better Approach (Hashing) :
//    - Time Complexity: O(n) in best and average case and O(n^2) in worst case.
//       Single pass through array
//       Each unordered_map operation is O(1) in best and average case and O(n)
//       in worst case due to collisions.
//       *If we use map instead of unordered_map, the time complexity will be O(N*logN)
//        as the map data structure takes O(logn) time to find an element.
//
//    - Space Complexity: O(n)
//       map stores the element and their counter.

// 3. Optimal (Modified Moore's Voting Algorithm) :
//    - Time Complexity: O(n) + O(n) = O(2n)
//       One pass to find majority element and another to validate.
//
//    - Space Complexity: O(1)
//       No extra data structures used

// NOTE :
// - Moore's Voting Algorithm only works when the majority element is guaranteed to
//   exist (i.e., appears > n/2 times). Otherwise, for validation when the majority
//   element may or may not exist, a second pass is needed to confirm.
