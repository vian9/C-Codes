// Link : https://leetcode.com/problems/coin-change-ii/
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Same as Unbounded Knapsack ....pick jo krrhe ho same ind pr call krte jao and unpick pr ind-1 ho baaki bs whi dp lgao and uske steps

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up....first coin se call krke n-1 tk jayenge
// dp[ind][amount] tells us ki index ind tk amount kitna ways se ban skta h
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    // 2 parameter h amount and ind toh 2D Vector mein save krenge....amount 0 tk jayega
    // Isme prev and curr row use horha h to 2 vector se kaam chal jayega....size as total no of col lete h row is getting repeated
    vector<int> prev(amount + 1, -1);
    // Save the base case of memoisation
    for (int i = 0; i <= amount; i++)
    {
        // We have to return ways so 1 or 0;
        prev[i] = (i % coins[0] == 0);
    }

    // 2 parameters h toh 2 nested loop chlega and usme ind will start from 1 as 0 save krdia h
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(amount + 1, -1);
        for (int amt = 0; amt <= amount; amt++)
        {
            // unPick the coin...ind-1 ko call
            int unPick = prev[amt];
            // Pick the coin....same ind ko call as infinite times le skte
            int pick = 0;
            if (coins[ind] <= amt)
                pick = curr[amt - coins[ind]];

            // Dono ka aaya hua ways ko add krke return
            curr[amt] = unPick + pick;
        }
        prev = curr;
    }
    // Jo memoisation mein call hua tha
    return prev[amount];
}

// Tabulation Approach - Bottom Up....first coin se call krke n-1 tk jayenge
// dp[ind][amount] tells us ki index ind tk amount kitna ways se ban skta h
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    // 2 parameter h amount and ind toh 2D Vector mein save krenge....amount 0 tk jayega
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // Save the base case of memoisation
    for (int i = 0; i <= amount; i++)
    {
        // We have to return ways so 1 or 0;
        dp[0][i] = (i % coins[0] == 0);
    }

    // 2 parameters h toh 2 nested loop chlega and usme ind will start from 1 as 0 save krdia h
    for (int ind = 1; ind < n; ind++)
    {
        for (int amt = 0; amt <= amount; amt++)
        {
            // unPick the coin...ind-1 ko call
            int unPick = dp[ind - 1][amt];
            // Pick the coin....same ind ko call as infinite times le skte
            int pick = 0;
            if (coins[ind] <= amt)
                pick = dp[ind][amt - coins[ind]];

            // Dono ka aaya hua ways ko add krke return
            dp[ind][amt] = unPick + pick;
        }
    }
    // Jo memoisation mein call hua tha
    return dp[n - 1][amount];
}

// Memoisation Approach - Top Down....last coin se call krke 0 tk jayenge
// dp[ind][amount] tells us ki index ind tk amount kitna ways se ban skta h
int coinSelector(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        // We have to return ways so 1 or 0;
        return dp[ind][amount] = (amount % coins[ind] == 0);
    }

    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    // unPick the coin...ind-1 ko call
    int unPick = coinSelector(coins, amount, ind - 1, dp);
    // Pick the coin....same ind ko call as infinite times le skte
    int pick = 0;
    if (coins[ind] <= amount)
        pick = coinSelector(coins, amount - coins[ind], ind, dp);

    // Dono ka aaya hua ways ko add krke return
    return dp[ind][amount] = unPick + pick;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    // 2 parameter h amount and ind toh 2D Vector mein save krenge....amount 0 tk jayega
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return coinSelector(coins, amount, n - 1, dp);
}

// Recursive Approach - Top Down....last coin se call krke 0 tk jayenge
int coinSelector(vector<int> &coins, int amount, int ind)
{
    if (ind == 0)
    {
        // We have to return ways so 1 or 0;
        return (amount % coins[ind] == 0);
    }

    // unPick the coin...ind-1 ko call
    int unPick = coinSelector(coins, amount, ind - 1);
    // Pick the coin....same ind ko call as infinite times le skte
    int pick = 0;
    if (coins[ind] <= amount)
        pick = coinSelector(coins, amount - coins[ind], ind);

    // Dono ka aaya hua ways ko add krke return
    return unPick + pick;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    return coinSelector(coins, amount, n - 1);
}

int main()
{

    return 0;
}