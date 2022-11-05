/*
An array A
 of length N
 is said to be pseudo-sorted if it can be made non-decreasing after performing the following operation at most once.

Choose an i
 such that 1≤i≤N−1
 and swap Ai
 and Ai+1
Given an array A
, determine if it is pseudo-sorted or not.

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
For each testcase, output YES if the array A
 is pseudo-sorted, NO otherwise.

You may print each character of YES and NO in uppercase or lowercase (for example, yes, yEs, Yes will be considered identical).

Constraints
1≤T≤1000
2≤N≤105
1≤Ai≤109
Sum of N
 over all test cases do not exceed 2⋅105
Sample Input 1
 3
5
3 5 7 8 9
4
1 3 2 3
3
3 2 1
Sample Output 1
 YES
YES
NO
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
        ll x;
        cin >> x;
        ll a[x];
        for (int i = 0; i < x; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < x - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                break;
            }
        }
        int flag = 0;
        for (int i = 0; i < x - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        n--;
    }

    return 0;
}