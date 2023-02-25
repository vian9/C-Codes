#include <bits/stdc++.h>
using namespace std;

void addEdgeAdjacencyMatrix(vector<vector<pair<int, int>>> &adj, int src, int dest, int weight)
{
    adj[src].push_back(dest, weight);
}
void printGraph(vector<vector<pair<int, int>>> &adj, int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj[V];
    addEdge(&adj, 0, 1, 2);
    addEdge(&adj, 0, 4, 2);
    addEdge(&adj, 1, 2, 3);
    addEdge(&adj, 1, 3, 2);
    addEdge(&adj, 1, 4, 2);
    addEdge(&adj, 2, 3, 1);
    addEdge(&adj, 3, 4, 5);
    printGraph(&adj, V);
    return 0;
}