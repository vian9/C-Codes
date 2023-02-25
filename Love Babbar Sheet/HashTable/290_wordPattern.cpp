// Link : https://leetcode.com/problems/word-pattern/
// Time Complexity : O(n+k)
// Approach-> Get the words ....check in hash map and check for duplicate and then words and letters length

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// phla letter lena h usko word se match krna h
bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> mp;
    int count = 0;
    int k = 0;
    // lelia to get the word out
    for (int i = 0; i < s.length(); i++)
    {
        string st = "";
        int j = i;
        while (s[j] != ' ' && j != s.length())
        {
            st += s[j];
            j++;
        }
        // agar usse letter se correspoding word h
        if (mp.count(pattern[k]) > 0)
        {
            string pt = mp[pattern[k]];
            if (pt != st)
                return false;
        }
        // ab agar letter nhi h to insert it
        if (k < pattern.length())
        {
            mp.insert({pattern[k], st});
            // isme harr word k liye count hoga
            count++;
            // check koi aur same word diff letter se stored nhi h na
            for (auto &m : mp)
            {
                if (m.second == st && m.first != pattern[k])
                    return false;
            }
        }
        else
        {
            return false;
        }
        k++;
        i = j;
    }
    // if number of words is less than pattern length tb false
    if (count < pattern.length())
        return false;
    return true;
}

int main()
{

    return 0;
}