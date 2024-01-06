// Link : https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Using set
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    // set....keeping dist, node
    set<pair<int, int>> st;
    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int src = it.second;
        st.erase(it);

        for (auto dests : adj[src])
        {
            int dest = dests[0];
            int wt = dests[1];
            if (dis + wt < dist[dest])
            {
                dist[dest] = dis + wt;
                st.insert({dist[dest], dest});
            }
        }
    }
    return dist;
}

// Using Priority Queue
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    // min heap....
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    dist[S] = 0;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int src = pq.top().second;
        pq.pop();

        for (auto dests : adj[src])
        {
            int dest = dests[0];
            int wt = dests[1];
            if (dis + wt < dist[dest])
            {
                dist[dest] = dis + wt;
                pq.push({dist[dest], dest});
            }
        }
    }
    return dist;
}

int main()
{

    return 0;
}