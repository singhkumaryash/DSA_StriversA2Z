// Painter's Partition Problem

// Problem Statement : Given an array/list of length ‘N’, where the array/list represents the boards and
// each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters
// are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’
// boards under the constraint that any painter will only paint the continuous sections of boards.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <numeric>   // for accumulate
using namespace std;

int countPainters(vector<int> &boards, int time)
{
    int n = boards.size(); // size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++)
    {
        if (boardsPainter + boards[i] <= time)
        {
            // allocate board to current painter
            boardsPainter += boards[i];
        }
        else
        {
            // allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int minTimeToPaint(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    // Apply binary search:
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = minTimeToPaint(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

// NOTE* : The problem is similar to book allocation and split array.

// Time and Space Complexity:

//    - Time Complexity : O(N * log(sum-max))
//        Everytime we check if an area is a possible solution taking O(N).
//        Rest to calculate the mimimum time to paint we use
//        binary search from maximum of the array to the sum of the array taking O(log(max-sum)).

//    - Space Complexity : O(1)
//        No extra space is used.

// NOTE : Brute force would be to use linear search instead of binary search in
//        the function, rest same.