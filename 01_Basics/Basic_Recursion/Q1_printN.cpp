// Problem Statement : Print name 'n' numbers of times using recursion.
// Input  : Name = Bob , n=4;
// Output : Bob
//          Bob
//          Bob
//          Bob
//          Bob

// Solution :

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void printN(int n)
{

    if (cnt == n)
    {

        return;
    }
    cout << cnt << endl;

    cnt++;
    printN(n);
}

int main()
{
    int n;
    cout<<"Enter N : ";
    cin >> n;
    printN(n);
    return 0;
}

// Time Complexity :

// TC is O(n) as the function is being called n times and
// everytime it prints which is O(1).

// Space Complexity :

// SC is O(n) because the recursion stack space would be full with
// all the function calls waiting to get completed and that would
// make it an O(N) recursion stack space
