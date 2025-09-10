// Sort Characters By frequency

// Problem Statement : Given a string "s", sort it in decreasing order based on the frequency of
// the characters. The frequency of a character is the number of times it appears in the string.
// "s" consists of uppercase and lowercase English letters and digits.
// Return the sorted string. If there are multiple answers, return any of them.

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// Solution :

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for sort
#include <queue>     //for priority queue
using namespace std;

// OPTIMAL (Using Fixed Size Hash Array)
string frequencySort(string s)
{
    // Creating a hash array for frequency
    vector<pair<char, int>> freq(128, {0, 0});
    for (char c : s)
    {

        freq[(int)c].first = c; // store char
        freq[(int)c].second++;  // increment frequency
    }

    // Lambda function for vector comparison based on frequency only
    auto frequencyComparison = [](auto a, auto b)
    {
        return a.second > b.second; // higher freq first
    };

    // Sorting hash array based on frequency using lambda function
    sort(freq.begin(), freq.end(), frequencyComparison);

    //  Building result string
    string result;
    for (auto it : freq)
    {
        result.append(it.second, it.first); // append(times,char)
    }

    return result;
}

// ALTERNATIVE (Uisng Priority Queue)
string frequencySortAlterative(string s)
{
    // Count character frequencies.
    unordered_map<char, int> counts;
    for (char c : s)
    {
        counts[c]++;
    }

    // Push {frequency, character} pairs into a max-heap.
    priority_queue<pair<int, char>> max_heap; // priority queue is implemented by max_heap
    for (auto [key, val] : counts)
    {
        max_heap.push({val, key});
    }

    // Build the result string from the heap.
    string result = "";
    while (!max_heap.empty())
    {
        pair<int, char> top = max_heap.top();
        max_heap.pop();

        // Append the character 'frequency' times.
        result += string(top.first, top.second);
    }

    return result;
}

int main()
{
    string s = "tree";
    cout << "Original String  : " << s << endl;
    string ans = frequencySort(s);
    cout << "Frequency Sorted : " << ans << endl;
    return 0;
}

// Time and Space Complexity:

//  OPTIMAL (Using Fixed Size Hash Array)
//    - Time Complexity : O(N),
//        O(N), for hashing the string.
//        O(1), for sorting because fixed size of 128.
//        O(N), for generating result from sorted hash.
//    - Space Complexity : O(1)
//        A Fixed size Hash Array used of size 128.

//  ALTERNATIVE (Uisng Priority Queue)
//    - Time Complexity : O(N + Mlog(M))
//        O(N), for iterating and hashing in map.
//        O(log(M)), for every heap operation where M = number of unique characters.
//        Thus total for heap operations is O(Mlog(M)).
//        O(N), for generating result from the heap.
//
//    - Space Complexity : O(M + N)
//        Auxiliary Space: O(M), M = number of unique characters
//        For Output : O(N), N = length of string