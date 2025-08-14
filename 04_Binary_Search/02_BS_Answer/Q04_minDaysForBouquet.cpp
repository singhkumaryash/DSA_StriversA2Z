// Minimum days to make M bouquets

// Problem Statement : You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the
// garden. The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can
// be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the
// garden. If it is impossible to make m bouquets return -1.

// Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
// Result: 12
// Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed.
// So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

// Solution :

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Check if it's possible to make 'm' bouquets with each having 'k' adjacent bloomed flowers within 'days'
bool isPossible(vector<int> &bloomDay, int m, int k, int days)
{
    int counter = 0;
    int bouquetCount = 0;
    for (auto it : bloomDay)
    {
        if (it <= days)
        {
            counter++; // consecutive bloomed flower count
        }
        else
        {
            bouquetCount += (counter / k); // count for bouquet made using k consecutive bloomed flower
            counter = 0;                   // resassign count 0 for another iteration
        }
    }
    bouquetCount += (counter / k); // for the last count
    if (bouquetCount >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Find minimum and maximum bloom days
vector<int> findRange(vector<int> &bloomDay)
{
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    for (auto it : bloomDay)
    {
        minimum = min(minimum, it);
        maximum = max(maximum, it);
    }
    return {minimum, maximum};
}

// To find minimum days to make m flower
int minDays(vector<int> &bloomDay, int m, int k)
{

    // check if the total flower required to make bouquet is more than given flower
    if (1LL * m * k > bloomDay.size()) // convert to long long for large input
    {
        return -1;
    }
    vector<int> range = findRange(bloomDay);
    int low = range[0];
    int high = range[1];
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(bloomDay, m, k, mid) == true)
        {
            ans = mid; // if possible store answer and move to left to find minimum
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    int result = minDays(bloomDay, m, k);
    cout << "Minimum days to make " << m << " bouquets : " << result << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N + (N * log(max - min)))
//        To find maximum and minimum of the array is O(N).
//        Everytime we check if a day is possible solution taking O(N).
//        Rest to calculate minimum days we use binary search from minimum to
//        maximum of the array taking O(log(max(bloomDay) - min(bloomDay))).

//    - Space Complexity : O(1)
//        No extra space is used.

// NOTE : Brute force would be to use linear search instead of binary search in
//        minimum days function, rest same.
