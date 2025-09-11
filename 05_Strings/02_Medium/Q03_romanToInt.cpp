// Roman To Integer
// Problem Statement : Roman numerals are represented by seven different symbols:

// I = 1
// V = 5
// X = 10
// L = 50
// C = 100
// D = 500
// M = 1000
// Roman numerals are typically written from largest to smallest, left to right. However, in
// specific cases, a smaller numeral placed before a larger one indicates subtraction.
// The following subtractive combinations are valid:
// I before V (5) and X (10) → 4 and 9
// X before L (50) and C (100) → 40 and 90
// C before D (500) and M (1000) → 400 and 900
// Given a Roman numeral, convert it to an integer.

// Input: s = "XLII"
// Output: 42
// Explanation: XL = 40, II = 2 → 40 + 2 = 42

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int romanToInt(string s)
{
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int result = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i < s.length() - 1 && roman[s[i]] < roman[s[i + 1]])
        {
            result -= int(roman[s[i]]);
        }
        else
        {
            result += int(roman[s[i]]);
        }
    }
    return result;
}
int main()
{
    string s = "XLII";
    int roman = romanToInt(s);
    cout << "Roman   : " << s << "\nInteger : " << roman << endl;
    return 0;
}

// Time and Space Complexity:

//    - Time Complexity : O(N)
//        O(N), for string traversal and conversion.
//        O(7) => O(1), for lookup in the map.

//    - Space Complexity : O(1)
//        O(7) => O(1), fixed size map is used.

// NOTE* : The time and space complexity will get affected a little by the type of data struncture
//         used like unordered map, ordered map, static array, vetor etc.
//         The lookup time will be affected but would be nothing significant because as it is fixed
//         size the big O notation will fall at most to total size; i.e, O(7) => O(1).