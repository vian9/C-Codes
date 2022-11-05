// Link : https://leetcode.com/problems/longest-palindrome/
// Time Complexity : O(n)
// Approach-> Maine phle map lelia and usme freq harr char k daal dia
// Issue is in conditions when counting......odd mein single freq ek hi aa skta hai jo beech mein aayega
// 2 ka multiple wala sav add hoga pallindrome mein......ab odd mein agar 1 wala nhi liya h to koi ek ko
// pura add krenge baaki odd wale ko multiple of 2 mein krenge.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int longestPalindrome(string s)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
    {
        if (freq.count(s[i]) > 0)
        {
            freq[s[i]] += 1;
        }
        else
        {
            freq.insert({s[i], 1});
        }
    }
    int length = 0;
    bool one = false;
    bool odd = false;
    for (auto &i : freq)
    {
        if (i.second == 1 && !one)
        {
            if (!odd)
            {
                cout << i.first;
                length += 1;
                one = true;
            }
        }
        if (i.second % 2 == 0)
        {
            cout << i.first;
            length += i.second;
        }
        else if (i.second % 2 != 0 && !odd)
        {
            if (i.second != 1)
            {
                if (one)
                {
                    cout << i.first;
                    odd = true;
                    length += (i.second - 1);
                }
                else
                {
                    cout << i.first;
                    odd = true;
                    length += i.second;
                }
            }
        }
        else if (i.second % 2 != 0 && odd)
        {
            if (i.second != 1)
            {
                cout << i.first;
                int val = i.second / 2;
                length += (val * 2);
            }
        }
    }
    return length;
}

int main()
{

    return 0;
}