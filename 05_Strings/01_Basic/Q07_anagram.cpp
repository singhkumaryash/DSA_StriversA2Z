// Valid Anagram

// Problem Statement : Given two strings s and t, return true if t is an anagram of s, and
// false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or
// phrase, typically using all the original letters exactly once.
// NOTE : Only lowercase letters.

// Input : s = "anagram" , t = "nagaram"
// Output : true
// Explanation : We can rearrange the characters of string s to get string t as frequency of
// all characters from both strings is same.

// Input : s = "dog" , t = "cat"
// Output : false
// Explanation : We cannot rearrange the characters of string s to get string t as frequency
// of all characters from both strings is not same.

// Solution :

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int n = s.length();
    vector<int> sHash(26, 0);
    vector<int> tHash(26, 0);
    for (int i = 0; i < n; i++)
    {
        sHash[s[i] - 'a']++; // hashing using ascii conversion
        tHash[t[i] - 'a']++; // hashing using ascii conversion
    }
    for (int i = 0; i < 26; i++)
    {
        if (sHash[i] != tHash[i]) // checking frequency counts
            return false;
    }
    return true;
}

int main()
{
    string s = "anagram";
    string t = "ngarama";
    cout << (isAnagram(s, t) ? "Yes! They are Anagrams." : "No! They are not Anagrams.") << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N) => O(N) + O(1),
//        O(N), for hashing the strings.
//        O(26) => O(1), for comparing the hash of the two strings.
//    - Space Complexity : O(1)
//        Two Fixed size Hash Array used of size 26.