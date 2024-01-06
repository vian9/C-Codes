// Link : https://practice.geeksforgeeks.org/problems/alien-dictionary/1
// Time Complexity : O()
// Approach-> Phle to adj list nikal do graph bnakr jha se jha jaaarha h usse basis pr and then topo sort krdo ki sequence kya hoga ki sab line m ban ske

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Topo sort - Kahn's Algo BFS....by using queue and indegree....0 indegree in queue dalo and then pop krke bulao and usse related nodes k indegree -1 kro
void topo(vector<int> adj[], vector<int> ans, int K)
{
    vector<int> inde(K, 0);
    vector<int> vis(K, 0);
    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        for (auto nodes : adj[i])
        {
            inde[nodes]++;
        }
    }
    for (int i = 0; i < K; i++)
    {
        if (inde[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto nodes : adj[front])
        {
            inde[nodes]--;
            if (inde[nodes] == 0)
            {
                q.push(nodes);
            }
        }
    }
}

// Isme phle hum adjacency list nikal lo by using 2 adjacent words mein char diff aaya to node link create krke
string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];
    // Word pr traverse krlo
    for (int i = 0; i < N - 1; i++)
    {
        // Ab jo min len h wha tk traverse kro
        int len = min(dict[i].length(), dict[i + 1].length());
        for (int j = 0; j < len; j++)
        {
            // Char diff aaya to link create krdo
            if (dict[i][j] != dict[i + 1][j])
            {
                adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                break;
            }
        }
    }
    vector<int> ans;
    topo(adj, ans, K);
    string st;
    for (int i = 0; i < ans.size(); i++)
    {
        st.push_back(ans[i] + 'a');
    }
    return st;
}

int main()
{

    return 0;
}