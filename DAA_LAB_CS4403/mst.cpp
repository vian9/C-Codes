#include <iostream>
using namespace std;

int minKey(int key[], bool mstSet[], int v)
{
    int min = INT_MAX, min_index;

    for (int i = 0; i < v; i++)
        if (mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;

    return min_index;
}

void printMST(int parent[], int graph[v][v], int v)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < v; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primMST(int graph[v][v], int v)
{
    int parent[v];
    int key[v];
    bool mstSet[v];
    for (int i = 0; i < v; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < v - 1; count++)
    {
        int u = minKey(key, mstSet, v);
        mstSet[u] = true;

        for (int i = 0; i < v; i++) {

            if (graph[u][i] && mstSet[i] == false && graph[u][i] < key[i])
                parent[i] = u, key[i] = graph[u][i];
        }
    }

    printMST(parent, graph, v);
}

int main()
{
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | / \ |
    (3)-------(4)
            9	 */
    int v;
    cout << "Enter the graph weight: " << endl;
    cin >> v;
    int graph[v][v];
    //= { { 0, 2, 0, 6, 0 },
    //                     { 2, 0, 3, 8, 5 },
//                     { 0, 3, 0, 0, 7 },
//                     { 6, 8, 0, 0, 9 },
//                     { 0, 5, 7, 9, 0 } };
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> graph[i][j];
        }

    }

    primMST(graph, v);
    cout << endl;
    return 0;
}