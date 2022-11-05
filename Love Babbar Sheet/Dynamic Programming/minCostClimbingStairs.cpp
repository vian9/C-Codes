// Link : https://leetcode.com/problems/min-cost-climbing-stairs/
// Time Complexity : O(n) and O(1) Space
// Approach-> Phle recursive relation smjho aur likho....yhan 0 or 1 se start with 1 or 2 steps
// Phir memoisation direct lagao aur tabulation mein socho kya store kr skte h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Tabulation .... Time : O(n) and Space O(1)
int minCostClimbingStairs(vector<int> &cost)
{
    // Cost dene k baad u can either climb one step or 2 steps....
    // So dp[i] means min cost of path from i to n/n+1
    int n = cost.size();
    if (n < 1)
        return 0;

    // Last mein either last cost pr jayega or either uske parr
    int next = cost[n - 1];
    int next1 = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int curr = cost[i] + min(next, next1);
        next1 = next;
        next = curr;
    }

    // 0 se ya 1 se jisse min hoga whi rasta lenge
    return min(next, next1);
}

// Tabulation .... Time : O(n) and Space O(n)
int minCostClimbingStairs(vector<int> &cost)
{
    // Cost dene k baad u can either climb one step or 2 steps....
    // So dp[i] means min cost of path from i to n/n+1
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    if (n < 1)
        return 0;

    // Last mein either last cost pr jayega or either uske parr
    dp[n - 1] = cost[n - 1];
    dp[n] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
    }

    // 0 se ya 1 se jisse min hoga whi rasta lenge
    return min(dp[0], dp[1]);
}

// Memoisation...TLE...Time : O()
int minCost(vector<int> &cost, int i, vector<int> dp)
{
    // Cost dene k baad u can either climb one step or 2 steps....so we have
    //  to do recursive calls to both 1 and 2 steps
    int n = cost.size();
    if (i >= n)
        return 0;

    int minCost1;
    int minCost2;
    if (dp[i] != -1)
    {
        return dp[i];
    }
    if (i == 0)
    {
        minCost1 = cost[i] + min(minCost(cost, i + 1, dp), minCost(cost, i + 2, dp));
        minCost2 = cost[i + 1] + min(minCost(cost, i + 2, dp), minCost(cost, i + 3, dp));
    }
    else
    {
        minCost1 = cost[i] + minCost(cost, i + 1, dp);
        minCost2 = cost[i] + minCost(cost, i + 2, dp);
    }

    return dp[i] = min(minCost1, minCost2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n, -1);
    return minCost(cost, 0, dp);
}

// Recursive - TLE
int minCost(vector<int> &cost, int i)
{
    // Cost dene k baad u can either climb one step or 2 steps....so we have
    //  to do recursive calls to both 1 and 2 steps
    int n = cost.size();
    if (i >= n)
        return 0;

    int minCost1;
    int minCost2;
    if (i == 0)
    {
        minCost1 = min(cost[i] + minCost(cost, i + 1), cost[i] + minCost(cost, i + 2));
        // AGar index 1 liye toh 1+1 = 2 aur 1+2 = 3 consider krenge
        minCost2 = min(cost[i + 1] + minCost(cost, i + 2), cost[i + 1] + minCost(cost, i + 3));
    }
    else
    {
        minCost1 = cost[i] + minCost(cost, i + 1);
        minCost2 = cost[i] + minCost(cost, i + 2);
    }

    return min(minCost1, minCost2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    return minCost(cost, 0);
}

int main()
{

    return 0;
}