// Link : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countTime(unordered_map<int, vector<int>> path, int n, vector<bool> &hasApple, int i, vector<bool> &visited)
{
    vector<int> nodes;
    if (path.count(i) > 0)
    {
        for (int j = 0; j < path[i].size(); j++)
        {
            nodes.push_back(path[i][j]);
        }
    }
    // leaf node with no apple
    if (!hasApple[i])
    {
        if (nodes.size() == 0)
        {
            return 0;
        }
    }
    int nodesVal = 0;

    for (int j = 0; j < nodes.size(); j++)
    {
        nodesVal += countTime(path, n, hasApple, nodes[j], visited);
    }

    if (hasApple[i] || nodesVal > 0)
    {
        if (visited[i])
        {
            return nodesVal;
        }
        else
        {
            visited[i] = true;
            return 2 + nodesVal;
        }
    }
    return 0;
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    // ye array se path ko O(1) mein lane k liye map use kr lenge
    unordered_map<int, vector<int>> path;
    // now hasapple to hmesa O(1) mein access hoga
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        path[a].push_back(b);
        // if (a != 0 && b != 0)
        //     path[b].push_back(a);
        // else {
        //     vector<int> vec;
        //     vec.push_back(0);
        //     path[a] = vec;
        // }
    }
    vector<bool> visited(n, false);
    visited[0] = true;
    int val = 0;
    val = countTime(path, n, hasApple, 0, visited);
    return val;
}
int main()
{
    vector<vector<int>> edges;
    vector<int> a;
    a.push_back(0);
    a.push_back(0);
    vector<bool> t;
    t.push_back(true);
    edges.push_back(a);
    cout << minTime(1, edges, t);
    return 0;
}