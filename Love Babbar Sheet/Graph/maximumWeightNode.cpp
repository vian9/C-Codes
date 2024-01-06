// Link : https://practice.geeksforgeeks.org/problems/b64485d3994958cca8748991bb58668204b3e4c0/1
// https://leetcode.com/discuss/interview-question/2032859/juspay-oa-maximum-weight-node
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxWeight(vector<int> &arr)
{
    int maxWt = INT_MIN;
    int result = -1;
    int n = arr.size();
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
    {
        int source = i;
        int dest = arr[i];
        if (dest != -1)
        {
            weight[dest] += source;
            if (maxWt <= weight[dest])
            {
                maxWt = max(maxWt, weight[dest]);
                result = dest;
            }
        }
    }
    if (maxWt != INT_MIN)
    {
        return result;
    }
    return -1;
}

int maxWeight(vector<int> &arr)
{
    int maxwt = INT_MIN;
    int result = -1;
    vector<int> weight(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        int source = i;
        int dest = arr[i];
        if (dest != -1)
        {
            weight[dest] += source;
            if (maxwt <= weight[dest])
            {
                maxwt = max(maxwt, weight[dest]);
                result = dest;
            }
        }
    }
    if (maxwt != INT_MIN)
        return result;
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> adj[i];
    }
    cout << maxWeight(adj);
    return 0;
}