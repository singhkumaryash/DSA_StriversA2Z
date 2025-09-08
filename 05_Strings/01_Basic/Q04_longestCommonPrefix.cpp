// Longest Common Prefix
//
// Problem Statement : Write a function to find the longest common prefix string
// amongst an array of strings. If there is no common prefix, return an empty string.
//
// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
//
// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return ""; // if input is empty, return ""

    // Compare characters one by one using the first string as reference
    for (int i = 0; i < strs[0].size(); i++) // iterate over first string
    {
        char currentChar = strs[0][i];        // character at position i of first string
        for (int j = 1; j < strs.size(); j++) // check this char in all other strings
        {
            // If index exceeds current string length OR mismatch occurs
            if (i >= strs[j].size() || strs[j][i] != currentChar)
                return strs[0].substr(0, i); // prefix up to i-1
        }
    }

    // If loop finishes, the whole first string is the prefix
    return strs[0];
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    string ans = longestCommonPrefix(strs);
    if (ans == "")
    {
        cout << "No Common Prefix Exists" << endl;
    }
    else
    {
        cout << "Longest Common Prefix is : " << ans << endl;
    }

    return 0;
}

// Time and Space Complexity:
//
//    - Time Complexity : O(N * M)
//        N = number of strings
//        M = length of the shortest string
//        In the worst case, we compare each character of all strings up to M.
//        Total comparisons = O(N * M).
//
//    - Space Complexity : O(1)
//        No extra space is used apart from variables.
//        The result string is built from the input, not additional storage.
