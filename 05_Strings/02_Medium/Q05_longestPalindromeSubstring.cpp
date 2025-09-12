// Longest Palindromic Substring

// Problem Statement : Given a string 's', return the longest palindromic substring in 's'.

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Solution :

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// BRUTE FORCE
string longestPalindromeBruteForce(string s)
{
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            string sub = s.substr(i, j - i + 1);

            // Lambda function for palindrome check
            auto isPalindrome = [&](string s)
            {
                string rev = s;
                reverse(rev.begin(), rev.end());
                if (rev == s)
                    return true;
                return false;
            };

            if (isPalindrome(sub))
            {
                if (sub.length() > ans.length())
                {
                    ans = sub;
                }
            }
        }
    }
    return ans;
}

// OPTIMAL (Using Two Pointer centre expansion)

// Helper Function
void expandAroundCenter(string &s, int left, int right, int &start, int &maxLen)
{
    int n = s.size();
    while (left >= 0 && right < n && s[left] == s[right])
    {
        if (right - left + 1 > maxLen)
        {
            maxLen = right - left + 1;
            start = left;
        }
        left--;
        right++;
    }
}

// Main Function
string longestPalindrome(string s)
{
    int start = 0;
    int maxLen = 1;
    int n = s.size();
    if (n <= 1)
        return s;

    for (int i = 0; i < n; i++)
    {
        expandAroundCenter(s, i, i, start, maxLen);     // Odd length palindrome
        expandAroundCenter(s, i, i + 1, start, maxLen); // Even length palindrome
    }

    return s.substr(start, maxLen);
}

int main()
{
    string s = "abcdbbfcba";
    cout << "The Longest Palindromic Substring is : " << longestPalindrome(s) << endl;
    return 0;
}

// Time and Space Complexity:

// BRUTE FORCE
//    - Time Complexity : O(N^3)
//        O(N), for iterating every character of string.
//        O(N), for every possible substring from character.
//        O(N), for generating palindrome string of substring.
//        In every iteration these three operation are perfomed making overall O(N^3).

//    - Space Complexity : O(1)
//        No extra sapce used.

// OPTIMAL (Using Two Pointer centre expansion)
//    - Time Complexity : O(N^2),
//        O(N), for iterating every character of string.
//        O(N), for expansion around a character for palindrome check.
//        In every iteration these two operation are perfomed making overall O(N^2).

//    - Space Complexity : O(1)
//        No extra space used.