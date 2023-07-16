// Link : https://leetcode.com/problems/edit-distance/
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Similar to LCS...isme bs hum match pr ek ind-1 pr jaarhe wrna min of insert, replace and delete dekhrhe h....
// isme 1 based indexing pr string k index and base case kaise save hoga dhyan rkho

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1-1 in word1 and ind2-1 in word2 min edit required kitna h
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n + 1 size rkho for 1 index shifting similar for m+1
    // Prev rows use horha and curr
    vector<int> prev(m + 1, 0);

    // Memoisation ka base case save krdenge
    // We will do index shifting ....agar -1 horha toh 0 pr toh n-1 ko n pr rkhdo to save base case of memoisation
    // Jab koi bhi ek string k length over ho jaye toh
    // string word1 exhaust hogya mtlb pura match nhi hua to word2 mein jitna baaki h wo return..kuuki abhi bhi word1 mein utna changes krna h edit to convert...
    // so index 1 se badha tha toh string mein index 1 se ghata hoga but len will be i...so i means ki i baaki h string mein toh that's value will be put
    for (int i = 0; i <= m; i++)
    {
        prev[i] = i;
    }

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        // Agar string word2 exhaust hogya to sara match hogya to ind1 return krdo.
        // Harr ka 0 mein 0 daldo as index shift k baad base case of memoisation
        vector<int> curr(m + 1, -1);
        curr[0] = ind1;
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match toh call on ind-1 on both and return....to ye pick krrhe ho
            // 1 based indexing to string mein -1 aayega
            if (word1[ind1 - 1] == word2[ind2 - 1])
                curr[ind2] = prev[ind2 - 1];
            // Dono match unmatch se min nhi lerhe kuuki match krrha whi 0 add krrha h and uske neeche pr jaarha and match nhi to no comparision
            // its a conditional kaun execute hoga
            // Agar no match to min of all execute hoga
            // Yha insertion , deletion and replace h.....insert mein word1 mein insert krenge and wo ek peeche aaya jo same as ind1 h and word2 mein ek peeche ind2-1
            // Deletion mein word1 mein ek peeche and word2 same and replace mein dono mein ek peeche
            else
                curr[ind2] = 1 + min(curr[ind2 - 1], min(prev[ind2], prev[ind2 - 1]));
        }
        prev = curr;
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    return prev[m];
}

// Tabulation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1-1 in word1 and ind2-1 in word2 min edit required kitna h
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n + 1 size rkho for 1 index shifting similar for m+1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Memoisation ka base case save krdenge
    // We will do index shifting ....agar -1 horha toh 0 pr toh n-1 ko n pr rkhdo to save base case of memoisation
    // Jab koi bhi ek string k length over ho jaye toh
    // Agar string word2 exhaust hogya to sara match hogya to ind1 return krdo...kuuki abhi bhi word1 mein utna changes krna h edit to convert...
    // so index 1 se badha tha toh string mein index 1 se ghata hoga but len will be i...so i means ki i baaki h string mein toh that's value will be put
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match toh call on ind-1 on both and return....to ye pick krrhe ho
            // 1 based indexing to string mein -1 aayega
            if (word1[ind1 - 1] == word2[ind2 - 1])
                dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];
            // Dono match unmatch se min nhi lerhe kuuki match krrha whi 0 add krrha h and uske neeche pr jaarha and match nhi to no comparision
            // its a conditional kaun execute hoga
            // Agar no match to min of all execute hoga
            // Yha insertion , deletion and replace h.....insert mein word1 mein insert krenge and wo ek peeche aaya jo same as ind1 h and word2 mein ek peeche ind2-1
            // Deletion mein word1 mein ek peeche and word2 same and replace mein dono mein ek peeche
            else
                dp[ind1][ind2] = 1 + min(dp[ind1][ind2 - 1], min(dp[ind1 - 1][ind2], dp[ind1 - 1][ind2 - 1]));
        }
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    return dp[n][m];
}

// Memoisation Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in word1 and ind2 in word2 min edit required kitna h
int stringHelper(string word1, string word2, int ind1, int ind2, vector<vector<int>> &dp)
{
    // Jab koi bhi ek string k length over ho jaye toh
    // Agar string word2 exhaust hogya to sara match hogya to ind1+1 return krdo...kuuki abhi bhi word1 mein utna changes krna h edit to convert
    if (ind2 < 0)
        return ind1 + 1;

    // string word1 exhaust hogya mtlb pura match nhi hua to word2 mein jitna baaki h wo return
    if (ind1 < 0)
        return ind2 + 1;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // If a match toh call on ind-1 on both and return....to ye pick krrhe ho
    if (word1[ind1] == word2[ind2])
        return dp[ind1][ind2] = stringHelper(word1, word2, ind1 - 1, ind2 - 1, dp);
    // Dono match unmatch se min nhi lerhe kuuki match krrha whi 0 add krrha h and uske neeche pr jaarha and match nhi to no comparision
    // its a conditional kaun execute hoga
    // Agar no match to min of all execute hoga
    // Yha insertion , deletion and replace h.....insert mein word1 mein insert krenge and wo ek peeche aaya jo same as ind1 h and word2 mein ek peeche ind2-1
    // Deletion mein word1 mein ek peeche and word2 same and replace mein dono mein ek peeche
    return dp[ind1][ind2] = 1 + min(stringHelper(word1, word2, ind1, ind2 - 1, dp), min(stringHelper(word1, word2, ind1 - 1, ind2, dp), stringHelper(word1, word2, ind1 - 1, ind2 - 1, dp)));
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n size rkho
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return stringHelper(word1, word2, n - 1, m - 1, dp);
}

// Recursive Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
int stringHelper(string word1, string word2, int ind1, int ind2)
{
    // Jab koi bhi ek string k length over ho jaye toh
    // Agar string word2 exhaust hogya to sara match hogya to ind1+1 return krdo...kuuki abhi bhi word1 mein utna changes krna h edit to convert
    if (ind2 < 0)
        return ind1 + 1;

    // string word1 exhaust hogya mtlb pura match nhi hua to word2 mein jitna baaki h wo return
    if (ind1 < 0)
        return ind2 + 1;

    // If a match toh call on ind-1 on both and return....to ye pick krrhe ho
    if (word1[ind1] == word2[ind2])
        return stringHelper(word1, word2, ind1 - 1, ind2 - 1);
    // Dono match unmatch se min nhi lerhe kuuki match krrha whi 0 add krrha h and uske neeche pr jaarha and match nhi to no comparision
    // its a conditional kaun execute hoga
    // Agar no match to min of all execute hoga
    // Yha insertion , deletion and replace h.....insert mein word1 mein insert krenge and wo ek peeche aaya jo same as ind1 h and word2 mein ek peeche ind2-1
    // Deletion mein word1 mein ek peeche and word2 same and replace mein dono mein ek peeche
    return 1 + min(stringHelper(word1, word2, ind1, ind2 - 1), min(stringHelper(word1, word2, ind1 - 1, ind2), stringHelper(word1, word2, ind1 - 1, ind2 - 1)));
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    return stringHelper(word1, word2, n - 1, m - 1);
}

int main()
{

    return 0;
}