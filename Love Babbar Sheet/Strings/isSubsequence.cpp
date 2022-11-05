// Link : https://leetcode.com/problems/is-subsequence/
// Time Complexity : O(n)
// Approach-> Loop mein iterate kie jbtk mjhe s[i] nhi mila tbtk bas i aage badhega and s[i] and t[i] match kia toh
// j++ kiya and finally check ki j == n hai toh pura string travel kiye and hence true

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isSubsequence(string s, string t)
{
    int j = 0;
    for (int i = 0; j < s.length() && i < t.length(); i++)
    {
        if (s[j] == t[i])
        {
            j++;
        }
    }
    if (j == s.length())
    {
        return true;
    }
    return false;
}

int main()
{

    return 0;
}