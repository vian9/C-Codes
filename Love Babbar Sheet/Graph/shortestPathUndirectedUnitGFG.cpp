// Link : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// Time Complexity : O()
// Approach-> Undirected h issliye no need of topo sort....directly distance update kr skte h in sequence....dijkstra k bhi jrurt ni kuuki unit wt h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(N, 0);
    queue<int> st;
    st.push(src);

    vector<int> dist(N, 1e9);
    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.front();
        st.pop();

        for (auto dest : adj[node])
        {
            if (dist[node] + 1 < dist[dest])
            {
                dist[dest] = dist[node] + 1;
                st.push(dest);
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