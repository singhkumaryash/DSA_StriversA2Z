// Union of Two Sorted Arrays

// Problem Statement : Given two sorted arrays, arr1, and arr2 of size n and m.
// Find the union of two sorted arrays.

// The union of two arrays can be defined as the common and distinct elements in
// the two arrays.
// NOTE: Elements in the union should be in ascending order.

// Input:
// n = 5, m = 5.
// arr1[] = {1,2,3,4,5}
// arr2[] = {2,3,4,4,5}
// Output : {1,2,3,4,5}

// Explanation:
// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1
// Distnict Elemennts in arr2 are : No distinct elements.
// Union of arr1 and arr2 is {1,2,3,4,5}

// Solution :

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// BRUTE FORCE
vector<int> unionArray(vector<int> &a, vector<int> &b)
{

    set<int> ans;
    int i = 0;
    int j = 0;
    while (i < a.size())
    {
        ans.insert(a[i++]);
    }
    while (j < b.size())
    {
        ans.insert(b[j++]);
    }

    vector<int> result;
    for (auto it : ans)
    {
        result.push_back(it);
    }
    return result;
}

// OPTIMAL
vector<int> arrayUnion(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }

            i++;
        }

        else
        {
            if (ans.size() == 0 || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < a.size())
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    while (j < b.size())
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {2, 3, 4, 4, 5, 7};
    vector<int> result = arrayUnion(a, b);
    cout << "Union of the two arrays is: ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

// Brute Force

// Time Complexity :
// TC is O((n + m) log(n + m)); where n and m are number of unique elements in a & b.

// Space Complexity
// SC is O(m+n); for storing the resultant array. Not for Computation.

// Optimal :

// Time Complexity :
// TC is O(n+m); where n and m are number of elements in a & b.

// Space Complexity
// SC is O(m+n); for storing the resultant array. Not for Computation.