// Maximum Nesting Depth of the Parentheses

// Problem Statement : Given a valid parentheses string "s", return the nesting depth of "s".
// The nesting depth is the maximum number of nested parentheses.

// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation: Digit 8 is inside of 3 nested parentheses in the string.

// Solution :

#include <iostream>
#include <string>
using namespace std;

int maxDepth(string s)
{
    int count = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')
            count++;
        else if (ch == ')')
            count--;
        else
            continue;
        ans = max(count, ans);
    }
    return ans;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "The Nesting Depth is " << maxDepth(s) << endl;
}

// Time and Space Complexity:

//    - Time Complexity : O(N)
//        O(N), for string traversal and counter.

//    - Space Complexity : O(1)
//        No extra space used.