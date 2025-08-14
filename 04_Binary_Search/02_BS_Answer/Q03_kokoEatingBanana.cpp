// Koko Eating Bananas

// Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile
// has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours)
// for all the bananas to be eaten.

// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the
// pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t
// eat any more bananas in that hour.

// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the
// bananas within ‘h’ hours.

// Input Format: N = 4, a[] = {7, 15, 6, 3}, h = 8
// Result: 5
// Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles
// accordingly. So, he will take 8 hours to complete all the piles.

// Solution :

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int maxOfPile(vector<int> &piles)
{
    int maxi = INT_MIN;
    for (auto it : piles)
    {
        maxi = max(maxi, it);
    }
    return maxi;
}

long long totalTime(vector<int> &piles, int mid)
{
    long long totalHours = 0;
    for (auto it : piles)
    {
        totalHours += ceil((double)it / (double)mid);
    }
    return totalHours;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = maxOfPile(piles);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long k = totalTime(piles, mid);
        if (k <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> piles = {7, 15, 6, 3};
    int h = 8;
    cout <<"Koko needs to eat minimum "<< minEatingSpeed(piles, h) <<" banana per hour."<< endl;
}


// Time and Space Complexity:

//    - Time Complexity : O(N + (N * log(max(piles)))) 
//        To find max out of pile is O(N).
//        Everytime to calculate total hour we iterate the piles taking O(N).
//        Rest to calculate minimum eating speed we use binary search from 1 to 
//        max of piles taking O(log(max(piles))).

//    - Space Complexity : O(1)
//        No extra space is used.


// NOTE : Brute force would be to use linear search instead of binary search in 
//        minimum eating banana function.
