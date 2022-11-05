#include <bits/stdc++.h>
#include<iostream>
using namespace std;

typedef struct Edge Edge;
struct Edge {
    int src, dest, weight;
};

typedef struct Graph Graph;
struct Graph {
    int V, E;
    Edge* edge; //array of edges
};

Graph* g_Create(int Vertex, int Edges) {
    Graph* graph = new Graph;
    graph->V = Vertex;
    graph->E = Edges;
    graph->edge = new Edge[Edges];
    return graph;
};

void bellman_Ford(Graph* ggraph, int src) {
    int V = ggraph->V;
    int E = ggraph->E;
    int d[V];

    for (int i = 0; i < V; i++)
    {
        d[i] = 100000000;
    }
    d[src] = 0;

    for (int i = 0; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = ggraph->edge[j].src;
            int v = ggraph->edge[j].dest;
            int W = ggraph->edge[j].weight;
            if (d[u] != 100000000 && d[u] + W < d[v])
                d[v] = d[u] + W;
        }

    }
    int d2[V];
    // for (int i = 1; i <= V - 1; i++)
    // {
    //     for (int j = 0; j < V - 1; j++)
    //     {
    //         int u = ggraph->edge[j].src;
    //         int v = ggraph->edge[j].dest;
    //         int W = ggraph->edge[j].weight;
    //         if (d2[u] != 100000000 && d2[u] + W < d2[v]) {
    //             d2[v] = d2[u] + W;
    //         }
    //     }
    // }

    int flag = 0;
    for (int i = 0; i < E; i++) {
        int u = ggraph->edge[i].src;
        int v = ggraph->edge[i].dest;
        int weight = ggraph->edge[i].weight;
        if (d[u] != INT_MAX
            && d[u] + weight < d[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            flag = 1;
            return;
        }
    }

    // if (d != d2) {
    //     cout << "Graph contains an negative cycle! " << endl;
    // } else 
    if (flag == 0) {
        for (int i = 0; i < V; i++)
        {
            cout << "Shortest distance of node " << i << " from node " << src << " is " << d[i] << endl;
        }
    }

    return;

}


int main() {
    cout << "Enter number of Vertex : " << endl;
    int n;
    cin >> n;
    int m;
    cout << "Enter number of Edges : " << endl;
    cin >> m;
    cout << "Enter source followed by destination followed by their edge weight : " << endl;

    int V = n;
    int E = m;

    Graph* gr = g_Create(V, E);

    for (int i = 0; i < E; i++)
    {
        cin >> gr->edge[i].src >> gr->edge[i].dest >> gr->edge[i].weight;
    }
    bellman_Ford(gr, 0);


    return 0;

    //negative edge cycle 
    // Enter number of Vertex :
    // 5
    //     Enter number of Edges :
    // 6
    //     Enter source followed by destination followed by their edge weight :
    // 0 3 7
    //     2 0 5
    //     1 0 3
    //     2 1 - 3
    //     2 5 9
    //     3 5 8
}