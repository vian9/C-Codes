// Link : https://www.codingninjas.com/codestudio/problems/row-with-maximum-1-s_1112656?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O(n ^ 2)
// Approach-> Bas loop m iterate krte gye and maxCount maintain nd check krte gye.....2 or more nested loop m beech m u cant change
// value of outer loop index value .....wo inner loop pura chlega anf then aayega

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int rowMaxOnes(vector<vector<int>> &mat, int n, int m)
{
    int max = -1;
    int k = 0;
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        count = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            if (mat[j][i] == 1)
            {
                count += 1;
            }
            else
            {
                continue;
            }
        }
        if (count > max)
        {
            max = count;
            k = j;
        }
    }
    return k;
}

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
    }
    return 0;
}