// Beauty Sum of All Substrings

// Problem Statement : Given a string s, return the sum of beauty of all of its substrings.
// The beauty of a string is the difference in frequencies between the most frequent and 
// least frequent characters.
// For example, the beauty of "abaacc" is 3 - 1 = 2.

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], 
// each with beauty equal to 1.

// Solution : 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

int beautySum(string s)
{
    int n = s.size();
    int totalBeauty = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            int maxFreq = INT_MIN, minFreq = INT_MAX;
            for (auto f : freq)
            {
                if (f > 0)
                {
                    maxFreq = max(maxFreq, f);
                    minFreq = min(minFreq, f);
                }
            }

            totalBeauty += (maxFreq - minFreq);
        }
    }

    return totalBeauty;
}
int main()
{
    string s = "aabcb";
    cout << "Beauty Sum of All Substrings: " << beautySum(s) << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N^2) => O(N^2 * 26);
//        O(N^2), for generating all the substring.
//        O(26) => O(1), for hashing the frequency in vector.

//    - Space Complexity : O(1) => O(26);
//        Constant space of is used for all substring hashing.