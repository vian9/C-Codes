// Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> chars;
    for (int i = 0; i < p.length(); i++)
    {
        chars[p[i]]++;
    }
    int j = 0;
    int len = p.length();
    vector<int> ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (chars.count(s[i]) > 0)
        {
            j = i + 1;
            unordered_map<char, int> check;
            check[s[i]]++;
            while (j - i < p.length())
            {
                if (chars.count(s[j]) > 0)
                {
                    check[s[j]]++;
                    j++;
                }
                else
                {
                    break;
                }
            }
            if (j - i == len && check == chars)
                ans.push_back(i);
        }
    }
    return ans;
}

int main()
{

    return 0;
}