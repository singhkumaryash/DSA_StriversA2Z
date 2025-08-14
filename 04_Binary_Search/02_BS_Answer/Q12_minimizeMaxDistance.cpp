// Minimise Maximum Distance between Gas Stations

// Problem Statement : You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions
// of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. You have to place 'k' new gas stations on
// the X-axis. You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.
// Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
// Find the minimum value of ‘dist’.

// Note : Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer
// is 0.65421678124, it is okay to return 0.654216. Our answer will be accepted if that is the same as the actual
// answer up to the 6th decimal place.

// Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
// Result: 0.5
// Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum
// difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there
// is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm> // for max
#include <queue>     //for priority queue

using namespace std;

// BRUTE FORCE
double minimiseMaxDistanceBrute(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<double> placedStations(n - 1, 0); // initialise station in gap as 0

    // Place k new stations one by one, starting from 1
    for (int i = 1; i <= k; i++)
    {
        double maxValue = -1; // Largest gap length found so far
        int maxIndex = -1;    // Index of the gap with the largest length

        // Find the largest current gap
        for (int i = 0; i < n - 1; i++)
        {
            double difference = arr[i + 1] - arr[i];
            double sectionLength = difference / (placedStations[i] + 1);
            if (maxValue < sectionLength)
            {
                maxValue = sectionLength;
                maxIndex = i;
            }
        }

        // Place a station in the largest gap found
        placedStations[maxIndex]++;
    }

    // After placing all stations, compute the maximum gap length
    double maxDistance = -1;
    for (int i = 0; i < n - 1; i++)
    {
        double secLength = (arr[i + 1] - arr[i]) / (placedStations[i] + 1);
        maxDistance = max(maxDistance, secLength);
    }
    return maxDistance;
}

// BETTER APPROACH (Using Priority Queue)
double minimiseMaxDistanceBetter(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<double> placedStations(n - 1, 0); // initialise station in gap as 0
    priority_queue<pair<double, int>> pq;    // stores {current gap length, gap index}

    // Initialize the queue with the original gaps
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    // Place k new stations one by one, starting from 1
    for (int gasStation = 1; gasStation <= k; gasStation++)
    {
        // Get the largest current gap
        auto tp = pq.top();
        pq.pop();

        int secIndex = tp.second;   // Index of the gap to split
        placedStations[secIndex]++; // Place a station in this gap

        // Calculate new section length after adding this station

        double iniDiff = arr[secIndex + 1] - arr[secIndex];
        double newSecLength = iniDiff / (placedStations[secIndex] + 1);

        pq.push({newSecLength, secIndex}); // Push the updated gap back into the queue
    }

    // The top of the queue contains the minimized maximum gap
    return pq.top().first;
}

// OPTIMAL APPROACH (Using Binary Search)
bool isPossibleSolution(vector<int> &arr, int k, double mid)
{
    int n = arr.size();
    int stationCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // Calculate how many stations are needed to make the gap between arr[i] and arr[i+1] <= mid
        int stationInBetween = (arr[i + 1] - arr[i]) / mid;

        // If the gap is exactly divisible by mid, the last station would coincide with an existing station,
        // so we subtract one to avoid counting an extra station.
        if ((arr[i + 1] - arr[i]) == (mid * stationInBetween))
        {
            stationInBetween--;
        }
        stationCount += stationInBetween; // Add the stations needed for this gap

        if (stationCount > k)
            return false; // If we need more than 'k' stations, it's not possible
    }
    return true;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    double low = 0; // Minimum possible maximum gap
    double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (double)arr[i + 1] - arr[i]); // high is maximum gap in array
    }

    // Perform binary search until the precision is within limit (1e-6)
    while (high - low > 1e-6) // 10^-6 is because the states so
    {
        double mid = low + (high - low) / 2.0;
        if (isPossibleSolution(arr, k, mid))
        {
            high = mid; // decreases maximum distance
        }
        else
        {
            low = mid; // increases maximum distance
        }
    }
    // 'high' will be our minimized maximum distance between stations
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    cout << minimiseMaxDistance(arr, k) << endl;
}

// TIME AND SPACE COMPLEXITY :

// 1. Brute Force Approach
//    Time Complexity: O(k * (n-1)) + O(n)
//       O(k * (n-1)) → For each of the k gas stations, we scan all n-1 gaps to find the one with the maximum section length.
//       O(n) → Final pass to compute the maximum distance after placement.
//    Space Complexity: O(n-1)
//       Extra array placedStations of size n-1 to store the number of stations placed in each gap.

// 2. Better Approach (Priority Queue)
//    Time Complexity: O(n log n) + O(k log n)
//       O(n log n) → Initial insertion of all n-1 gaps into the priority queue.
//       O(k log n) → For each of the k placements, extract the largest gap and insert the updated gap back into
//       the queue (both operations take log n time).
//    Space Complexity: O(n-1) + O(n-1)
//       O(n-1) → Array placedStations to track placements.
//       O(n-1) → Priority queue storing gap lengths and their indices.

// 3. Optimal Approach (Binary Search)
//    Time Complexity: O(n * log(max gap)) + O(n)
//       O(log(max gap)) → Binary search iterations from 0 to the maximum gap in the array.
//       O(n) inside each iteration to check feasibility (isPossibleSolution).
//       O(n) one-time pass to find the initial maximum gap.
//    Space Complexity: O(1)
//       Uses only a few variables for counters and limits, no extra arrays.
