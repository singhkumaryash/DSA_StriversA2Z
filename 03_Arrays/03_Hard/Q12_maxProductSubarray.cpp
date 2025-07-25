// Maximum Product Subarray in an Array

// Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

// Input : Nums = [1,2,3,4,5,0]
// Output: 120
// Explanation : In the given array, we can see 1×2×3×4×5 gives maximum product value.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

// BRUTE FORCE
int maxProductBruteForce(vector<int> &nums)
{
    int n = nums.size();
    int maxProduct = 0;
    if (n < 2)
    {
        return nums[0];
    }
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= nums[j];

            maxProduct = max(maxProduct, product);
        }
    }
    return maxProduct;
}

// BETTER APPROACH (Hashing)
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxProduct = INT_MIN;
    if (n < 2)
    {
        return nums[0];
    }
    int suffixProduct = 1;
    int prefixProduct = 1;
    for (int i = 0; i < n; i++)
    {
        prefixProduct *= nums[i];         // start -> end
        suffixProduct *= nums[n - i - 1]; // end -> start
        maxProduct = max(maxProduct, max(prefixProduct, suffixProduct));
        if (prefixProduct == 0)
        {
            prefixProduct = 1;
        }
        if (suffixProduct == 0)
        {
            suffixProduct = 1;
        }
    }

    return maxProduct;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProduct(arr) << endl;
    return 0;
}

//  Brute Force :
//   - Time Complexity: O(n^2)
//      Two nested loops traverse all subarrays.
//   - Space Complexity: O(1)
//      No extra data structures used.

//  Optimal Approach (Observation) :
//   - Time Complexity: O(n)
//      Single traversal throughout the array and keeping a maxProduct.
//   - Space Complexity: O(1)
//      No extra data structures used.
