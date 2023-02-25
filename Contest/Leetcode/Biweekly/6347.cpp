// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    vector<bool> vow(words.size());
    unordered_map<char, int> vowel;
    vowel.insert({'a', 1});
    vowel.insert({'e', 1});
    vowel.insert({'i', 1});
    vowel.insert({'o', 1});
    vowel.insert({'u', 1});
    for (int i = 0; i < words.size(); i++)
    {
        int n = words[i].length();
        char start = words[i][0];
        char end = words[i][n - 1];
        if (vowel.count(start) > 0 && vowel.count(end) > 0)
        {
            vow[i] = true;
        }
        else
        {
            vow[i] = false;
        }
    }
    vector<int> presum(words.size());
    int prefix = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (vow[i])
        {
            prefix += 1;
        }
        presum[i] = prefix;
    }

    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];
        if (start != 0 && start != end)
            ans[i] = presum[end] - presum[start - 1];
        else if (start == 0 && start != end)
            ans[i] = presum[end];
        else if (start == end)
        {
            if (vow[start])
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = 0;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}