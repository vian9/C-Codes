// Link : https://leetcode.com/problems/course-schedule/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> inde(V, 0);
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto nodes : adj[i])
        {
            inde[nodes]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (inde[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto nodes : adj[front])
        {
            inde[nodes]--;
            if (inde[nodes] == 0)
                q.push(nodes);
        }
    }
    return ans;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> adj[numCourses];
    int V = numCourses;
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }
    vector<int> ans = topoSort(V, adj);
    if (ans.size() == V)
        return true;
    return false;
}

int main()
{

    return 0;
}