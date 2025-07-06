// Problem Statement: Given a string, check if the string is palindrome or not.
// A string is said to be palindrome if the reverse of the string is the same as the string.

// Input: Str =  “ABCDCBA”
// Output: Palindrome

// Solution :

#include <iostream>
using namespace std;
bool palindromeCheck(int i, string &s)
{
    if (i >= s.size() / 2)
    {
        return true;
    }
    if (s[i] != s[s.size() - i - 1])
    {
        return false;
    }
    return palindromeCheck(i + 1, s);
}
int main()
{
    string s = "madam";
    cout << "The string " << s << " is" << (palindromeCheck(0, s) ? " a Palindrome." : " not a Palindrome.") << endl;
    return 0;
}

// Time Complexity :

// TC is O(n/2) = O(n) as the function is called n/2 times.

// Space Complexity :

// SC is O(n/2)= O(n) because the recursion stack space would be full with
// all the function calls waiting to get completed and that would
// make it an O(n) recursion stack space
