// Problem statement : Sam is curious about Alpha-Hills, so he decided to create Alpha-Hills of different sizes.
// An Alpha-hill is represented by a triangle, where alphabets are filled in palindromic order.
// For every value of ‘N’, help sam to return the corresponding Alpha-Hill.
// Example:
// Input: ‘N’ = 3
// Output:
//     A
//   A B A
// A B C B A

// Solution :

#include <bits/stdc++.h>
using namespace std;

void alphaHill(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char alpha = 'A';

        for (int x = 1; x <= (n - i); x++)
        {
            cout << " ";
        }
        for (int y = 1; y < 2 * i; y++)
        {

            cout<<alpha;
            if (y < i)
            {
                alpha++;
            }
            else
            {
                alpha--;
            }
        }
        for (int z = 1; z < (n - i); z++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Alpha Hill Pattern : " << endl;
    alphaHill(n);
    return 0;
}

// Notes : 'i' is taken as the reaking point in the code as after i the letters start to decrease.
//         To better optimize the code the last loop for space can be skipped, as it would not 
//         have any affect on the output.