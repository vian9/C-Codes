// Link : https://leetcode.com/problems/richest-customer-wealth/
// Time Complexity : O(n^2)......to access items itna lagega hi bas access k baad calcultate fast rhe
// Approach-> Harr iterations mein vector pr gye and usme saare element ko add krte jao and check max se jada h to update

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maximumWealth(vector<vector<int>> &accounts)
{
    int maxWealth = 0;
    // M-1 in Less than O(n^2) but nearby but reduces time than 2 nested loops
    for (int i = 0; i < accounts.size(); i++)
    {
        int wealth = 0;
        wealth = accumulate(accounts[i].begin(), accounts[i].begin() + accounts[i].size(), 0);

        maxWealth = max(maxWealth, wealth);
    }

    return maxWealth;

    // M -2 in O(n^2) to move in a matrix
    for (int i = 0; i < accounts.size(); i++)
    {
        int wealth = 0;
        for (int j = 0; j < accounts[i].size(); j++)
        {
            wealth += accounts[i][j];
        }
        maxWealth = max(maxWealth, wealth);
    }
}

int main()
{

    return 0;
}