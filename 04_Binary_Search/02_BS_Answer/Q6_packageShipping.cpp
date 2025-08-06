// Capacity to Ship Packages within D Days

// Problem Statement : You are the owner of a Shipment company. You use conveyor belts to ship
// packages from one port to another. The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'of weights'. The packages are loaded on
// the conveyor belts every day in the same order as they appear in the array. The loaded weights
// must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.

// Input Format: N = 5, weights[] = {5,4,5,2,3,4,5,6}, d = 5
// Result: 9
// Explanation: If the ship capacity is 9, the shipment will be done in the following manner:
// Day         Weights            Total
// 1        -       5, 4          -        9
// 2        -       5, 2          -        7
// 3        -       3, 4          -        7
// 4        -       5             -        5
// 5        -       6             -        6
// So, the least capacity should be 9.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm> // for *max_element
#include <numeric>   // for accumulate
using namespace std;

// number of days required to ship all packages with a given capacity
int daysTaken(vector<int> &weights, int capacity)
{
    int days = 1; // day 1
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        // If current weight exceeds capacity, move to next day
        if (load + weights[i] > capacity)
        {
            days++;            // add new day
            load = weights[i]; // restart load from new weight
        }
        else
        {
            load += weights[i]; // add weight to load
        }
    }
    return days;
}

// minimum capacity to ship all packages within 'days' days
int shipWithinDays(vector<int> &weights, int days)
{
    // low is max weight cause we need to ship all packages
    // (Reason : if taken smaller weight the maximum weight will never be shipped)
    int low = *max_element(weights.begin(), weights.end()); // to find max of weight

    // high is the total weights
    // (Reason : ship all weights in one day)
    int high = accumulate(weights.begin(), weights.end(), 0); // to find sum of weights

    int ans = -1;
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (daysTaken(weights, mid) <= days)
        {
            ans = mid;      // stores possible answer
            high = mid - 1; // move left to find minimum
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
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int days = 5;
    cout << "The minimum capacity should be: " << shipWithinDays(weights, days) << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N * log(sum(weights) - max(weights)))
//        Everytime we check days taken for a specific capacity it takes O(N).
//        Rest to calculate minimum capacity we use binary search from max(weights) to
//        sum of weights taking O(log(sum(weights) - max(weights))).

//    - Space Complexity : O(1)
//        No extra space is used.

// NOTE : Brute force would be to use linear search instead of binary search in
//        minimum capacity function, rest same.
