// Link : https://leetcode.com/problems/split-a-string-in-balanced-strings/
// Time Complexity : O(n)
// Approach-> Take r count and l count nd jha pr barabar aaye just split and last k liye bhi check krlo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int balancedStringSplit(string s)
{
    int rcnt = 0;
    int lcnt = 0;
    int count = 0;
    // simple counting krte h ki jbjb equal ho tordenge
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'R')
            rcnt++;
        else
            lcnt++;
        if (rcnt == lcnt)
        {
            count++;
            rcnt = 0;
            lcnt = 0;
        }
    }
    if (rcnt != lcnt)
        return 1;
    else
        return count;
}

int main()
{

    return 0;
}