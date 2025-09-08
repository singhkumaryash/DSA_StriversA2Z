// Reverse Words in a String

// Problem Statement : Given an input string 's', reverse the order of the words. A word is defined as a
// sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that 's' may contain leading or trailing spaces or multiple spaces between two words. The returned
// string should only have a single space separating the words. Do not include any extra spaces.

// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Solution :

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{
    int n = s.length();
    string ans = "";
    reverse(s.begin(), s.end()); // first reverse the complete string
    for (int i = 0; i < n; i++)
    {
        string word = "";
        while (i < n && s[i] != ' ')
        {
            word += s[i]; // till space is not encountered a word is counted
            i++;
        }
        reverse(word.begin(), word.end()); // the counted word is reversed
        if (!word.empty())
        {
            if (!ans.empty())
                ans += " "; // add space only between words
            ans += word;
        }
    }

    return ans;
}

int main()
{
    string s = "the sky is blue";
    string ans = reverseWords(s);
    cout << "Original String : " << s << endl;
    cout << "Reversed String : " << ans << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N)
//        Reversing the full string takes O(N).
//        Iterating and reversing each word also takes O(N).
//        Total time = O(N).

//    - Space Complexity : O(N)
//        For the output string ans (required).
//        Auxiliary space is O(1) apart from output storage.
