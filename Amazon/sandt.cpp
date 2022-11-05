// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maximumOperations(string s, string t)
{
    int ans = 1e9;
    unordered_map<char, int> freqS;
    unordered_map<char, int> freqT;
    for (int i = 0; i < s.length(); i++)
    {
        freqS[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        freqT[t[i]]++;
    }
    for (auto &i : freqT)
    {
        ans = min(ans, freqS[i.first] / i.second);
    }
    return ans;
}

int main()
{

    return 0;
}