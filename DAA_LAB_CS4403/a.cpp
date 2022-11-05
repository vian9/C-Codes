#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct Edge Edge;

struct Edge
{
    int src, dest, weight;
};

typedef struct Graph Graph;
struct Graph
{
    int V, E;
    Edge* edge;
};

Graph* create_graph(int Vertex, int Edges)
{
    Graph* graph = new Graph();
    graph->V = Vertex;
    graph->E = Edges;
    graph->edge = new Edge[Edges];
    return graph;
}

int edge_weight(Graph* g, int i, int j)
{
    int E = g->E;
    int V = g->V;
    int weight = 100000000;
    for (int k = 0; k < E; k++)
    {
        if (g->edge[k].src == i && g->edge[k].dest == j)
        {
            weight = g->edge[k].weight;
        }
    }
    return weight;
}

void floyd_warshall(Graph* ggraph)
{
    int E = ggraph->E;
    int V = ggraph->V;

    int matrix[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            matrix[i][j] = edge_weight(ggraph, i, j);
            // cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j] && matrix[i][k] != 100000000 && matrix[k][j] != 1000000000 && i != j)
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
                if (i == j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << i << " " << j << " " << matrix[i][j] << endl;
        }
    }
}

int main()
{
    cout << "Enter number of Vertex"
        << "\n";
    int n;
    cin >> n;
    int m;
    cout << "Enter number of Edges"
        << "\n";
    cin >> m;
    cout << "Enter source followed by destination followed by their edge weight : "
        << "\n";

    int V = n;
    int E = m;

    Graph* gr = create_graph(V, E);

    for (int i = 0; i < E; i++)
    {
        cin >> gr->edge[i].src >> gr->edge[i].dest >> gr->edge[i].weight;
    }
    floyd_warshall(gr);
    return 0;
}