// Link : https://leetcode.com/problems/longest-common-subsequence/
// Time Complexity : O(n*m)
// Approach-> Bas main yhi h match or not match....if match toh 1+string mein left move ....otherwise no match toh
// ek mein whi ek mein left se jo max aayega

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Dp- Tabulation - Time : O(n*m) and Space : O(n+m)
int longestCommonSubsequence(string text1, string text2)
{
    // Base Case
    if (text1.length() == 0 || text2.length() == 0)
    {
        return 0;
    }
    int n = text1.length();
    int m = text2.length();
    // Length of vector will be equal to row no
    vector<int> prevRow(m + 1, 0);
    vector<int> currRow(m + 1, 0);
    // phla row ka savka value 0 k barabar
    for (int j = 0; j <= m; j++)
    {
        prevRow[j] = 0;
    }
    // Index shifted....0 par jb koi char nhi lia
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                // Jahan jahan i-1 tha mtlb prev row and i tha mtlb current row
                currRow[j] = 1 + prevRow[j - 1];
            }
            // agar match nhi hua toh ek peche jayega and ek nhi aur unme se max length
            else
                currRow[j] = max(prevRow[j], currRow[j - 1]);
        }
        // This line directly copies value from one vector to another if dimension of vector is same
        prevRow = currRow;
    }
    // Last mein longest value store ho jayega
    return prevRow[m];
}

// Dp- Tabulation - Time : O(n*m) and Space : O(n*m)
int longestCommonSubsequence(string text1, string text2)
{
    // Base Case
    if (text1.length() == 0 || text2.length() == 0)
    {
        return 0;
    }
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // Index shifted....0 par jb koi char nhi lia
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // agar match nhi hua toh ek peche jayega and ek nhi aur unme se max length
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// Memoization...O(n*m) time and O(n*m) + O(n*m) Stack Space
int commonSubsequence(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    // Base Case
    if (i < 0 || j < 0)
        return 0;

    // Check for save value
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + commonSubsequence(s1, s2, i - 1, j - 1, dp);
    }
    // agar match nhi hua toh ek peche jayega and ek nhi aur unme se max length
    return dp[i][j] = max(commonSubsequence(s1, s2, i - 1, j, dp), commonSubsequence(s1, s2, i, j - 1, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    if (text1.length() == 0 || text2.length() == 0)
    {
        return 0;
    }
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return commonSubsequence(text1, text2, text1.length() - 1, text2.length() - 1, dp);
}

// Recursive - TLE...O(2^n)
int commonSubsequence(string s1, string s2, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;

    // String mein check for match or no match....agar match h toh dono ek peeche jayega
    if (s1[i] == s2[j])
    {
        return 1 + commonSubsequence(s1, s2, i - 1, j - 1);
    }
    // agar match nhi hua toh ek peche jayega and ek nhi aur unme se max length
    return max(commonSubsequence(s1, s2, i - 1, j), commonSubsequence(s1, s2, i, j - 1));
}

int longestCommonSubsequence(string text1, string text2)
{
    if (text1.length() == 0 || text2.length() == 0)
    {
        return 0;
    }

    return commonSubsequence(s1, s2, text1.length() - 1, text2.length() - 1);
}

int main()
{

    return 0;
}