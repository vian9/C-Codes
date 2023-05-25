// Link : https://leetcode.com/problems/optimal-partition-of-string/
// Time Complexity : O(n) and space : O(n)
// Approach-> Substring se start index and wo char last kb aaya wo maintain kro and count rkhlo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Optimal O(1).....Bit manipulation
int partitionString(string s)
{
    int i = 0, ans = 1, flag = 0;
    while (i < s.size())
    {
        // left shift krdo wo val k sth
        int val = s[i] - 'a';
        // Jb flag h ki exist krrha and set (1) bhi h
        if (flag & (1 << val))
        {
            flag = 0;
            ans++;
        }

        flag = flag | (1 << val);
        i++;
    }
    return ans;
}

int partitionString(string s)
{
    // Brute force - unique kitna h sequence mein...phir optimise kro
    unordered_map<char, int> mp;
    int count = 1;
    // Ab substring se start kro
    int subStart = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // wo char exist krrha ho and ye subString start mein hi ho ie current substring tbhi count increase kro
        if (mp.count(s[i]) > 0 && mp[s[i]] >= subStart)
        {
            subStart = i;
            count++;
        }
        mp[s[i]] = i;
    }
    return count;
}

int main()
{

    return 0;
}