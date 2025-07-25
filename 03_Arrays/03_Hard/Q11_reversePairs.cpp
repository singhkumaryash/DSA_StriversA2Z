#include <iostream>
#include <vector>
using namespace std;

// BRUTE FORCE
int reversePairsBruteForce(vector<int> &arr)
{
    int count = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > 2LL * arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

// OPTIMAL APPROACH
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && (long long)arr[i] > 2LL * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;
    int count = 0;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}

int reversePairsOptimal(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{

    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    cout << "The number of inversion of the array is : "
         << reversePairsOptimal(arr)
         << endl;

    return 0;
}

// BRUTE FORCE
//
// Time Complexity :
// TC is O(n^2), as we use nested loops to compare each element with every other.
//
// Space Complexity :
// SC is O(1), no extra space is used.

// OPTIMAL APPROACH (Using Merge Sort)
//
// Time Complexity :
// TC is O(2n*logn), as it's based on merge sort and we only added another linear pass to count pairs.
//
// Space Complexity :
// SC is O(n), due to the temporary array used during merge operation and recursion stack.
