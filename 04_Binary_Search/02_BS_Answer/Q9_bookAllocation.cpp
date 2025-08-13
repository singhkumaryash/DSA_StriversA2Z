// Allocate Minimum Number of Pages

// Problem Statement : Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of
// pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all
// the books to the students.

// Allocate books in such a way that:
// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned
// to a student is minimum. If the allocation of books is not possible. return -1

// Input Format: n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
// Result: 71
// Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.

// We can allocate books in several ways but it is clearly said in the question that we have to
// allocate the books in such a way that the maximum number of pages received by a student should
// be minimum.
// Assume the given array is {25 46 28 49 24} and number of students, M = 4. Now, we can allocate
// these books in different ways. Some of them are the following:

// 25 | 46 | 28 | 49, 24  → Maximum no. of pages a student receive = 73
// 25 | 46 | 28, 49 | 24  → Maximum no. of pages a student receive = 77
// 25 | 46, 28 | 49 | 24  → Maximum no. of pages a student receive = 74
// 25, 46 | 28 | 49 | 24  → Maximum no. of pages a student receive = 71

// From the above allocations, we can clearly observe that the minimum possible maximum number of
// pages is 71.

// Solution :

#include <iostream>
#include <vector>
#include <algorithm> // for *max_element
#include <numeric>   // for accumulate
using namespace std;

bool isPossibleSolution(vector<int> &arr, int n, int m, int mid)
{

    int pageSum = 0;
    int studentCount = 1;
    for (int i = 0; i < n; i++)
    {
        // add pages to current student
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }

        // add pages to next student
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
        if (studentCount > m)
        {
            return false;
        }
    }
    return true;
}
int findPages(vector<int> &arr, int n, int m)
{
    // not possible to allocate books
    if (m > n)
    {
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());   // max of array
    int high = accumulate(arr.begin(), arr.end(), 0); // sum of array
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossibleSolution(arr, n, m, mid)) // when true
        {
            high = mid - 1;
        }
        else // when false
        {
            low = mid + 1;
        }
    }

    return low; // *opposite polarity
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;

    cout << "The answer is : " << findPages(arr, n, m) << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N * log(max-sum))
//        Everytime we check if a page sum is a possible solution taking O(N).
//        Rest to calculate the minimum possible maximum number of pages we use
//        binary search from maximum of the array to the sum of the array taking O(log(max-sum)).

//    - Space Complexity : O(1)
//        No extra space is used.

// NOTE : Brute force would be to use linear search instead of binary search in
//        the function, rest same.
