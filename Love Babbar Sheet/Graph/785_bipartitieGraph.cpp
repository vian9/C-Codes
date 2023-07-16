// Link : https://leetcode.com/problems/is-graph-bipartite/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool bfs(int m, vector<vector<int>> &graph, vector<int> &color, int root)
{
    queue<pair<int, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int curr = q.front().first;
        int col = q.front().second;
        color[curr] = col;
        q.pop();
        for (auto nodes : graph[curr])
        {
            if (color[nodes] == -1)
            {
                q.push({nodes, !col});
            }
            else if (color[nodes] == col)
                return false;
        }
    }
    return true;
}

bool dfs(int m, vector<vector<int>> &graph, vector<int> &color, int root, int col)
{
    color[root] = col;
    int n = graph[root].size();
    for (auto nodes : graph[root])
    {
        if (color[nodes] == -1)
        {
            if (dfs(m, graph, color, nodes, !col) == false)
                return false;
        }
        else if (color[nodes] == col)
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int m = graph.size();
    vector<int> color(m, -1);
    for (int i = 0; i < m; i++)
    {
        if (color[i] == -1)
        {
            // if (dfs(m, graph, color, i, 0) == false)
            //     return false;
            if (bfs(m, graph, color, i) == false)
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}