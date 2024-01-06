// Link : https://leetcode.com/discuss/interview-question/2032910/juspay-oa-nearest-meeting-cell
// Time Complexity : O()
// Approach->

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
                q.pop();
            }
        }
    }
    return dist;
}

// Shortest path nikal rhe ho
vector<int> shortestPath(vector<int> adj[], int src, int n)
{
    // Inf distance phle
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    // Source dala and uska dist 0 kia khudse
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        // current node front nikala and uska neighbour pr ghuma and check kro ki dist kaam h to push and update
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

    vector<int> v1 = shortestPath(adj, c1, n);
    vector<int> v2 = shortestPath(adj, c2, n);

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