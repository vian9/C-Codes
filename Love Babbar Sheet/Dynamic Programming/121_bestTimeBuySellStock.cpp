// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time Complexity  -  O(n)
// Approach -buyValue ko price k maximum dedia....ab harr prices m check kro agar price buyValue se kaam h to lelo
// aur ab currentProfit dekho wo purana profit se jada h to update krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxProfit(vector<int> &prices)
{
    // BuyValue lelo 1st ko
    int buyValue = prices[0];
    // Profit min 0 ho skta h neg nhi
    int profit = 0;
    // Ab hume jo current transaction h uske left mein sbse min ko buyValue rkhenge for max Profit
    for (int i = 1; i < prices.size(); i++)
    {
        // Profit nikalo and update kro
        int currProfit = prices[i] - buyValue;
        profit = max(profit, currProfit);
        // Min buyValue rkho
        buyValue = min(buyValue, prices[i]);
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    int buyValue = INT_MAX;
    int profit = 0;
    int currProfit = 0;
    int i = 0;
    while (i < prices.size())
    {
        buyValue = min(buyValue, prices[i]);
        currProfit = prices[i] - buyValue;
        if (currProfit > profit)
        {
            profit = currProfit;
        }
        i++;
    }
    return profit;
}

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
    }
    return 0;
}