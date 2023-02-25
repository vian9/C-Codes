// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int unboundedKnapsack(int total, int n, vector<int> &val, vector<int> &wt)
{
    int dp[total + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= total; i++)
        for (int j = 0; j < n; j++)
            if (wt[j] == i)
                dp[i] = max(dp[i], dp[i - val[j]] + wt[j]);

    return dp[total];
}

int countGoodStrings(int low, int high, int zero, int one)
{
    vector<int> coins;
    coins.push_back(0);
    coins.push_back(1);
    vector<int> val;
    val.push_back(zero);
    val.push_back(one);
    int total = 0;
    for (int i = low; i <= high; i++)
    {
        for (int j = low; j <= high; j++)
        {
            total += unboundedKnapsack(j, i, coins, val);
        }
    }
    return total;
}

int main()
{

    return 0;
}