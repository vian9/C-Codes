#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int buyValue = INT_MAX;
    int sellValue = 0;
    int profit = 0;
    int i = 0;
    while (i < prices.size())
    {
        buyValue = min(buyValue, prices[i]);
        sellValue = max(sellValue, prices[i]);
        i++;
    }
    profit = sellValue - buyValue;
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

    return 0;
}