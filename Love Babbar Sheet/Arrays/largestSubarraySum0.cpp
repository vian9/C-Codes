// Link : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Time Complexity : O(n)
// Approach-> Map lelo and usme elements k sum dalte jao....agar sum same aagye mtlb 0 horha beech m

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxLen(vector<int> &A, int n)
{
    unordered_map<int, int> mp;
    int len = 0;
    mp[0] = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        // Sum barabar h mtlb beech m 0 hua h
        if (mp.count(sum) > 0)
        {
            len = max(len, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return len;
}

int main()
{

    return 0;
}