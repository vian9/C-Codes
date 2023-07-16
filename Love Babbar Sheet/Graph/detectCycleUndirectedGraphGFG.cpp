// Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph
// Time Complexity : O()
// Approach-> Cycle undirected graph m tb detect kr skte...keep 1 vector visited and if visited h and parent ke equal ni to koi aur rasta se aaya h
// tb cycle h return krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// BFS
bool bfs(int V, vector<int> adj[], int node, int parent, vector<int> &visited)
{
    // Node and Parent push krdo
    queue<pair<int, int>> nodes;
    nodes.push({node, parent});
    while (!nodes.empty())
    {
        int curr = nodes.front().first;
        int par = nodes.front().second;
        // Visited mark krke usse nodes traverse krdo
        visited[curr] = 1;
        nodes.pop();
        for (auto it : adj[curr])
        {
            if (!visited[it])
            {
                nodes.push({it, curr});
            }
            // Visited h and parent k equal ni to cycle h
            else if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}

// DFS
bool dfs(int V, vector<int> adj[], int node, int parent, vector<int> &visited)
{
    // Node and Parent aagya
    // Visited mark krke usse nodes traverse krdo
    visited[node] = 1;
    for (auto nodes : adj[node])
    {
        if (!visited[nodes])
        {
            if (dfs(V, adj, nodes, node, visited))
                return true;
        }
        // Visited h and parent k equal ni to cycle h
        else if (parent != nodes)
            return true;
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    // Bfs
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(V, adj, i, -1, vis))
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}