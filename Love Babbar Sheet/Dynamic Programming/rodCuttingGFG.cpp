// Link : https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
// Time Complexity : O(n*n) SC:O(n)
// Approach-> Same as Unbounded Knapsack....aise socho ki hume n size k stick bnana h...toh hum alag alag size k stick milakr bna skte h...n-1 se start krke
// Agar koi i+1 pr jaye utna length pick kia to ab baaki length pr call krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - yha hum values 0 se pick not pick krrhe and max dekhrhe h
// dp[ind][n] tells us max profit possible from ind 0 to ind with length n
int cutRod(int price[], int n)
{
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < n; i++)
    {
        vall.push_back(price[i]);
    }
    // 1 based indexing h....N-1 se bnarhe h
    // 2 Parameter ind and size n from 0 to W toh 2D Vector
    // Prev row k bs use horha
    vector<int> prev(n + 1, 0);

    // Memoisation ka base case save krenge
    // Agar ind == 0 hai At 0 bs 1 size k bna skte and jo length bacha h uska bnayenge
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * vall[0];
    }

    // 2 nested loop chlega as 2 Parameters and from 1 it will start as 0 save krdia h
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(n + 1, 0);
        // Ye length tells ki usse ind tk ye length aa skte h with max value
        for (int length = 0; length <= n; length++)
        {
            // Not pick
            int notPick = 0 + prev[length];
            // Pick krlia to vall add kro.....and same index pr call krdo
            int pick = -1e9;
            if (ind + 1 <= length)
                pick = vall[ind] + curr[length - (ind + 1)];

            // Return max of values
            curr[length] = max(notPick, pick);
        }
        prev = curr;
    }

    // Jo memoisation mein call hua usse return krenge
    return prev[n];
}

// Tabulation Approach - Bottom Up...yha hum values 0 se pick not pick krrhe and max dekhrhe h
// dp[ind][n] tells us max profit possible from ind 0 to ind with length n
int cutRod(int price[], int n)
{
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < n; i++)
    {
        vall.push_back(price[i]);
    }
    // 1 based indexing h....N-1 se bnarhe h
    // 2 Parameter ind and size n from 0 to W toh 2D Vector
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // Memoisation ka base case save krenge
    // Agar ind == 0 hai At 0 bs 1 size k bna skte and jo length bacha h uska bnayenge
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * vall[0];
    }

    // 2 nested loop chlega as 2 Parameters and from 1 it will start as 0 save krdia h
    for (int ind = 1; ind < n; ind++)
    {
        // Ye length tells ki usse ind tk ye length aa skte h with max value
        for (int length = 0; length <= n; length++)
        {
            // Not pick
            int notPick = 0 + dp[ind - 1][length];
            // Pick krlia to vall add kro.....and same index pr call krdo
            int pick = -1e9;
            if (ind + 1 <= length)
                pick = vall[ind] + dp[ind][length - (ind + 1)];

            // Return max of values
            dp[ind][length] = max(notPick, pick);
        }
    }

    // Jo memoisation mein call hua usse return krenge
    return dp[n - 1][n];
}

// Memoisation Approach - Top Down...yha hum values n-1 se pick not pick krrhe and max dekhrhe h
// dp[ind][n] tells us max profit possible from ind 0 to ind with length n
int pickHelper(vector<int> &val, int n, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        // At 0 bs 1 size k bna skte and jo length bacha h uska bnayenge
        return n * val[0];
    }

    if (dp[ind][n] != -1)
        return dp[ind][n];
    // Not pick
    int notPick = 0 + pickHelper(val, n, ind - 1, dp);
    // Pick krlia to val add kro.....and same index pr call krdo and wo size at i+1 minus kr denge
    int pick = -1e9;
    if (ind + 1 <= n)
        pick = val[ind] + pickHelper(val, n - (ind + 1), ind, dp);

    // Return max of values
    return dp[ind][n] = max(notPick, pick);
}

int cutRod(int price[], int n)
{
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < n; i++)
    {
        vall.push_back(price[i]);
    }
    // 1 based indexing h....N-1 se bnarhe h
    // 2 Parameter ind and size n from 0 to W toh 2D Vector
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return pickHelper(vall, n, n - 1, dp);
}

// Recursive Approach - Top Down...yha hum values 0 se pick not pick krrhe and max dekhrhe h and n length ka bnayenge
int pickHelper(vector<int> &val, int n, int ind)
{
    if (ind == 0)
    {
        // At 0 bs 1 size k bna skte and jo length bacha h uska bnayenge
        return n * val[0];
    }

    // Not pick
    int notPick = 0 + pickHelper(val, n, ind - 1);
    // Pick krlia to val add kro....and same index pr call krdo and wo size at i+1 minus kr denge
    int pick = -1e9;
    if (ind + 1 <= n)
        pick = val[ind] + pickHelper(val, n - (ind + 1), ind);

    // Return max of values
    return max(notPick, pick);
}

int cutRod(int price[], int n)
{
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < n; i++)
    {
        vall.push_back(price[i]);
    }
    // 1 based indexing h....N-1 se bnarhe h
    return pickHelper(vall, n, n - 1);
}

int main()
{

    return 0;
}