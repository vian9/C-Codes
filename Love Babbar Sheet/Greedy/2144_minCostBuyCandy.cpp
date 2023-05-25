// Link : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
// Time Complexity : O(nlogn)
// Approach-> Sort kro and max 2 k sth usse kaam 1 lelo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minimumCost(vector<int> &cost)
{
    // saare candies buy krna h with min cost
    // means hum bada wla candies kharedo nd sasta wla mil jayega
    sort(cost.begin(), cost.end());
    int costs = 0;
    int i = cost.size() - 1;
    while (i >= 0)
    {
        costs += cost[i];
        if (i - 1 >= 0)
            costs += cost[i - 1];
        i = i - 3;
    }
    return costs;
}

int main()
{

    return 0;
}