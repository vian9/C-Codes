// Link : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int root, map<pair<int, int>, int> &newRoads, vector<bool> &visited)
{
    if (visited[root] == true)
    {
        return;
    }

    // Ab root se koi aur road pr traverse krte rho
    visited[root] = true;
    for (int i = 1; i <= visited.size(); i++)
    {
        if (i != root)
        {
            int mini = min(root, i);
            int maxi = max(root, i);
            if (!visited[i] && newRoads.count({mini, maxi}) > 0)
            {
                dfs(i, newRoads, visited);
            }
        }
    }
}

int minScore(int n, vector<vector<int>> &roads)
{
    // Adjacency vector is given
    // ai bi distance h
    map<pair<int, int>, int> newRoads;
    for (int i = 0; i < roads.size(); i++)
    {
        pair<int, int> pt = {min(roads[i][0], roads[i][1]), max(roads[i][0], roads[i][1])};
        newRoads[pt] = roads[i][2];
    }
    vector<bool> visited(n + 1, false);
    dfs(1, newRoads, visited);
    int mini = 0;
    for (auto i : newRoads)
    {
        if (visited[i.first.first] && visited[i.first.second])
        {
            mini = min(mini, i.second);
        }
    }
    return mini;
}

int main()
{

    return 0;
}