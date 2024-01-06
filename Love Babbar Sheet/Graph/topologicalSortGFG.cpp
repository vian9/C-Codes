// Link : https://practice.geeksforgeeks.org/problems/topological-sort/1
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Topo sort by bfs - Khann's Algo
// by using queue and indegree....0 indegree in queue dalo and then pop krke bulao and usse related nodes k indegree -1 kro
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

// Topological sort by dfs - stack
void dfs(int V, vector<int> adj[], vector<int> &vis, stack<int> &st, int root)
{
    vis[root] = 1;

    for (auto nodes : adj[root])
    {
        if (!vis[nodes])
        {
            dfs(V, adj, vis, st, nodes);
        }
    }

    st.push(root);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(V, adj, vis, st, i);
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{

    return 0;
}