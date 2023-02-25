// Link : https://leetcode.com/problems/maximum-ice-cream-bars/
// Time Complexity : O(n)
// Approach-> Sort krdia and ab jb costs jbtk chota h coins lete gya

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// baht jada constraints h to greedy lgarha
int maxIceCream(vector<int> &costs, int coins)
{
    // Greedy h toh sort kro phle
    sort(costs.begin(), costs.end());
    int totalCoin = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        if (costs[i] <= coins)
        {
            totalCoin++;
            coins -= costs[i];
        }
        else
        {
            break;
        }
    }
    return totalCoin;
}

int main()
{

    return 0;
}