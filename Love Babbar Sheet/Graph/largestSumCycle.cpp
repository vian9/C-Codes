// Link : https://practice.geeksforgeeks.org/problems/51afa710a708c0681748445b509696dd588d5c40/1
// https : // leetcode.com/discuss/interview-question/1186405/largest-sum-cycle
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int sum = 0;

void dfs(vector<int> &adj, int src, int n, vector<int> &vis, vector<int> &pathVis)
{
    vis[src] = 1;
    pathVis[src] = 1;
    if (adj[src] != -1)
    {
        int dest = adj[src];
        if (!vis[dest])
        {
            dfs(adj, dest, n, vis, pathVis);
        }
        if (pathVis[dest])
        {
            int curr = dest;
            int sumi = 0;
            do
            {
                sumi += curr;
                curr = adj[curr];
            } while (curr != dest);
            sum = max(sum, sumi);
        }
    }
}

void dfs(vector<int> &adj, int src, int n, vector<int> &vis, vector<int> &pathVis)
{
    vis[src] = 1;
    pathVis[src] = 1;

    if (adj[src] != -1)
    {
        int dest = adj[src];
        if (!vis[dest])
        {
            dfs(adj, dest, n, vis, pathVis);
        }
        if (pathVis[dest])
        {
            int curr = dest;
            int sumi = 0;
            do
            {
                sumi += curr;
                curr = adj[curr];
            } while (curr != dest);
            sum = max(sum, sumi);
        }
    }

    pathVis[src] = 0;
}

long long largestSumCycle(int N, vector<int> Edge)
{
    vector<int> vis(N, 0);
    vector<int> pathVis(N, 0);
    for (int i = 0; i < N; i++)
    {
        dfs(Edge, i, N, vis, pathVis);
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> adj[i];
    }
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    dfs(adj, n, vis, pathVis);
    cout << sum << endl;
    return 0;
}