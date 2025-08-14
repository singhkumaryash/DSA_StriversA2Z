// Find the repeating and missing numbers

// Problem Statement : You are given a read-only array of N integers with values also
// in the range [1, N] both inclusive. Each integer appears exactly once except A which
// appears twice and B which is missing. The task is to find the repeating and missing
// numbers A and B where A repeats twice and B is missing.

// Input Format:  array[] = {3,1,2,5,3}
// Result: {3,4)
// Explanation: A = 3 , B = 4
// Since 3 is appearing twice and 4 is missing

// Solution :

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// EXTREME BRUTE FORCE
// TC = O(n^2) | SC = O(1); vector space is used to return anser
vector<int> findMissingRepeatingNumbersBruteForce(vector<int> nums)
{
    vector<int> ans(2, 0);
    for (int i = 1; i <= nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == i)
            {
                count++;
            }
        }
        if (count == 2)
        {
            ans[0] = i;
        }
        if (count == 0)
        {
            ans[1] = i;
        }
    }
    return ans;
}

// Self Derived Using Sorting
// TC = O(n*logn) + O(n) | SC = O(1);  vector space is used to return anser
vector<int> findMissingRepeatingNumbersSort(vector<int> nums)
{

    sort(nums.begin(), nums.end());
    vector<int> ans(2, 0);
    if (nums[0] != 1)
    {
        ans[1] = 1;
    }
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            ans[0] = (nums[i]);
        }
        if (nums[i + 1] > nums[i] + 1)
        {
            ans[1] = (nums[i] + 1);
        }
    }
    if (ans[1] == 0 && nums[nums.size() - 1] != nums.size())
    {
        ans[1] = nums.size();
    }
    return ans;
}

// BETTER APPROACH (Hashing)
vector<int> findMissingRepeatingNumbersHashing(vector<int> nums)
{
    vector<int> hashArray(nums.size() + 1, 0);
    vector<int> ans(2, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        hashArray[nums[i]]++;
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if (hashArray[i] == 2)
        {
            ans[0] = i;
        }
        else if (hashArray[i] == 0)
        {
            ans[1] = i;
        }
    }
    return ans;
}

// OPTIMAL (Using Mathematics)
vector<int> findMissingRepeatingNumbersMath(vector<int> nums)
{
    long long n = nums.size();
    long long Sn = (n * (n + 1)) / 2;
    long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0;
    long long S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += (long long)nums[i];
        S2 += ((long long)nums[i] * (long long)nums[i]);
    }
    long long val1 = S - Sn;
    long long val2 = S2 - S2n;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

// OPTIMAL (Using Bit Manipulation XOR)
vector<int> findMissingRepeatingNumbersBit(vector<int> a)
{
    int n = a.size(); // size of the array

    int xr = 0;

    // Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    // Step 2: Find the differentiating bit number:
    int bitNo = 0;
    while (1)
    {
        if ((xr && (1 << bitNo)) != 0)
        {
            break;
        }
        bitNo++;
    }

    // Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        // part of 1 group:
        if ((a[i] & (1 << bitNo)) != 0)
        {
            one = one ^ a[i];
        }
        // part of 0 group:
        else
        {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // part of 1 group:
        if ((i & (1 << bitNo)) != 0)
        {
            one = one ^ i;
        }
        // part of 0 group:
        else
        {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
            cnt++;
    }

    if (cnt == 2)
        return {zero, one};
    return {one, zero};
}

int main()
{
    vector<int> nums = {1, 2, 3, 6, 7, 5, 7};
    vector<int> result = findMissingRepeatingNumbersHashing(nums);
    cout << "Missing and Repeating Numbers: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

// BETTER APPROACH (Hashing)
//
// Time Complexity :
// TC is O(n), as we make two linear passes over the array and the hashArray.
//
// Space Complexity :
// SC is O(n), due to extra space used by the hashArray.

// OPTIMAL APPROACH (Mathematics)
//
// Time Complexity :
// TC is O(n), single pass through the array for computing sum and square sum.
//
// Space Complexity :
// SC is O(1), only constant space is used for variables.

// OPTIMAL APPROACH (Bit Manipulation XOR)
//
// Time Complexity :
// TC is O(n), as we iterate over the array and from 1 to n separately.
//
// Space Complexity :
// SC is O(1), no extra space is used except a few variables.
