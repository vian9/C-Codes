// Link : https://leetcode.com/problems/find-eventual-safe-states/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// BFS
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int start = i;
        for (auto node : graph[i])
        {
            adj[node].push_back(start);
        }
    }
    vector<int> inde(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto node : adj[i])
        {
            inde[node]++;
        }
        cout << endl;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inde[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto node : adj[front])
        {
            inde[node]--;
            if (inde[node] == 0)
                q.push(node);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// DFS se path save krke
bool dfs(int V, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path, vector<int> &check, int root)
{
    vis[root] = 1;
    path[root] = 1;

    for (auto nodes : adj[root])
    {
        if (!vis[nodes])
        {
            if (dfs(V, adj, vis, path, check, nodes))
            {
                check[nodes] = 1;
                return true;
            }
        }
        else if (path[nodes] == 1)
        {
            check[nodes] = 1;
            return true;
        }
    }
    path[root] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> path(n, 0);
    vector<int> check(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (dfs(n, graph, vis, path, check, i))
            check[i] = 1;
        ;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (check[i] != 1)
            ans.push_back(i);
    }
    return ans;
}

int main()
{

    return 0;
}