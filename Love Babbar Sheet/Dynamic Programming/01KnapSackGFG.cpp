// Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Isme hume W rkhna h and such that max Profit....greedy nhi lga skte kuuki uniform nhi hai distribution...ek jada profit wla chiz utha lia
// wo jada weight lelia to ab baaki nhi kr skte but 2 ko milakr jada usse profit ho skta tha to saara combination dekhna hoga

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up...yha hum values 0 se pick not pick krrhe and max dekhrhe h
// dp[ind][W] tells us max profit possible from ind 0 to ind with Weight max W
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> wtt;
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < n; i++)
    {
        wtt.push_back(wt[i]);
        vall.push_back(val[i]);
    }
    // 2 Parameter ind and weigth from 0 to W toh 2D Vector...yha default value 0 krdia for 1st case run kre to dikkat na aaye
    // Prev row k bs use horha
    vector<int> prev(W + 1, 0);

    // Memoisation ka base case save krenge
    // Agar ind == 0 hai to Wtt[0] se wo val le skta h to W tk ka liye vall[ind] aayega otherwise 0 for ind = 0
    // Jo wtt[0] hai whi vall[0] dega and wha se lekr W tk
    for (int i = wtt[0]; i <= W; i++)
    {
        prev[i] = vall[0];
    }

    // 2 nested loop chlega as 2 Parameters and from 1 it will start as 0 save krdia h
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(W + 1, 0);
        // Ye weight tells ki usse ind tk ye weight aa skte h with max value
        for (int weight = 0; weight <= W; weight++)
        {
            // Not pick
            int notPick = 0 + prev[weight];
            // Pick krlia to vall add kro
            int pick = -1e9;
            if (wtt[ind] <= weight)
                pick = vall[ind] + prev[weight - wt[ind]];

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
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> wtt;
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < n; i++)
    {
        wtt.push_back(wt[i]);
        vall.push_back(val[i]);
    }
    // 2 Parameter ind and weigth from 0 to W toh 2D Vector...yha default value 0 krdia for 1st case run kre to dikkat na aaye
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Memoisation ka base case save krenge
    // Agar ind == 0 hai to Wtt[0] se wo val le skta h to W tk ka liye vall[ind] aayega otherwise 0 for ind = 0
    // Jo wtt[0] hai whi vall[0] dega and wha se lekr W tk
    for (int i = wtt[0]; i <= W; i++)
    {
        dp[0][i] = vall[0];
    }

    // 2 nested loop chlega as 2 Parameters and from 1 it will start as 0 save krdia h
    for (int ind = 1; ind < n; ind++)
    {
        // Ye weight tells ki usse ind tk ye weight aa skte h with max value
        for (int weight = 0; weight <= W; weight++)
        {
            // Not pick
            int notPick = 0 + dp[ind - 1][weight];
            // Pick krlia to vall add kro
            int pick = -1e9;
            if (wtt[ind] <= weight)
                pick = vall[ind] + dp[ind - 1][weight - wt[ind]];

            // Return max of values
            dp[ind][weight] = max(notPick, pick);
        }
    }

    // Jo memoisation mein call hua usse return krenge
    return dp[n - 1][W];
}

// Memoisation Approach - Top Down...yha hum values n-1 se pick not pick krrhe and max dekhrhe h
// dp[ind][W] tells us max profit possible from ind 0 to ind with Weight max W
int pickHelper(vector<int> &wt, vector<int> &val, int W, int n, int ind, vector<vector<int>> &dp)
{
    // Agar weight 0 ho gya to return without picking anything now
    // Isse case se farq nhi pdta as 0 hogya to pick nhi hoga ind = 0 tk
    // if (W == 0)
    // {
    //     return dp[ind][W] = 0;
    // }
    if (ind == 0)
    {
        // Agar weight rkh skte ho to
        if (wt[ind] <= W)
            return dp[ind][W] = val[ind];
        else
            return dp[ind][W] = 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];
    // Not pick
    int notPick = 0 + pickHelper(wt, val, W, n, ind - 1, dp);
    // Pick krlia to val add kro
    int pick = -1e9;
    if (wt[ind] <= W)
        pick = val[ind] + pickHelper(wt, val, W - wt[ind], n, ind - 1, dp);

    // Return max of values
    return dp[ind][W] = max(notPick, pick);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> wtt;
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < n; i++)
    {
        wtt.push_back(wt[i]);
        vall.push_back(val[i]);
    }
    // 2 Parameter ind and weigth from 0 to W toh 2D Vector
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return pickHelper(wtt, vall, W, n, n - 1, dp);
}

// Recursive Approach - Top Down...yha hum values n-1 se pick not pick krrhe and max dekhrhe h
int pickHelper(vector<int> &wt, vector<int> &val, int W, int n, int ind)
{
    // Agar weight 0 ho gya to return without picking anything now
    // Isse case se farq nhi pdta as 0 hogya to pick nhi hoga ind = 0 tk
    // if (W == 0)
    // {
    //     return 0;
    // }
    if (ind == 0)
    {
        // Agar weight rkh skte ho to
        if (wt[ind] <= W)
            return val[ind];
        else
            return 0;
    }

    // Not pick
    int notPick = 0 + pickHelper(wt, val, W, n, ind - 1);
    // Pick krlia to val add kro
    int pick = -1e9;
    if (wt[ind] <= W)
        pick = val[ind] + pickHelper(wt, val, W - wt[ind], n, ind - 1);

    // Return max of values
    return max(notPick, pick);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> wtt;
    vector<int> vall;
    // For convenience....easy to pass
    for (int i = 0; i < n; i++)
    {
        wtt.push_back(wt[i]);
        vall.push_back(val[i]);
    }
    return pickHelper(wtt, vall, W, n, n - 1);
}

int main()
{

    return 0;
}