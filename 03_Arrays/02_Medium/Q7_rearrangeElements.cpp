// Rearrange Array Elements by Sign

// Problem Statement : There’s an array ‘A’ of size ‘N’ with an equal number of positive
// and negative elements. Without altering the relative order of positive and negative
// elements, you must return an array of alternately positive and negative values.

// Note: Start the array with positive elements

// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]

// Solution :

#include <iostream>
#include <vector>
using namespace std;

// Brute Force
vector<int> rearrangeArrayBruteForce(vector<int> &nums)
{
    vector<int> ans;
    vector<int> positive;
    vector<int> negative;

    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] > 0)
        {
            positive.push_back(nums[i]);
        }
        else
        {
            negative.push_back(nums[i]);
        }
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < nums.size())
    {
        if (i % 2 == 0)
        {
            ans.push_back(positive[j]);
            i++;
            j++;
        }
        else
        {
            ans.push_back(negative[k]);
            i++;
            k++;
        }
    }
    return ans;
}

// Optimal
vector<int> rearrangeArrayOptimal(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    int positive = 0;
    int negative = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans[positive] = nums[i];
            positive += 2;
        }
        else
        {
            ans[negative] = nums[i];
            negative += 2;
        }
    }
    return ans;
}

// Variety-2
// Not neccessarily Equal positives and negatives
// Note: Start the array with positive elements.

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans;
    vector<int> positive;
    vector<int> negative;

    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] > 0)
        {
            positive.push_back(nums[i]);
        }
        else
        {
            negative.push_back(nums[i]);
        }
    }

    int i = 0;
    int j = 0;
    int index = 0;
    while (index < nums.size() && i < positive.size() && j < negative.size())
    {
        if (index % 2 == 0)
        {
            ans.push_back(positive[i]);
            i++;
            index++;
        }
        else
        {
            ans.push_back(negative[j]);
            j++;
            index++;
        }
    }
    while (i < positive.size())
    {
        ans.push_back(positive[i++]);
    }
    while (j < negative.size())
    {
        ans.push_back(negative[j++]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> result1 = rearrangeArrayBruteForce(arr);
    vector<int> result2 = rearrangeArrayOptimal(arr);
    for (auto it : result1)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : result2)
    {
        cout << it << " ";
    }
    cout << endl;
    vector<int> arr2 = {3, 1, -2, -5, 2, -4, 4, 7};
    vector<int> result3 = rearrangeArray(arr2);
    for (auto it : result3)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

// 1. Brute Force :
//    - Time Complexity: O(2n)
//       as we iterate twice through the loop till n.
//
//    - Space Complexity: O(2n)
//       as we store positive(n/2), negatives(n/2) and ans(n).
//

// 2. Optimal  :
//    - Time Complexity: O(n)
//       Single pass through array
//
//    - Space Complexity: O(n)
//       as we store positive(n/2), negatives(n/2) and ans(n).

// 2nd Variety : 
//    - Time Complexity: O(2n)
//       as we iterate through array once ans store. Then we iterate till minimum of negative
//       or positive elements. Then we iterate to the remaining.   
//
//    - Space Complexity: O(2n)
//       as we store positive(n/2), negatives(n/2) and ans(n).
