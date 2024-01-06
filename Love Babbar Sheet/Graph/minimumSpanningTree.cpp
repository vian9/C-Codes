// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class DisJoint
{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    DisJoint(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int uprParU = findParent(u);
        int uprParV = findParent(v);

        if (rank[uprParU] < rank[uprParV])
        {
            parent[uprParU] = uprParV;
        }
        else if (rank[uprParU] > rank[uprParV])
        {
            parent[uprParV] = uprParU;
        }
        else
        {
            parent[uprParU] = uprParV;
            rank[uprParV]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int uprParU = findParent(u);
        int uprParV = findParent(v);

        if (size[uprParU] < size[uprParV])
        {
            parent[uprParU] = uprParV;
            size[uprParV] += size[uprParU];
        }
        else
        {
            parent[uprParV] = uprParU;
            size[uprParU] += size[uprParV];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    // Disjoint set bnayenge and usse hume mst lena h
    //  Agar do components ke same parents hai mtlb dono same jagah se h no need to attach
    //  hum wt ka vector mein bnayenge and usse sort krenge
    //  Isme {wt, {src, dest}}
    //  Adj[i] will have all edges
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int src = i;
            int dest = it[0];
            int wt = it[1];
            edges.push_back({wt, {src, dest}});
        }
    }

    DisJoint ds(V);

    sort(edges.begin(), edges.end());
    int sum = 0;

    for (auto it : edges)
    {
        int wt = it.first;
        int src = it.second.first;
        int dest = it.second.second;

        if (ds.findParent(src) != ds.findParent(dest))
        {
            sum += wt;
            // ds.unionByRank(src, dest);
            ds.unionBySize(src, dest);
        }
    }
    return sum;
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    // Input is given as adj[i] contains values as end and wt
    // Prim's Algo for MST
    // Min heap and we will be having vector for visited
    // Min heap will contain {wt, src and dst}
    // In vector we will keep visited 0 for not visited and 1 for visited
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});

    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto nodes : adj[node])
        {
            int wt = nodes[1];
            int desti = nodes[0];
            pq.push({wt, desti});
        }
    }
    return sum;
}

int main()
{

    return 0;
}