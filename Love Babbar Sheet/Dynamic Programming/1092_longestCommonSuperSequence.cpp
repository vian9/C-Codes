// Link : https://leetcode.com/problems/shortest-common-supersequence/
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Length of the supersequence will be same as ki LCS jo ho ab baaki se nikal do whi jo bacha.....ab hum whi LCS ka DP Table use krenge jisse ye bna h
// Aur usme agar match krrha h to lelo otherwise jha se aaya h wha jao and jo leave krrhe h usse pick krlo string mein....and reverse string return krdo
// Isme dp table k jrurt h toh Space Optimisation use nhi kr skte...
// Isme memoisation ko bhi 1 based indexing mein shift krna hoga wrna out of bound jayega....memmoisation will give tle so better h ki Tabulation use kro

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Tabulation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in str1 and ind2 in str2 max longest subsequence kitna length ka h
string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n + 1 size rkho for 1 index shifting similar for m+1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Memoisation ka base case save krdenge
    // We will do index shifting ....agar -1 horha toh 0 pr toh n-1 ko n pr rkhdo to save base case of memoisation
    // Jab koi bhi ek string k length over ho jaye toh koi match nhi horha toh usse case mein hum 0 return krdo
    // text 1 ke liye....n rows mein h to i rows mein aayega
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    // Text 2 k liye
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match toh 1 add krke call on ind-1 and return..index shifting hua h toh -1 krdo as string k liye ind 0 to n-1 hi h
            if (str1[ind1 - 1] == str2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
            // its a conditional kaun execute hoga
            // Agar no match to max of dono ind jo call kroge
            else
                dp[ind1][ind2] = 0 + max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
        }
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    int lcs = dp[n][m];
    string ans = "";
    int i = n;
    int j = m;
    int index = lcs - 1;
    // Ab pick krenge
    while (i > 0 && j > 0)
    {
        // Jo index hai 1-based toh wo string mein -1 chlega and dp mein same
        // Dono str match krrha
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            index--;
            i--;
            j--;
        }
        // dp ka jo size h wo i 0 se n tk hai as n+1 similarly for n....so yha i and j waise hi rhega
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            // Ab jisse side k value bada h
            ans += str2[j - 1];
            j--;
        }
        else
        {
            ans += str1[i - 1];
            i--;
        }
    }

    // Ab jo str1 mein jo baaki h copy krdo
    while (i > 0)
    {
        ans += str1[i - 1];
        i--;
    }

    while (j > 0)
    {
        ans += str2[j - 1];
        j--;
    }
    // Reverse krdo string
    reverse(ans.begin(), ans.end());
    return ans;
}

// Memoisation Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in str1 and ind2 in str2 max longest subsequence kitna length ka h
int stringHelper(string str1, string str2, int ind1, int ind2, vector<vector<int>> &dp)
{
    // Jab koi bhi ek string k length over ho jaye toh koi match nhi horha toh usse case mein hum 0 return krdo
    if (ind1 <= 0 || ind2 <= 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    // If a match toh 1 add krke call on ind-1 and return
    if (str1[ind1 - 1] == str2[ind2 - 1])
        return dp[ind1][ind2] = 1 + stringHelper(str1, str2, ind1 - 1, ind2 - 1, dp);
    // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
    // its a conditional kaun execute hoga
    // Agar no match to max of dono ind jo call kroge
    return dp[ind1][ind2] = 0 + max(stringHelper(str1, str2, ind1, ind2 - 1, dp), stringHelper(str1, str2, ind1 - 1, ind2, dp));
}

string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n size rkho

    // 1-based indexing mein shift krdia h so that jb koi ek side mein 0 jaarha tb out of bound na jaye
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int lcs = stringHelper(str1, str2, n, m, dp);
    // Ab mere pass dp table aagya h
    // Ab jha jha match hoga lete jayenge and jha match

    string ans = "";
    int i = n;
    int j = m;
    int index = lcs - 1;
    // Ab pick krenge
    while (i > 0 && j > 0)
    {
        // Jo index hai 1-based toh wo string mein -1 chlega and dp mein same
        // Dono str match krrha
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            index--;
            i--;
            j--;
        }
        // dp ka jo size h wo i 0 se n tk hai as n+1 similarly for n....so yha i and j waise hi rhega
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            // Ab jisse side k value bada h
            ans += str2[j - 1];
            j--;
        }
        else
        {
            ans += str1[i - 1];
            i--;
        }
    }

    // Ab jo str1 mein jo baaki h copy krdo
    while (i > 0)
    {
        ans += str1[i - 1];
        i--;
    }

    while (j > 0)
    {
        ans += str2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}