#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> shortestPath(vector<int> adj[], int src, int n)
{
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto nodes : adj[front])
        {
            if (dist[nodes] > dist[front] + 1)
            {
                dist[nodes] = dist[front] + 1;
                q.push(nodes);
            }
        }
    }

    return dist;
}

int main()
{
    int n;
    cin >> n;
    vector<int> edges(n);
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i];
    }
    int c1, c2;
    cin >> c1 >> c2;

    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        if (edges[i] == -1)
            continue;
        adj[i].push_back(edges[i]);
    }

    vector<int> v1 = shortestPath();
    vector<int> v2 = shortestPath();

    int dist = INT_MAX;
    int node = -1;

    for (int i = 0; i < n; i++)
    {
        if (v1[i] == INT_MAX || v2[i] == INT_MAX)
            continue;
        if (v1[i] + v2[i] < dist)
        {
            dist = v1[i] + v2[i];
            node = i;
        }
    }

    cout << node << endl;

    return 0;
}