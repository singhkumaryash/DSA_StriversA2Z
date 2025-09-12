// Implement Atoi

// Problem Statement : Implement the myAtoi(string s) function, which converts a string to a
// 32-bit signed integer.
// The algorithm for myAtoi(string s) is as follows:
// 1. Whitespace: Ignore any leading whitespace (" ").
// 2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming
// positivity if neither present.
// 3. Conversion: Read the integer by skipping leading zeros until a non-digit character is
// encountered or the end of the string is reached. If no digits were read, then the result is 0.
// 4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then
// round the integer to remain in the range. Specifically, integers less than -231 should be rounded
// to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

// Return the integer as the final result.

// Input: s = "1337c0d3"
// Output: 1337
// Explanation:
// Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
// Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
// Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)

// Input: s = "words and 987"
// Output: 0
// Explanation: Reading stops at the first non-digit character 'w'.

// Solution :

#include <iostream>
#include <string>
#include <climits>
using namespace std;

int myAtoi(string s)
{
    int i = 0; // index
    long long int ans = 0;
    int sign = 1;
    while (i < s.length() && s[i] == ' ')
    {
        i++; // skips the whitespaces
    }
    if (s[i] == '-')
    {
        sign = -1; // if negative integer change sign
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    while (i < s.length() && isdigit(s[i])) // isdigit verify to be a digit in character only
    {

        ans = (ans * 10) + (s[i] - '0'); // add to answer
        if (ans * sign > INT_MAX)
            return INT_MAX; // Clamp to INT_MAX if overflow occurs
        if (ans * sign < INT_MIN)
            return INT_MIN; // Clamp to INT_MIN if underflow occurs
        i++;
    }
    // return result with sign
    return ans * sign;
}

int main()
{
    string s = "1337c0d3";
    cout << "String  : " << s << "\nInteger : " << myAtoi(s) << endl;

    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N)
//         We graverse the string till all white spaces first. Then again we traverse for digits.
//         In totality we only traverse the strig once, thus O(N).

//    - Space Complexity : O(1)
//         No extra space used.