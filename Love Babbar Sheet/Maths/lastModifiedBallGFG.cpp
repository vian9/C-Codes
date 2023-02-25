// Link : https://practice.geeksforgeeks.org/problems/33af95e5935f1f2a0c3f5083c4b9d0db68e97bd4/1
// Time Complexity : O(n)
// Approach-> Jbtk jao tbtk 9 rhe and jaise hi 9 k alawa ho to return.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(int N, vector<int> A)
{
    int val = A[N - 1];
    int i = N - 1;
    while (val == 9 && i >= 1)
    {
        if (A[i - 1] + 1 > 9)
        {
            i--;
            val = A[i];
        }
        else if (A[i - 1] + 1 < 9)
        {
            val = A[i - 1];
            return i;
        }
    }
    return i + 1;
}

int main()
{

    return 0;
}