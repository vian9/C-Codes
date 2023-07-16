// Link : https://leetcode.com/problems/coin-change/
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Dekho isme greedy nhi lga skte as diff between coins uniform nhi h to wo max Coin se divide krke ki kitna coins lgega and usse krle toh
// usse min coin harr jagah nhi dega
// So harr combinations dekhna h to DP lgana hoga toh uske liye pick and unpick unlimited times kr skte h
// Base case yhi hoga jb Last coin amount ko divide kr ske totally and amount becomes zero

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up.....hum 0 se n-1 jayenge
// dp[ind][amount] means ki ind tk amount kitna min coin se bnrha
int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    int n = coins.size();
    // 2 parameter horha h yeh amount and ind toh 2D Vector....amount jbtk 0 nhi aayega....default value 0 krdo ab kuuki prev value use hoga
    // ind-1 and ind chahiye toh prev and curr se
    vector<int> prev(amount + 1, 0);
    // Hum base case of memoisation save krenge
    // Ab ind == 0 pr amount agar divisible h tb possible h so harr amount k liye dekhenge 0 to amount
    for (int i = 0; i <= amount; i++)
    {
        // Agar amount ind=0 coins se divisible h tbhi wo amount bnega
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }

    // 2 nested loops for ind for coin and amount....will start ind from 1 as for 0 save krlia
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(amount + 1, 0);
        for (int amt = 0; amt <= amount; amt++)
        {
            // Unpick krdia toh ab nhi lerhe to ind-1 pr jao
            int notPick = 0 + prev[amt];
            // Pick....min lena h to max
            int pick = 1e9;
            // Ab agar lerhe isse to phir se whi ind call krenge
            if (coins[ind] <= amt)
                pick = 1 + curr[amt - coins[ind]];

            // min return krdo
            curr[amt] = min(pick, notPick);
        }
        prev = curr;
    }

    // Jisko memoisation mein call kia usse return krdo
    // Agar amount nhu bnrha to yeh aayega
    if (prev[amount] >= 1e9)
        return -1;
    return prev[amount];
}

// Tabulation Approach - Bottom Up.....hum 0 se n-1 jayenge
// dp[ind][amount] means ki ind tk amount kitna min coin se bnrha
int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    int n = coins.size();
    // 2 parameter horha h yeh amount and ind toh 2D Vector....amount jbtk 0 nhi aayega....default value 0 krdo ab kuuki prev value use hoga
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    // Hum base case of memoisation save krenge
    // Ab ind == 0 pr amount agar divisible h tb possible h so harr amount k liye dekhenge 0 to amount
    for (int i = 0; i <= amount; i++)
    {
        // Agar amount ind=0 coins se divisible h tbhi wo amount bnega
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }

    // 2 nested loops for ind for coin and amount....will start ind from 1 as for 0 save krlia
    for (int ind = 1; ind < n; ind++)
    {
        for (int amt = 0; amt <= amount; amt++)
        {
            // Unpick krdia toh ab nhi lerhe to ind-1 pr jao
            int notPick = 0 + dp[ind - 1][amt];
            // Pick....min lena h to max
            int pick = 1e9;
            // Ab agar lerhe isse to phir se whi ind call krenge
            if (coins[ind] <= amt)
                pick = 1 + dp[ind][amt - coins[ind]];

            // min return krdo
            dp[ind][amt] = min(pick, notPick);
        }
    }

    // Jisko memoisation mein call kia usse return krdo
    // Agar amount nhu bnrha to yeh aayega
    if (dp[n - 1][amount] >= 1e9)
        return -1;
    return dp[n - 1][amount];
}

// Memoisation Approach - Top Down .....hum n-1 se call krrhe and jaarhe 0 tk
// dp[ind][amount] means ki ind tk amount kitna min coin se bnrha
int coinPicker(vector<int> &coins, int amount, int ind, int n, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        // Agar amount ind=0 coins se divisible h tbhi wo amount bnega
        if (amount % coins[ind] == 0)
            return dp[ind][amount] = amount / coins[ind];
        else
            return dp[ind][amount] = 1e9;
    }

    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    // Unpick krdia toh ab nhi lerhe to ind-1 pr jao
    int notPick = 0 + coinPicker(coins, amount, ind - 1, n, dp);
    // Pick....min lena h to max
    int pick = 1e9;
    // Ab agar lerhe isse to phir se whi ind call krenge
    if (coins[ind] <= amount)
        pick = 1 + coinPicker(coins, amount - coins[ind], ind, n, dp);

    // min return krdo
    return dp[ind][amount] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    int n = coins.size();
    // 2 parameter horha h yeh amount and ind toh 2D Vector....amount jbtk 0 nhi aayega
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int change = coinPicker(coins, amount, n - 1, n, dp);
    // Agar amount nhu bnrha to yeh aayega
    if (change >= 1e9)
        return -1;
    return change;
}

// Recursive Approach - Top Down .....hum n-1 se call krrhe and jaarhe 0 tk
int coinPicker(vector<int> &coins, int amount, int ind, int n)
{
    if (ind == 0)
    {
        // Agar amount ind=0 coins se divisible h tbhi wo amount bnega
        if (amount % coins[ind] == 0)
            return amount / coins[ind];
        else
            return 1e9;
    }

    // Unpick krdia toh ab nhi lerhe to ind-1 pr jao
    int notPick = 0 + coinPicker(coins, amount, ind - 1, n);
    // Pick....min lena h to max
    int pick = 1e9;
    // Ab agar lerhe isse to phir se whi ind call krenge
    if (coins[ind] <= amount)
        pick = 1 + coinPicker(coins, amount - coins[ind], ind, n);

    // min return krdo
    return min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    int n = coins.size();
    int change = coinPicker(coins, amount, n - 1, n);
    // Agar amount nhu bnrha to yeh aayega
    if (change >= 1e9)
        return -1;
    return change;
}

int main()
{

    return 0;
}