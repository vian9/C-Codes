// Link : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Isme hume W rkhna h and such that max Profit....greedy nhi lga skte kuuki uniform nhi hai distribution...ek jada profit wla chiz utha lia
// wo jada weight lelia to ab baaki nhi kr skte but 2 ko milakr jada usse profit ho skta tha to saara combination dekhna hoga and also
// jab bhi kuch pick krrhe toh same ind pr call krdo as infinite pick h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up...yha hum values 0 se pick not pick krrhe and max dekhrhe h
// dp[ind][W] tells us max profit possible from ind 0 to ind with Weight max W
int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> wtt;
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < N; i++)
    {
        wtt.push_back(wt[i]);
        vall.push_back(val[i]);
    }
    // 2 Parameter ind and weigth from 0 to W toh 2D Vector...yha default value 0 krdia for 1st case run kre to dikkat na aaye
    // Prev row k bs use horha
    vector<int> prev(W + 1, 0);

    // Memoisation ka base case save krenge
    // Agar ind == 0 hai toh jo current weight aarha h usse wt[0] se divide krdo and vall[0] se multiply hoga as vall is dependent on ind
    // wtt[0] se chota weight pr 0 hi hoga jo already default value h
    // Also agar wtt[0] se kaam hoga weight W to usse nhi le skte toh 0 hi
    for (int i = wtt[0]; i <= W; i++)
    {
        prev[i] = (int)(i / wtt[0]) * vall[0];
    }

    // 2 nested loop chlega as 2 Parameters and from 1 it will start as 0 save krdia h
    for (int ind = 1; ind < N; ind++)
    {
        vector<int> curr(W + 1, 0);
        // Ye weight tells ki usse ind tk ye weight aa skte h with max value
        for (int weight = 0; weight <= W; weight++)
        {
            // Not pick
            int notPick = 0 + prev[weight];
            // Pick krlia to vall add kro....and same index pr call krdo so curr
            int pick = -1e9;
            if (wtt[ind] <= weight)
                pick = vall[ind] + curr[weight - wt[ind]];

            // Return max of values
            curr[weight] = max(notPick, pick);
        }
        prev = curr;
    }

    // Jo memoisation mein call hua usse return krenge
    return prev[W];
}

// Tabulation Approach - Bottom Up...yha hum values 0 se pick not pick krrhe and max dekhrhe h
// dp[ind][W] tells us max profit possible from ind 0 to ind with Weight max W
int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> wtt;
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < N; i++)
    {
        wtt.push_back(wt[i]);
        vall.push_back(val[i]);
    }
    // 2 Parameter ind and weigth from 0 to W toh 2D Vector...yha default value 0 krdia for 1st case run kre to dikkat na aaye
    vector<vector<int>> dp(N, vector<int>(W + 1, 0));

    // Memoisation ka base case save krenge
    // Agar ind == 0 hai toh jo current weight aarha h usse wt[0] se divide krdo and vall[0] se multiply hoga as vall is dependent on ind
    // wtt[0] se chota weight pr 0 hi hoga jo already default value h
    // Also agar wtt[0] se kaam hoga weight W to usse nhi le skte toh 0 hi
    for (int i = wtt[0]; i <= W; i++)
    {
        dp[0][i] = (int)(i / wtt[0]) * vall[0];
    }

    // 2 nested loop chlega as 2 Parameters and from 1 it will start as 0 save krdia h
    for (int ind = 1; ind < N; ind++)
    {
        // Ye weight tells ki usse ind tk ye weight aa skte h with max value
        for (int weight = 0; weight <= W; weight++)
        {
            // Not pick
            int notPick = 0 + dp[ind - 1][weight];
            // Pick krlia to vall add kro.....and same index pr call krdo
            int pick = -1e9;
            if (wtt[ind] <= weight)
                pick = vall[ind] + dp[ind][weight - wt[ind]];

            // Return max of values
            dp[ind][weight] = max(notPick, pick);
        }
    }

    // Jo memoisation mein call hua usse return krenge
    return dp[N - 1][W];
}

// Memoisation Approach - Top Down...yha hum values N-1 se pick not pick krrhe and max dekhrhe h
// dp[ind][W] tells us max profit possible from ind 0 to ind with Weight max W
int pickHelper(vector<int> &wt, vector<int> &val, int W, int N, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        // Agar weight rkh skte ho to...infinite no of times rkh skte h na
        return (int)(W / wt[0]) * val[0];
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];
    // Not pick
    int notPick = 0 + pickHelper(wt, val, W, N, ind - 1, dp);
    // Pick krlia to val add kro.....and same index pr call krdo
    int pick = -1e9;
    if (wt[ind] <= W)
        pick = val[ind] + pickHelper(wt, val, W - wt[ind], N, ind, dp);

    // Return max of values
    return dp[ind][W] = max(notPick, pick);
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> wtt;
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < N; i++)
    {
        wtt.push_back(wt[i]);
        vall.push_back(val[i]);
    }
    // 2 Parameter ind and weigth from 0 to W toh 2D Vector
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return pickHelper(wtt, vall, W, N, N - 1, dp);
}

// Recursive Approach - Top Down...yha hum values N-1 se pick not pick krrhe and max dekhrhe h
int pickHelper(vector<int> &wt, vector<int> &val, int W, int N, int ind)
{
    if (ind == 0)
    {
        // Agar weight rkh skte ho to
        return (int)(W / wt[0]) * val[0];
    }

    // Not pick
    int notPick = 0 + pickHelper(wt, val, W, N, ind - 1);
    // Pick krlia to val add kro....and same index pr call krdo
    int pick = -1e9;
    if (wt[ind] <= W)
        pick = val[ind] + pickHelper(wt, val, W - wt[ind], N, ind);

    // Return max of values
    return max(notPick, pick);
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> wtt;
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < N; i++)
    {
        wtt.push_back(wt[i]);
        vall.push_back(val[i]);
    }
    return pickHelper(wtt, vall, W, N, N - 1);
}

int main()
{

    return 0;
}