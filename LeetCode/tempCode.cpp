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