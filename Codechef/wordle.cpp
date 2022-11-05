/*
Chef invented a modified wordle.

There is a hidden word S
 and a guess word T
, both of length 5
.

Chef defines a string M
 to determine the correctness of the guess word. For the ith
 index:

If the guess at the ith
 index is correct, the ith
 character of M
 is 𝙶
.
If the guess at the Ith
 index is wrong, the ith
 character of M
 is 𝙱
.
Given the hidden word S
 and guess T
, determine string M

*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x, y;
    string x1, x2;
    int n;
    string m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        x1 = x.substr(0, 5);
        x2 = y.substr(0, 5);
        for (int i = 0; i < 5; i++)
        {
            if (x1[i] == x2[i])
            {
                m[i] = 'G';
            }
            else
            {
                m[i] = 'B';
            }
        }
        for (int i = 0; i < 5; i++)
        {
            cout << m[i];
        }
        cout << endl;
    }

    return 0;
}