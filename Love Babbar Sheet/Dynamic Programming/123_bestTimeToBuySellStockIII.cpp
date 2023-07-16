// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
// Time Complexity : O(n) SC:O(2*3)
// Approach-> Dekho hum koi bhi buy and sale kr skte for max profit....to buy ke time hum usse -price se profit lerhe and sell k time +price se
// Now ab buy krna na krna dono hmesa choice h waise hi sell krna and nhi krna bhi to dono k liye run kroge
// Ab isme ek aur parameter aagya ki 2 at most transaction jaise hi hoga return 0....ab transaction complete buy pr nhi hoga sale kr hoga...as buy pr kroge to wo sale nhi to profit kha
// glti bs yhi h ki transaction complete kha pr krna h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation- Bottom Up Approach .....hum yha memoisation ke opposite start krenge and buy mein pick not pick and similar on sell and return
// dp[ind][buy] means ki ind tk hum max profit kitna kama skte h agar ind wla ko buy krdia h ya sell krdia h
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // 3 Parameters h ek ind aur ek buy ya sell and trans
    // At a time curr and prev use horha h
    vector<vector<int>> prev(2, vector<int>(3, 0));
    // Memoisation ka hum base case save kr denge...ind == n pr sb 0 hoga and similarly trans == 0 pr sb 0...waise no need to save sb already 0 h

    // Start opposite se hoga.....hum n-1 se 0 tk jayenge
    for (int ind = n - 1; ind >= 0; ind--)
    {
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int buy = 0; buy < 2; buy++)
        {
            // Trans 2 se 0 horha to yha opposite hoga 1 se 2...0 is saved
            for (int trans = 1; trans <= 2; trans++)
            {
                // Buy the stock if buy = 1
                if (buy == 1)
                {
                    // You can either buy or skip it
                    int buyy = -prices[ind] + prev[0][trans];
                    int notBuy = prev[1][trans];
                    curr[buy][trans] = max(buyy, notBuy);
                }
                else
                {
                    // You can either sell or skip it....sell pr ek transaction kaam hoga not on buy pr as wrna hum sale nhi kr payenge base case hit ho jayega
                    int sell = prices[ind] + +prev[1][trans - 1];
                    int notSell = prev[0][trans];
                    curr[buy][trans] = max(sell, notSell);
                }
            }
        }
        prev = curr;
    }

    // Jo memoisation mein call kiye h usse return krdenge
    return prev[1][2];
}

// Tabulation- Bottom Up Approach .....hum yha memoisation ke opposite start krenge and buy mein pick not pick and similar on sell and return
// dp[ind][buy] means ki ind tk hum max profit kitna kama skte h agar ind wla ko buy krdia h ya sell krdia h
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // 3 Parameters h ek ind aur ek buy ya sell and ek trans...jo 2 to 0 jayega
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Memoisation ka hum base case save kr denge...ind == n pr sb 0 hoga and similarly trans == 0 pr sb 0...waise no need to save sb already 0 h
    // for (int ind = 0; ind <= n; ind++)
    // {
    //     for (int buy = 0; buy < 2; buy++)
    //     {
    //         dp[ind][buy][0] = 0;
    //     }
    // }

    // for (int buy = 0; buy < 2; buy++)
    // {
    //     for (int trans = 0; trans <= 2; trans++)
    //     {
    //         dp[n][buy][trans] = 0;
    //     }
    // }

    // Start opposite se hoga.....hum n-1 se 0 tk jayenge
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            // Trans 2 se 0 horha to yha opposite hoga 1 se 2...0 is saved
            for (int trans = 1; trans <= 2; trans++)
            {
                // Buy the stock if buy = 1
                if (buy == 1)
                {
                    // You can either buy or skip it
                    int buyy = -prices[ind] + dp[ind + 1][0][trans];
                    int notBuy = dp[ind + 1][1][trans];
                    dp[ind][buy][trans] = max(buyy, notBuy);
                }
                else
                {
                    // You can either sell or skip it....sell pr ek transaction kaam hoga not on buy pr as wrna hum sale nhi kr payenge base case hit ho jayega
                    int sell = prices[ind] + +dp[ind + 1][1][trans - 1];
                    int notSell = dp[ind + 1][0][trans];
                    dp[ind][buy][trans] = max(sell, notSell);
                }
            }
        }
    }

    // Jo memoisation mein call kiye h usse return krdenge
    return dp[0][1][2];
}

// Memoisation- Top Down Approach .....hum 0 se start krenge and buy mein pick not pick and similar on sell and return..jb bhi sale kro to ek transaction kaam kro
// dp[ind][buy] means ki ind tk hum max profit kitna kama skte h agar ind wla ko buy krdia h ya sell krdia h
int stockSeller(vector<int> &prices, int n, int ind, int buy, vector<vector<vector<int>>> &dp, int trans)
{
    if (ind == n || trans == 0)
    {
        return 0;
    }

    if (dp[ind][buy][trans] != -1)
        return dp[ind][buy][trans];

    // Buy the stock if buy = 1
    if (buy)
    {
        // You can either buy or skip it
        int buyy = -prices[ind] + stockSeller(prices, n, ind + 1, 0, dp, trans);
        int notBuy = stockSeller(prices, n, ind + 1, 1, dp, trans);
        return dp[ind][buy][trans] = max(buyy, notBuy);
    }
    // You can either sell or skip it....sell pr ek transaction kaam hoga not on buy pr as wrna hum sale nhi kr payenge base case hit ho jayega
    int sell = prices[ind] + stockSeller(prices, n, ind + 1, 1, dp, trans - 1);
    int notSell = stockSeller(prices, n, ind + 1, 0, dp, trans);
    return dp[ind][buy][trans] = max(sell, notSell);
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // 3 Parameters h ek ind aur ek buy ya sell and ek trans...jo 2 to 0 jayega
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // Start 0 se hi hoga as hum buy krenge tb sell krenge
    return stockSeller(prices, n, 0, 1, dp, 2);
}

// Recursion - Top Down Approach .....hum 0 se start krenge and buy mein pick not pick and similar on sell and return...jb bhi sale kro to ek transaction kaam kro
int stockSeller(vector<int> &prices, int n, int ind, int buy, int trans)
{
    if (ind == n || trans == 0)
    {
        return 0;
    }

    // Buy the stock if buy = 1
    if (buy)
    {
        // You can either buy or skip it
        int buyy = -prices[ind] + stockSeller(prices, n, ind + 1, 0, trans);
        int notBuy = stockSeller(prices, n, ind + 1, 1, trans);
        return max(buyy, notBuy);
    }
    // You can either sell or skip it....sell pr ek transaction kaam hoga not on buy pr as wrna hum sale nhi kr payenge base case hit ho jayega
    int sell = prices[ind] + stockSeller(prices, n, ind + 1, 1, trans - 1);
    int notSell = stockSeller(prices, n, ind + 1, 0, trans);
    return max(sell, notSell);
}

int maxProfit(vector<int> &prices)
{
    // Start 0 se hi hoga as hum buy krenge tb sell krenge
    return stockSeller(prices, prices.size(), 0, 1, 2);
}

int main()
{

    return 0;
}