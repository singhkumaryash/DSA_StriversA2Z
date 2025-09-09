// Isomorphic String

// Problem Statement: Given two strings "s" and "t", determine if they are isomorphic.
// Two strings "s" and "t" are isomorphic if the characters in "s" can be replaced to
// get "t".

// All occurrences of a character must be replaced with another character while
// preserving the order of characters. No two characters may map to the same character,
// but a character may map to itself.

// Input : s = "egg" , t = "add"
// Output : true
// Explanation : The 'e' in string s can be replaced with 'a' of string t.
// The 'g' in string s can be replaced with 'd' of t.
// Hence all characters in s can be replaced to get t.

// Input : s = "apple" , t = "bbnbm"
// Output : false
// Explanation : It can be proved that no solution exists for this example.
// All the "b"s in t have to take places of "a", "p", "l", which requires "p" to be
// mapped to "b", but that makes it impossible for "p" at index 2 (0-indexed) to
// become "n". Thus no solution exists.

// Solution :

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Using Map
bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> s2tMap;
    unordered_map<char, int> t2sMap;
    for (int i = 0; i < s.length(); i++)
    {
        char c1 = s[i];
        char c2 = t[i];
        if (s2tMap.count(c1))
        {
            if (s2tMap
                    [c1] != c2)
            {
                return false;
            }
        }
        else
        {
            s2tMap[c1] = c2;
        }
        if (t2sMap.count(c2))
        {
            if (t2sMap[c2] != c1)
            {
                return false;
            }
        }
        else
        {
            t2sMap[c2] = c1;
        }
    }
    return true;
}

// Using Fixed Size Hash Array
bool isIsomorphicAlternative(string s, string t)
{
    if (s.size() != t.size())
        return false;

    vector<int> s2t(256, -1), t2s(256, -1);

    for (int i = 0; i < s.size(); i++)
    {
        char c1 = s[i], c2 = t[i];
        if ((s2t[c1] != -1 && s2t[c1] != c2) ||
            (t2s[c2] != -1 && t2s[c2] != c1))
        {
            return false;
        }
        s2t[c1] = c2;
        t2s[c2] = c1;
    }
    return true;
}

int main()
{
    string s = "egg";
    string t = "add";
    cout << (isIsomorphic(s, t) ? "Yes! Isomorphic Strings" : "No! Not Isomorphic String") << endl;
    return 0;
}

// Time and Space Complexity:

//  Using Map
//    - Time Complexity : Avergae is O(N*1) , Worst is O(N*N), where N = length of strings,
//        We traverse both the string in a single iteration O(N).
//        As we use unordered_map the average case time compleity of operation is O(1),
//        but in the worst case complexity of operation falls to O(N), making overall quadratic.
//
//    - Space Complexity : O(N)
//        As we use map forboth string thus 2*N space in worst case for storing all unique characters.
// NOTES :
// - Using ordered_map will affect the time complexity as all opertion in worst, averge and best case
//   have time complexity of O(logN)

//  Using Fixed Size Hash Array 
//    - Time Complexity : O(N)
//        As we traverse both strings using a single loop for once only.
//
//    - Space Complexity : O(1)
//        We use fixed size hash arrays.