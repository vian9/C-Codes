// Link : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Time Complexity : O(V+E)
// Approach-> DFS mein is recursion se top se neeche tk jayenge backtrack krenge usse path ko and then phir se wapas dusra path pr neeche jayenge
// Recursion h toh Stack LIFO use hota h space m

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int V, vector<int> adj[], vector<int> &node, vector<int> &visited, int root)
{
    // Mark krdo visited
    visited[root] = 1;

    node.push_back(root);
    // Ab jo current node h usse connected nodes traverse kro and if not visited then visit it
    for (auto nodes : adj[root])
    {
        if (!visited[nodes])
        {
            dfs(V, adj, node, visited, nodes);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Adjacency list dia hua h
    vector<int> node;
    vector<int> visited(V, 0);
    dfs(V, adj, node, visited, 0);
    return node;
}

int main()
{

    return 0;
}