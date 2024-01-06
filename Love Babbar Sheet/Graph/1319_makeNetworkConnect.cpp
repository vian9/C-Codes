// Link : https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Time Complexity : O()
// Approach-> Simply we will do unionbySize of disjoint set of each node if they don't have a common parent and if they have that's an extra edge

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Using Disjoint set
class DisjointSet
{
    vector<int> parents;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parents.resize(n + 1);
        size.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parents[i] = i;
        }
    }

    // Path Compression
    int findParents(int u)
    {
        if (parents[u] == u)
            return u;
        return parents[u] = findParents(parents[u]);
    }

    // Union by size
    void unionBySize(int u, int v)
    {
        int ulParU = findParents(u);
        int ulParV = findParents(v);

        if (size[ulParU] < size[ulParV])
        {
            parents[ulParU] = ulParV;
            size[ulParV] += size[ulParU];
        }
        else
        {
            parents[ulParV] = ulParU;
            size[ulParU] += size[ulParV];
        }
    }
};
int makeConnected(int n, vector<vector<int>> &connections)
{
    DisjointSet ds(n);
    int extraedges = 0;
    for (auto it : connections)
    {
        int src = it[0];
        int dest = it[1];
        if (ds.findParents(src) != ds.findParents(dest))
        {
            ds.unionBySize(src, dest);
        }
        else
        {
            extraedges++;
        }
    }
    // If a node points for parents to itself....then it's a parent of itself and hence it's a diff component
    int cnc = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.findParents(i) == i)
            cnc++;
    }

    // to connect n components we need n-1 edges and for that extraedges should be equla to it
    if (extraedges >= cnc - 1)
        return cnc - 1;
    return -1;
}

// We could do using dfs too....like if connects.size() <n-1 then return -1
// Other do dfs traversal and visit every node and mark it visited and take out total different components
// Now we know for a component of p nodes to be connected it needs just p-1 edges and for all components to be connected it needs n-1 edges
// Just return n-1 as the ans as we have extra edges and we merge all we make mst with n-1 edges and we have total edges more than it

void dfs(vector<bool> &vis, int node, vector<int> &adj[])
{
    vis[node] = true;

    for (auto nodes : adj[node])
    {
        if (!vis[nodes])
        {
            dfs(vis, nodes, adj);
        }
    }
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
        return -1;

    vector<int> adj[n];
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<bool> vis(n, false);
    int cnc = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(vis, i, adj);
            cnc++;
        }
    }
    return cnc - 1;
}

int main()
{

    return 0;
}