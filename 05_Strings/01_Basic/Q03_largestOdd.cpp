// Largest Odd Number in String

// Problem Statement : You are given a string num, representing a large integer. Return the
// largest-valued odd integer (as a string) that is a non-empty substring of num, or an
// empty string "" if no odd integer exists.
// A substring is a contiguous sequence of characters within a string.

// Input: num = "35427"
// Output: "35427"
// Explanation: "35427" is already an odd number.

// Solution :

#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num)
{
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int digit = num[i] - '0'; // convert char to int (using ASCII)
        if (digit % 2 == 1)
        {
            return num.substr(0, i + 1); // return if odd string
        }
    }

    return ""; // return empty if even
}

int main()
{
    string num = "35428";
    string ans = largestOddNumber(num);
    if (ans == "")
    {
        cout << "No Odd Integer Exists" << endl;
    }
    else
    {
        cout << "Largest Odd Intger : " << ans << endl;
    }
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N)
//        We iterate through the string once from right to left.
//        Each operation (conversion, modulus, substring) is O(1).
//        Worst case, we check all N digits.
//        Total = O(N).

//    - Space Complexity : O(1)
//        No extra space used.