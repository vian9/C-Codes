// Link : https://leetcode.com/problems/find-and-replace-pattern/
// Time Complexity : O(n^2)
// Approach-> Similar to Isomorphic Strings Question....harr word k liye check ki isomorphic hai ya nhi
// Agar ek char k liye koi char hai map mein to usse replace krdo otherwise agar char nhi h toh check ki
// Second string ka char nhi h na usme.....agar haai to false otherwise insert and replace

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// M-2....O(n^2)
bool isomorphicString(string a, string b)
{
    unordered_map<char, char> check;
    for (int i = 0; i < a.length(); i++)
    {
        if (check.count(a[i]) > 0)
        {
            a[i] = check[a[i]];
        }
        else
        {
            for (auto &j : check)
            {
                if (j.second == b[i])
                {
                    return false;
                }
            }
            check.insert({a[i], b[i]});
            a[i] = check[a[i]];
        }
    }
    return a.compare(b) == 0;
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
        if (isomorphicString(words[i], pattern))
        {
            ans.push_back(words[i]);
        }
    }
    return ans;
}

int main()
{

    return 0;
}