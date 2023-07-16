// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Time Complexity : O(n) SC:O(n)
// Approach-> Dekho hum koi bhi buy and sale kr skte for max profit....to buy ke time hum usse -price se profit lerhe and sell k time +price se
// Now ab buy krna na krna dono hmesa choice h waise hi sell krna and nhi krna bhi to dono k liye run kroge

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation- Bottom Up Approach .....hum yha memoisation ke opposite start krenge and buy mein pick not pick and similar on sell and return
// dp[ind][buy] means ki ind tk hum max profit kitna kama skte h agar ind wla ko buy krdia h ya sell krdia h
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // 2 Parameters h ek ind aur ek buy ya sell
    // At a time curr and prev use horha h
    vector<int> prev(2, 0);

    // Memoisation ka hum base case save kr denge
    prev[0] = prev[1] = 0;

    // Start opposite se hoga.....hum n-1 se 0 tk jayenge
    for (int ind = n - 1; ind >= 0; ind--)
    {
        vector<int> curr(2, 0);
        for (int buy = 0; buy < 2; buy++)
        {
            // Buy the stock if buy = 1
            if (buy == 1)
            {
                // You can either buy or skip it
                int buyy = -prices[ind] + prev[0];
                int notBuy = prev[1];
                curr[buy] = max(buyy, notBuy);
            }
            else
            {
                // You can either sell or skip it
                int sell = prices[ind] + prev[1];
                int notSell = prev[0];
                curr[buy] = max(sell, notSell);
            }
        }
        prev = curr;
    }

    // Jo memoisation mein call kiye h usse return krdenge
    return prev[1];
}

// Tabulation- Bottom Up Approach .....hum yha memoisation ke opposite start krenge and buy mein pick not pick and similar on sell and return
// dp[ind][buy] means ki ind tk hum max profit kitna kama skte h agar ind wla ko buy krdia h ya sell krdia h
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // 2 Parameters h ek ind aur ek buy ya sell
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // Memoisation ka hum base case save kr denge

    dp[n][0] = dp[n][1] = 0;

    // Start opposite se hoga.....hum n-1 se 0 tk jayenge
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            // Buy the stock if buy = 1
            if (buy == 1)
            {
                // You can either buy or skip it
                int buyy = -prices[ind] + dp[ind + 1][0];
                int notBuy = dp[ind + 1][1];
                dp[ind][buy] = max(buyy, notBuy);
            }
            else
            {
                // You can either sell or skip it
                int sell = prices[ind] + dp[ind + 1][1];
                int notSell = dp[ind + 1][0];
                dp[ind][buy] = max(sell, notSell);
            }
        }
    }

    // Jo memoisation mein call kiye h usse return krdenge
    return dp[0][1];
}

// Memoisation- Top Down Approach .....hum 0 se start krenge and buy mein pick not pick and similar on sell and return
// dp[ind][buy] means ki ind tk hum max profit kitna kama skte h agar ind wla ko buy krdia h ya sell krdia h
int stockSeller(vector<int> &prices, int n, int ind, int buy, vector<vector<int>> &dp)
{
    if (ind == n)
    {
        return 0;
    }

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    // Buy the stock if buy = 1
    if (buy)
    {
        // You can either buy or skip it
        int buyy = -prices[ind] + stockSeller(prices, n, ind + 1, 0, dp);
        int notBuy = stockSeller(prices, n, ind + 1, 1, dp);
        return dp[ind][buy] = max(buyy, notBuy);
    }
    // You can either sell or skip it
    int sell = prices[ind] + stockSeller(prices, n, ind + 1, 1, dp);
    int notSell = stockSeller(prices, n, ind + 1, 0, dp);
    return dp[ind][buy] = max(sell, notSell);
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // 2 Parameters h ek ind aur ek buy ya sell
    vector<vector<int>> dp(n, vector<int>(2, -1));
    // Start 0 se hi hoga as hum buy krenge tb sell krenge
    return stockSeller(prices, n, 0, 1, dp);
}

// Recursion - Top Down Approach .....hum 0 se start krenge and buy mein pick not pick and similar on sell and return
int stockSeller(vector<int> &prices, int n, int ind, int buy)
{
    if (ind == n)
    {
        return 0;
    }

    // Buy the stock if buy = 1
    if (buy)
    {
        // You can either buy or skip it
        int buyy = -prices[ind] + stockSeller(prices, n, ind + 1, 0);
        int notBuy = stockSeller(prices, n, ind + 1, 1);
        return max(buyy, notBuy);
    }
    // You can either sell or skip it
    int sell = prices[ind] + stockSeller(prices, n, ind + 1, 1);
    int notSell = stockSeller(prices, n, ind + 1, 0);
    return max(sell, notSell);
}

int maxProfit(vector<int> &prices)
{
    // Start 0 se hi hoga as hum buy krenge tb sell krenge
    return stockSeller(prices, prices.size(), 0, 1);
}

int main()
{

    return 0;
}