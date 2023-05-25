// Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time Complexity : O(n)
// Approach-> Loop mein move kro aur map mein insert krte jao index k sth...agar element map mein phle se h
// toh count push kro and start and count ko update kro and
// purane elements jo hai repeated usse delete krte jao jbtk repeated wale element tk na erase krdo
// Issue....val[s[i]] k jagah insert use krne pr ans sahi nhi aarha

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// optimal...O(n) time
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int len = 0;
    int count = 0;
    int last = -1;
    for (int i = 0; i < s.length(); i++)
    {
        char curr = s[i];
        // Last bs maintain krrha and agar usse bda h nd repeat horha tbhi consider kro
        if (mp.count(s[i]) > 0 && mp[s[i]] > last)
        {
            len = max(len, count);
            last = mp[s[i]];
            count = i - mp[s[i]];
            mp[s[i]] = i;
        }
        else
        {
            mp[s[i]] = i;
            count++;
        }
    }
    len = max(len, count);
    return len;
}

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> val;
    int start = 0, end = 0;
    int count = 0;
    int maxi = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (val.count(s[i]) > 0)
        {
            maxi = max(maxi, count);
            int res = start;
            // updated start- jahan se repeat hua uske baad wala se start updated
            start = (val[s[i]] + 1);
            // purana element from last start to place where the element repeated erase krrhe
            for (int j = res; j <= val[s[i]]; j++)
            {
                val.erase(s[j]);
            }
            // count will be i - updated start....+1 for the current element jo push hoga
            count = (i - start + 1);
            val[s[i]] = i;
            end = i;
        }
        else
        {
            count++;
            val[s[i]] = i;
            end++;
        }
    }
    maxi = max(maxi, count);

    return maxi;
}

int main()
{

    return 0;
}