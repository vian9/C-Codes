// Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Bass String ke case mein ye hai dono string ke apne apne index chlenge aur ye dekhna h ki wo current character match krrha h ya nhi...
// agar match krrha h +1 krke dono ko ind-1 call krdo and match nhi toh ek ek baar krke ind-1 char call krdo and return max on it
// Base case neg ko tabulation mein save krrhe to index shifting mein array ka size and string mein access kisse value pr krrhe aur return value will change...
// don't directly copy from memoisation in tabulation as it will give then wrong ans for segmentation glt index pr access krrhe

// LCS of dono string nikal do....ab baaki jo bacha word1 mein wo htao and word2 ka jo nhi h wo daldo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in word1 and ind2 in word2 max longest subsequence kitna length ka h
int longestCommonSubsequence(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n + 1 size rkho for 1 index shifting similar for m+1
    // Prev rows use horha and curr
    vector<int> prev(m + 1, -1);

    // Memoisation ka base case save krdenge
    // We will do index shifting ....agar -1 horha toh 0 pr toh n-1 ko n pr rkhdo to save base case of memoisation
    // Jab koi bhi ek string k length over ho jaye toh koi match nhi horha toh usse case mein hum 0 return krdo
    // text 1 ke liye....n rows mein h to i rows mein aayega
    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i][0] = 0; // curr ka 0 mein jayega
    // }
    // Text 2 k liye
    for (int i = 0; i <= m; i++)
    {
        prev[i] = 0;
    }

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        // Harr ka 0 mein 0 daldo as index shift k baad base case of memoisation
        vector<int> curr(m + 1, -1);
        curr[0] = 0;
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match toh 1 add krke call on ind-1 and return..index shifting hua h toh -1 krdo as string k liye ind 0 to n-1 hi h
            if (word1[ind1 - 1] == word2[ind2 - 1])
                curr[ind2] = 1 + prev[ind2 - 1];
            // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
            // its a conditional kaun execute hoga
            // Agar no match to max of dono ind jo call kroge
            else
                curr[ind2] = 0 + max(curr[ind2 - 1], prev[ind2]);
        }
        prev = curr;
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    return prev[m];
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    int len = longestCommonSubsequence(word1, word2);
    // Ab jo pallindrome h usse rehne do wo same hoga uske alawa word 1 se htao and jo word 2 ka nhi h dalo
    return n + m - 2 * len;
}

// Tabulation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in word1 and ind2 in word2 max longest subsequence kitna length ka h
int longestCommonSubsequence(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
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
            if (word1[ind1 - 1] == word2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
            // its a conditional kaun execute hoga
            // Agar no match to max of dono ind jo call kroge
            else
                dp[ind1][ind2] = 0 + max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
        }
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    return dp[n][m];
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    int len = longestCommonSubsequence(word1, word2);
    // Ab jo pallindrome h usse rehne do wo same hoga uske alawa word 1 se htao and jo word 2 ka nhi h dalo
    return n + m - 2 * len;
}

// Memoisation Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in word1 and ind2 in word2 max longest subsequence kitna length ka h
int stringHelper(string word1, string word2, int ind1, int ind2, vector<vector<int>> &dp)
{
    // Jab koi bhi ek string k length over ho jaye toh koi match nhi horha toh usse case mein hum 0 return krdo
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    // If a match toh 1 add krke call on ind-1 and return
    if (word1[ind1] == word2[ind2])
        return dp[ind1][ind2] = 1 + stringHelper(word1, word2, ind1 - 1, ind2 - 1, dp);
    // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
    // its a conditional kaun execute hoga
    // Agar no match to max of dono ind jo call kroge
    return dp[ind1][ind2] = 0 + max(stringHelper(word1, word2, ind1, ind2 - 1, dp), stringHelper(word1, word2, ind1 - 1, ind2, dp));
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n size rkho
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int len = stringHelper(word1, word2, n - 1, m - 1, dp);
    // Ab jo pallindrome h usse rehne do wo same hoga uske alawa word 1 se htao and jo word 2 ka nhi h dalo
    return n + m - 2 * len;
}

// Recursive Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
int stringHelper(string word1, string word2, int ind1, int ind2)
{
    // Jab koi bhi ek string k length over ho jaye toh koi match nhi horha toh usse case mein hum 0 return krdo
    if (ind1 < 0 || ind2 < 0)
        return 0;

    // If a match toh 1 add krke call on ind-1 and return
    if (word1[ind1] == word2[ind2])
        return 1 + stringHelper(word1, word2, ind1 - 1, ind2 - 1);
    // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
    // its a conditional kaun execute hoga
    // Agar no match to max of dono ind jo call kroge
    return 0 + max(stringHelper(word1, word2, ind1, ind2 - 1), stringHelper(word1, word2, ind1 - 1, ind2));
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    int len = stringHelper(word1, word2, n - 1, m - 1);
    // Ab jo pallindrome h usse rehne do wo same hoga uske alawa word 1 se htao and jo word 2 ka nhi h dalo
    return n + m - 2 * len;
}

int main()
{

    return 0;
}