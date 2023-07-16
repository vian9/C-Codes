// Link : https://leetcode.com/problems/wildcard-matching/
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Similar to LCS...isme bs hum match pr ek ind-1 pr jaarhe wrna hum dono ko ek baar ind-1 call krrhe incase of a *...base case k dhyan rkhna h
// ki kab match kre and 1-based indexing use krrhe h to kaise move kre

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// To check if the remaining string contains only stars
bool isAllStars(string p, int ind2)
{
    while (ind2 >= 0)
    {
        if (p[ind2] != '*')
            return false;
        ind2--;
    }
    return true;
}

// Space Optimisation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in s and ind2 in p match horha ya nhi
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n + 1 size rkho for 1 index shifting similar for m+1
    // Prev rows use horha and curr
    vector<int> prev(m + 1, false);

    // Memoisation ka base case save krdenge
    // We will do index shifting ....agar -1 horha toh 0 pr toh n-1 ko n pr rkhdo to save base case of memoisation
    // Jab koi bhi ek string k length over ho jaye toh

    // Jab dono ka over ho jaye to 0 0 toh true save hoga
    prev[0] = true;
    // Jab string1 over ho jaye and str2 baaki h toh usme all stars check krlo....jo ind 1 se badha h toh str k length i-1 se denge
    // 1 se save krrhe kuuki 0 already true save h
    for (int i = 1; i <= m; i++)
    {
        prev[i] = isAllStars(p, i - 1);
    }
    // No need to check for jb str2 over ho as default mein false lelia h

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        vector<int> curr(m + 1, false);
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match or ? toh call on ind-1 on both and return....to ye pick krrhe ho
            // 1 based indexing so str mein -1 hoga
            if (s[ind1 - 1] == p[ind2 - 1] || p[ind2 - 1] == '?')
                curr[ind2] = prev[ind2 - 1];
            // its a conditional kaun execute hoga
            // Agar no match to * ke liye check
            else if (p[ind2 - 1] == '*')
                // * mein either phle se ek jaye check ya dusra se ek index jake check
                curr[ind2] = (prev[ind2] || curr[ind2 - 1]);
        }
        prev = curr;
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    return prev[m];
}

// Tabulation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in s and ind2 in p match horha ya nhi
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n + 1 size rkho for 1 index shifting similar for m+1
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Memoisation ka base case save krdenge
    // We will do index shifting ....agar -1 horha toh 0 pr toh n-1 ko n pr rkhdo to save base case of memoisation
    // Jab koi bhi ek string k length over ho jaye toh

    // Jab dono ka over ho jaye to 0 0 toh true save hoga
    dp[0][0] = true;
    // Jab string1 over ho jaye and str2 baaki h toh usme all stars check krlo....jo ind 1 se badha h toh str k length i-1 se denge
    // 1 se save krrhe kuuki 0 already true save h
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = isAllStars(p, i - 1);
    }
    // No need to check for jb str2 over ho as default mein false lelia h

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match or ? toh call on ind-1 on both and return....to ye pick krrhe ho
            // 1 based indexing so str mein -1 hoga
            if (s[ind1 - 1] == p[ind2 - 1] || p[ind2 - 1] == '?')
                dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];
            // its a conditional kaun execute hoga
            // Agar no match to * ke liye check
            else if (p[ind2 - 1] == '*')
                // * mein either phle se ek jaye check ya dusra se ek index jake check
                dp[ind1][ind2] = (dp[ind1 - 1][ind2] || dp[ind1][ind2 - 1]);
        }
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    return dp[n][m];
}

// Memoisation Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in s and ind2 in p match horha ya nhi
int stringHelper(string s, string p, int ind1, int ind2, vector<vector<int>> &dp)
{
    // Jab koi bhi ek string k length over ho jaye toh
    // Agar dono exhaust ho jaye to true
    if (ind1 < 0 && ind2 < 0)
        return true;

    // Agar p exhaust ho jaye and s bach jaye to false
    if (ind2 < 0 && ind1 >= 0)
        return false;

    // string s exhaust hogya and p bach gya to check ki bs star to nhi h
    if (ind1 < 0 && ind2 >= 0)
        return isAllStars(p, ind2);

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // If a match or ? toh call on ind-1 on both and return....to ye pick krrhe ho
    if (s[ind1] == p[ind2] || p[ind2] == '?')
        return dp[ind1][ind2] = stringHelper(s, p, ind1 - 1, ind2 - 1, dp);
    // its a conditional kaun execute hoga
    // Agar no match to * ke liye check
    else if (p[ind2] == '*')
        // * mein either phle se ek jaye check ya dusra se ek index jake check
        return dp[ind1][ind2] = (stringHelper(s, p, ind1 - 1, ind2, dp) || stringHelper(s, p, ind1, ind2 - 1, dp));

    return dp[ind1][ind2] = false;
}

bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n size rkho
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return stringHelper(s, p, n - 1, m - 1, dp);
}

// Recursive Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
int stringHelper(string s, string p, int ind1, int ind2)
{
    // Jab koi bhi ek string k length over ho jaye toh
    // Agar dono exhaust ho jaye to true
    if (ind1 < 0 && ind2 < 0)
        return true;

    // Agar p exhaust ho jaye and s bach jaye to false
    if (ind2 < 0 && ind1 >= 0)
        return false;

    // string s exhaust hogya and p bach gya to check ki bs star to nhi h
    if (ind1 < 0 && ind2 >= 0)
        return isAllStars(p, ind2);

    // If a match or ? toh call on ind-1 on both and return....to ye pick krrhe ho
    if (s[ind1] == p[ind2] || p[ind2] == '?')
        return stringHelper(s, p, ind1 - 1, ind2 - 1);
    // its a conditional kaun execute hoga
    // Agar no match to * ke liye check
    else if (p[ind2] == '*')
        // * mein either phle se ek jaye check ya dusra se ek index jake check
        return (stringHelper(s, p, ind1 - 1, ind2) || stringHelper(s, p, ind1, ind2 - 1));

    return false;
}

bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    return stringHelper(s, p, n - 1, m - 1);
}

int main()
{

    return 0;
}