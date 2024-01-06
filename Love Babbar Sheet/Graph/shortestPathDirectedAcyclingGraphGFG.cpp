// Link : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st, int n, int node)
{
    vis[node] = 1;

    for (auto dest : adj[node])
    {
        int visit = dest.first;
        if (!vis[visit])
        {

            dfs(adj, vis, st, n, visit);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    vector<int> vis(N, 0);
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, st, N, i);
        }
    }

    vector<int> dist(N, 1e9);
    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int dest = it.first;
            int wt = it.second;
            if (dist[node] + wt <= dist[dest])
            {
                dist[dest] = dist[node] + wt;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}

// Using Dijkstra
// Using Priority Queue
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<vector<int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }
    vector<int> dist(N, 1e9);
    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int src = pq.top().second;
        pq.pop();

        for (auto dests : adj[src])
        {
            int dest = dests[0];
            int wt = dests[1];
            if (dis + wt < dist[dest])
            {
                dist[dest] = dis + wt;
                pq.push({dist[dest], dest});
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}

int main()
{

    return 0;
}