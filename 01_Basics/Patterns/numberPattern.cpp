// Problem statement : Ninja has been given a task to print the required
// pattern and he asked for your help with the same.
// You must print a matrix corresponding to the given number pattern.
// Example:
// Input: ‘N’ = 4
// Output:
// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444

// Solution :

#include <iostream>
using namespace std;

void numberPattern(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {

            int top = i;
            int left = j;
            int bottom = 2 * (n - 1) - i;
            int right = 2 * (n - 1) - j;
            cout << (n - min(min(top, bottom), min(left, right))) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Number Pattern : " << endl;
    numberPattern(n);
    return 0;
}

// Note : The pattern here resembles to a cartisian plot and distances.
//        Thus the minimum function is used to find the minimum distance
//        from top, bottom, right and left and then subtracted from 'n'
//        for desired output.