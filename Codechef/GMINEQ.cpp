/*
You are given an array A
 of length N
 containing the elements −1
 and 1
 only. Determine if it is possible to rearrange the array A
 in such a way that Ai
 is not the geometric mean of Ai−1
 and Ai+1
, for all i
 such that 2≤i≤N−1
.

Y
 is said to be the geometric mean of X
 and Z
 if Y2=X⋅Z
.

Input Format
The first line contains a single integer T
 - the number of test cases. Then the test cases follow.
The first line of each test case contains an integer N
 - the size of the array A
.
The second line of each test case contains N
 space-separated integers A1,A2,…,AN
 denoting the array A
.
Output Format
For each test case, output Yes if it is possible to rearrange A
 in such a way that Ai
 is not the geometric mean of Ai−1
 and Ai+1
, where 2≤i≤N−1
. Otherwise output No.

You may print each character of Yes and No in uppercase or lowercase (for example, yes, yEs, YES will be considered identical).

Constraints
1≤T≤200
3≤N≤1000
Ai∈{−1,1}
Sample Input 1
 3
5
1 1 1 -1 -1
3
1 1 1
6
1 -1 -1 -1 -1 1
Sample Output 1
 Yes
No
Yes
*/

#include <iostream>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin >> n;
    while (n > 0)
    {
        ll t;
        cin >> t;
        ll x[t];
        ll oddCount = 0, evenCount = 0;
        for (ll i = 0; i < t; i++)
        {
            cin >> x[i];
            if (x[i] == 1)
            {
                evenCount += 1;
            }
            else
            {
                oddCount += 1;
            }
        }
        ll diff = abs(evenCount - oddCount);
        if (diff == 0)
        {
            cout << "YES" << endl;
        }
        else if (diff == 1)
        {
            cout << "YES" << endl;
        }
        else if (diff == 2)
        {
            if (evenCount % 2 == 0 && oddCount % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }

        n--;
    }

    return 0;
}