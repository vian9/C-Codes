// Link : https://leetcode.com/problems/naming-a-company/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long distinctNames(vector<string> &ideas)
{
    unordered_set<string> ct1[26];
    for (int i = 0; i < ideas.size(); i++)
    {
        // suffixes aagye
        ct1[ideas[i][0] - 'a'].insert(ideas[i].substr(1));
    }

    long long ans = 0;
    for (int i = 0; i < ideas.size(); i++)
    {
        string str = ideas[i].substr(1);
        for (int j = 0; j < 26; j++)
        {
            if ((j != ideas[i][0] - 'a') && ct1[j] != str)
            {
                ans += 1;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}