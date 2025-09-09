// Rotate String

// Problem Statement: Given two strings "s" and goal, return true if and only if "s" can become
// goal after some number of shifts on "s".
// A shift on "s" consists of moving the leftmost character of "s" to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.

// Input: s = "abcde", goal = "cdeab"
// Output: true

// Input: s = "abcde", goal = "abced"
// Output: false

// Solution :

#include <iostream>
#include <string>
using namespace std;

// Manually Generating Strings (Brute Force)
bool rotateStringBruteForce(string s, string goal)
{
    if (s.length() != goal.length())
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string rotated = s.substr(i) + s.substr(0, i);
        if (rotated == goal)
        {
            return true;
        }
    }
    return false;
}

// Using find on a doubled string (Optimal)
bool rotateStringOptimal(string s, string goal)
{
    if (s.length() != goal.length())
    {
        return false;
    }
    string doubled = s + s;
    // example "abcdeabcde" contains "cdeab"
    if (doubled.find(goal) == string::npos)
    {
        return false;
    }
    return true;
}

int main()
{
    string s1 = "abcde";
    string goal1 = "cdeab";
    string s2 = "abcde";
    string goal2 = "abced";
    cout << (rotateStringBruteForce(s1, goal1) ? "Yes! Goal can be generated from string." : "No! Goal cannot be generated from string.") << endl;
    cout << (rotateStringBruteForce(s2, goal2) ? "Yes! Goal can be generated from string." : "No! Goal cannot be generated from string.") << endl;
    return 0;
}

// Time and Space Complexity:

//  Manually Generating Strings (Brute Force)
//    - Time Complexity : O(N^2),
//        O(N), for all possible rotations.
//        O(N), for generating rotated using substr.
//    - Space Complexity : O(1)
//        No extra space used.

//  Using find on a doubled string (Optimal)
//    - Time Complexity : O(N)
//        O(1), to concatenate the string twice.
//        O(N), to find substring in string.
//
//    - Space Complexity : O(1)
//        No extra space used.