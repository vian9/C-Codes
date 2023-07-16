// Link : https://leetcode.com/problems/distinct-subsequences/
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Similar to LCS....bs isme ye krrhe ki jha bhi match horha to usko pick kro and dono mein peeche ya unpick krke string s mein peeche chal jao
// No match to bs string s mein peeche jao....bs yhi h logic.....ye h String match syntax
// 1 based indexing mein hmesa base case and return kya krna h dhyan rkhna

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int prime = 1e9 + 7;

// Space Optimisation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in s and ind2 in t max longest subsequence kitna length ka h
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n + 1 size rkho for 1 index shifting similar for m+1
    // Prev rows use horha and curr
    vector<int> prev(m + 1, 0);

    // Memoisation ka base case save krdenge
    // We will do index shifting ....agar -1 horha toh 0 pr toh n-1 ko n pr rkhdo to save base case of memoisation
    // Jab koi bhi ek string k length over ho jaye toh
    // text 1 ke liye....n rows mein h to i rows mein aayega

    // Jab koi bhi ek string k length over ho jaye toh
    // string s exhaust hogya mtlb pura match nhi hua to 0 return wo already daldo defau;t value ,

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        vector<int> curr(m + 1, 0);
        // Harr ka 0 mein 0 daldo as index shift k baad base case of memoisation
        // Agar string t exhaust hogya to sara match hogya to 1 return krdia
        curr[0] = 1;
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match toh 1 add krke call on ind-1  on both and return....to ye pick krrhe ho
            // And usko match liye bina s ko ind1-1 krdo toh nhi pick kia and peeche dekhne chle gye khi match horha...
            // index shifting hua h toh -1 krdo as string k liye ind 0 to n-1 hi h
            if (s[ind1 - 1] == t[ind2 - 1])
                curr[ind2] = (prev[ind2 - 1] + prev[ind2]) % prime;
            // Agar match nhi kia toh s mein ind1-1 krdenge to check for the match for current char in t
            else
                curr[ind2] = prev[ind2];
        }
        prev = curr;
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    return prev[m];
}

// Tabulation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in s and ind2 in t max kitna max match banrha h
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n + 1 size rkho for 1 index shifting similar for m+1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Memoisation ka base case save krdenge
    // We will do index shifting ....agar -1 horha toh 0 pr toh n-1 ko n pr rkhdo to save base case of memoisation
    // Jab koi bhi ek string k length over ho jaye toh
    // text 1 ke liye....n rows mein h to i rows mein aayega

    // Agar string t exhaust hogya to sara match hogya to 1 return krdia
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    // Jab koi bhi ek string k length over ho jaye toh
    // string s exhaust hogya mtlb pura match nhi hua to 0 return
    // 1 se start kuuki 0 pr humne 1 set krdia h
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match toh 1 add krke call on ind-1  on both and return....to ye pick krrhe ho
            // And usko match liye bina s ko ind1-1 krdo toh nhi pick kia and peeche dekhne chle gye khi match horha...
            // index shifting hua h toh -1 krdo as string k liye ind 0 to n-1 hi h
            if (s[ind1 - 1] == t[ind2 - 1])
                dp[ind1][ind2] = (dp[ind1 - 1][ind2 - 1] + dp[ind1 - 1][ind2]) % prime;
            // Agar match nhi kia toh s mein ind1-1 krdenge to check for the match for current char in t
            else
                dp[ind1][ind2] = dp[ind1 - 1][ind2];
        }
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    return dp[n][m];
}

// Memoisation Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in s and ind2 in t max kitna max match banrha h
int stringHelper(string s, string t, int ind1, int ind2, vector<vector<int>> &dp)
{
    // Jab koi bhi ek string k length over ho jaye toh
    // Agar string t exhaust hogya to sara match hogya to 1 return krdia
    if (ind2 < 0)
        return 1;

    // string s exhaust hogya mtlb pura match nhi hua to 0 return
    if (ind1 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // If a match toh 1 add krke call on ind-1  on both and return....to ye pick krrhe ho
    // And usko match liye bina s ko ind1-1 krdo toh nhi pick kia and peeche dekhne chle gye khi match horha
    if (s[ind1] == t[ind2])
        return dp[ind1][ind2] = stringHelper(s, t, ind1 - 1, ind2 - 1, dp) + stringHelper(s, t, ind1 - 1, ind2, dp);
    // Agar match nhi kia toh s mein ind1-1 krdenge to check for the match for current char in t
    return dp[ind1][ind2] = stringHelper(s, t, ind1 - 1, ind2, dp);
}

int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n size rkho
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return stringHelper(s, t, n - 1, m - 1, dp);
}

// Recursive Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
int stringHelper(string s, string t, int ind1, int ind2)
{
    // Jab koi bhi ek string k length over ho jaye toh
    // Agar string t exhaust hogya to sara match hogya to 1 return krdia
    if (ind2 < 0)
        return 1;

    // string s exhaust hogya mtlb pura match nhi hua to 0 return
    if (ind1 < 0)
        return 0;

    // If a match toh 1 add krke call on ind-1  on both and return....to ye pick krrhe ho
    // And usko match liye bina s ko ind1-1 krdo toh nhi pick kia and peeche dekhne chle gye khi match horha
    if (s[ind1] == t[ind2])
        return stringHelper(s, t, ind1 - 1, ind2 - 1) + stringHelper(s, t, ind1 - 1, ind2);
    // Agar match nhi kia toh s mein ind1-1 krdenge to check for the match for current char in t
    return stringHelper(s, t, ind1 - 1, ind2);
}

int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    return stringHelper(s, t, n - 1, m - 1);
}

int main()
{

    return 0;
}