// Find the missing number in an array

// Problem Statement : Given an integer array of size n containing distinct values
// in the range from 0 to n (inclusive), return the only number missing from the
// array within this range.

// Input: nums = [0, 1, 2, 4, 5, 6]
// Output: 3
// Explanation: nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number
// in the range [0, 6]

// Solution :

#include <iostream>
#include <vector>

using namespace std;

// BRUTE FORCE : 
// int missingNumber(vector<int> &arr, int n)
// {
//     for (int i = 0; i <= n; i++)
//     {
//         int flag = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] == i)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// USING HASHING : 
// int missingNumber(vector<int> arr, int n)
// {
//     vector<int> hash(n + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         hash[arr[i]]++;
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         if (hash[i] == 0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// NATURAL SUM OPTIMAL : 
// int missingNumber(vector<int> &arr, int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }
//     int nSum = (n * (n + 1)) / 2;
//     return nSum - sum;
// }

// XOR OPTIMAL : 
int missingNumber(vector<int> &arr, int n)
{
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= i;
        xor2 ^= arr[i];
    }
    xor1 ^= n;
    return xor1 ^ xor2;
}
int main()
{
    vector<int> arr = {1, 2, 0, 4, 5, 3, 6};
    cout << "The missing number in array is " << missingNumber(arr, arr.size()) << endl;

    return 0;
}

// 1. BRUTE FORCE Approach:

//    - Time Complexity : O(n^2)
//      > Outer loop runs n+1 times (from 0 to n)
//      > Inner loop runs up to n times in worst case

//    - Space Complexity : O(1)
//      > No extra data structures used, just a few variables

// 2. HASHING Approach:

//    - Time Complexity : O(n)
//      > One pass to fill the hash array, one pass to find the missing

//    - Space Complexity : O(n)
//      > A hash array of size n+1 is used

// 3. SUM Formula (Optimal):

//    - Time Complexity : O(n)
//      > One pass to calculate sum of array elements
     
//    - Space Complexity : O(1)
//      > No extra data structures, just two variables

// 4. XOR Method (Optimal):

//    - Time Complexity : O(n)
//      > Two passes: one for [0...n], one for array elements

//    - Space Complexity : O(1)
//      > Only a few integer variables used


//   NOTE : 
// - Use XOR or SUM formula for optimal results with **O(n)** time and **O(1)** space
// - Use Hashing only when extra space is acceptable
// - Brute force is not suitable for large `n`


