// Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// bfs

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> inde(V, 0);
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto nodes : adj[i])
        {
            inde[nodes]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (inde[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto nodes : adj[front])
        {
            inde[nodes]--;
            if (inde[nodes] == 0)
                q.push(nodes);
        }
    }
    return ans;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> path(V, 0);

    vector<int> ans = topoSort(V, adj);

    if (ans.size() == V)
        return true;

    return false;
}

// dfs
bool dfs(int V, vector<int> adj[], vector<int> &vis, vector<int> &path, int root)
{
    vis[root] = 1;
    path[root] = 1;

    for (auto nodes : adj[root])
    {
        if (!vis[nodes])
        {
            if (dfs(V, adj, vis, path, nodes))
                return true;
        }
        else if (path[nodes] == 1)
            return true;
    }
    path[root] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> path(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (dfs(V, adj, vis, path, i))
            return true;
    }

    return false;
}

int main()
{

    return 0;
}