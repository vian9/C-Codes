// Link : https://leetcode.com/problems/isomorphic-strings/
// Time Complexity : O(n) VVFast
// Approach-> Problem ye tha ki only one character can be mapped to other.....to yhi challenge tha
// Ek map lia and usme check kia ki s[i] hai ya nhi agar hai to s[i] k corresponding value mein check kia
// Agar s[i] nhi hai toh phle pura map mein check kro t[i] hai ya nhi.....agar rha to wo s[i] k corresponding
// nhi hai to false return and agar t[i] nhi h to map mein s[i] t[i] insert kr denge.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> letter;
    for (int i = 0; i < s.length(); i++)
    {
        if (letter.count(s[i]) > 0)
        {
            s[i] = letter[s[i]];
        }
        else
        {
            for (auto &j : letter)
            {
                if (j.second == t[i])
                {
                    return false;
                }
            }
            letter.insert({s[i], t[i]});
            s[i] = letter[s[i]];
        }
    }
    if (s.compare(t) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    return 0;
}