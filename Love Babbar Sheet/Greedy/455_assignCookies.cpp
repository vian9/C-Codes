// Link : https://leetcode.com/problems/assign-cookies/
// Time Complexity : O(nlogn)
// Approach-> Phle sort krdo and then uska s ko iterate krdo jbtk equal size na aa jaye

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0;
    int k = 0;
    int i = 0;
    // Cookie pr iterate kro kuuki wo chota ho skta h s....toh s ko iterate kro
    while (i < s.size())
    {
        if (k < g.size() && g[k] <= s[i])
        {
            k++;
            count++;
        }
        i++;
    }

    return count;
}

int main()
{

    return 0;
}