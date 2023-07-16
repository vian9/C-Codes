// Link : https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Isme bs yhi tha jha dp mein sequence break horha no match ka wha dp mein 0 store kro and max value for match store krte jao
// and last mein max return krdo
// Substring is consecutive series of string

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in text1 and ind2 in text2 max longest subsequence kitna length ka h
int longestCommonSubstr(string text1, string text2, int n, int m)
{
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

    int maxi = 0;

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        // Harr ka 0 mein 0 daldo as index shift k baad base case of memoisation
        vector<int> curr(m + 1, -1);
        curr[0] = 0;
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match toh 1 add krke call on ind-1 and return..index shifting hua h toh -1 krdo as string k liye ind 0 to n-1 hi h
            if (text1[ind1 - 1] == text2[ind2 - 1])
            {
                curr[ind2] = 1 + prev[ind2 - 1];
                maxi = max(curr[ind2], maxi);
            }
            // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
            // its a conditional kaun execute hoga
            // Agar no match to 0 daldo as  sequence break horha h
            else
                curr[ind2] = 0;
        }
        prev = curr;
    }
    // maxi return krdo
    return maxi;
}

// Tabulation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in text1 and ind2 in text2 max longest subsequence kitna length ka h
int longestCommonSubstr(string text1, string text2, int n, int m)
{
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
    int maxi = 0;
    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match toh 1 add krke call on ind-1 and return..index shifting hua h toh -1 krdo as string k liye ind 0 to n-1 hi h
            if (text1[ind1 - 1] == text2[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                maxi = max(dp[ind1][ind2], maxi);
            }
            // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
            // its a conditional kaun execute hoga
            // Agar no match to 0 daldo as  sequence break horha h
            else
                dp[ind1][ind2] = 0;
        }
    }
    // maxi return krdo
    return maxi;
}

int main()
{

    return 0;
}