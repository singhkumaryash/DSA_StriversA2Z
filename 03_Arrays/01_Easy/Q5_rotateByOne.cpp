// Problem Statement: Given an array of N integers, left rotate the array by one place

// Input: N = 5, array[] = {1,2,3,4,5}
// Output: 2,3,4,5,1

// Solution :

#include <iostream>
#include <vector>
using namespace std;
void rotateArrayByOne(vector<int> &nums)
{
    int i = nums[0];
    int j = 0;
    while (j != nums.size() - 1)
    {
        nums[j] = nums[j + 1];
        j++;
    }
    nums[j] = i;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Array befor rotating : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
    rotateArrayByOne(arr);
    cout << "Array after rotating : { ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "}" << endl;

    return 0;
}

// Time Complexity :
// TC is O(n); where n is the number of element in the array.
// It is because we traverse the array once using while loop.

// Space Complexity :
// SC is O(1); constant space complexity.