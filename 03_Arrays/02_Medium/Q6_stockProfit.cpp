// Stock Buy And Sell

// Problem Statement : You are given an array of prices where prices[i] is the
// price of a given stock on an ith day.

// You want to maximize your profit by choosing a single day to buy one stock
// and choosing a different day in the future to sell that stock. Return the
// maximum profit you can achieve from this transaction. If you cannot achieve
// any profit, return 0.

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and
// sell on day 5 (price = 6), profit = 6-1 = 5

// Solution :

#include <iostream>
using namespace std;

int maxProfit(int prices[], int n)
{
    int low = prices[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - low;
        profit = max(profit, cost);
        low = min(low, prices[i]);
    }
    return profit;
}

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The maxixum profit that can be achieved is " << maxProfit(arr, n) << endl;
    return 0;
}

// Time Complexity :
// TC is O(n), as we iterate through the array once.

// Space Complexity : SC is O(1), as we use no extra space.