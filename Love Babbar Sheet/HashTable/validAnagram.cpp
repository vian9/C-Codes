// Link : https://leetcode.com/problems/valid-anagram/
// Time Complexity : O(n)
// Approach-> Phle freq lelia and phir dusre string mein check krlia and freq htate gya.....ab agar uske baad freq > 0
// hai toh anagram nhi h
// map.count value nhi deta hai....wo btata h ki wo key present h bas.....bool funct hai only returns 0 or 1 na ki value
// The unordered_map::count() is a builtin method in C++ which is used to count the number of elements present in an unordered_map with a given key.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isAnagram(string s, string t)
{
    // M - 1 : Faster reduced one loop with help of if statement
    unordered_map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (freq.count(t[i]) > 0)
        {
            freq[t[i]]--;
            if (freq[t[i]] == 0)
            {
                freq.erase(t[i]);
            }
        }
        else
            return false;
    }
    return freq.size() == 0;

    // M - 2 : Brute force with map
    unordered_map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (freq.count(t[i]) > 0)
            freq[t[i]]--;
        else
            return false;
    }
    for (auto &i : freq)
    {
        if (i.second > 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}