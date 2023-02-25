// Link : https://leetcode.com/problems/gas-station/
// Time Complexity : O(n)
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    // if total gas < total cost so no point exists as pura nhi travel kr skte

    int totalGas = 0;
    int totalCost = 0;
    int currentGas = 0;
    int startIndex = 0;
    int n = gas.size();
    for (int i = 0; i < gas.size(); i++)
    {
        totalCost += cost[i];
        totalGas += gas[i];
        currentGas += (gas[i] - cost[i]);
        // Ab kahin se bhi current gas negative hua toh startIndex reset krdo next se
        if (currentGas < 0)
        {
            startIndex = i + 1;
            currentGas = 0;
        }
    }
    if (totalGas < totalCost)
        return -1;
    else
        return startIndex;
}

int main()
{

    return 0;
}