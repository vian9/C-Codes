// Link : https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620
// Time Complexity : O(V+E)
// Approach-> Adjacency list dia h bs aage mein jo node pr h wo bhi print krna h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> printGraph(int V, vector<int> adj[])
{
    vector<vector<int>> lis;
    // Hume nodes se traverse krte h aur edges list m dalte h
    for (int i = 0; i < V; i++)
    {
        vector<int> curNodes;
        // Current node pushback krdia
        curNodes.push_back(i);
        // Ab usse nodes se jitne bhi edges h traverse krke push krte jao
        for (auto nodes : adj[i])
        {
            curNodes.push_back(nodes);
        }
        lis.push_back(curNodes);
    }
    return lis;
}

int main()
{

    return 0;
}