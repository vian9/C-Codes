// Link : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Time Complexity : O(V+E)
// Approach-> BFS is breadth first.....so same level wale chizo pr ek sth jayenge....bfs mostly tb lgao jb traversal krna ho and usme ye ho same distance k
// kuch count ho...will use queue for FIFO property ki jo phle aaya wo ek sth aana chahiye

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Adjacency list dia hua h
    vector<int> node;
    queue<int> q;
    q.push(0);
    // Hmesa visited bnao
    // Visited array hmesa lena h traversal mein wrna hmesa glt jagah baar baar jayenge
    vector<int> visited(V, 0);
    visited[0] = 1;
    while (!q.empty())
    {
        // front nikalo and pop
        int front = q.front();
        node.push_back(front);
        q.pop();
        // Ab usse front pr adjacency list pr traversal kro and push krdo
        for (auto nodes : adj[front])
        {
            if (!visited[nodes])
            {
                visited[nodes] = 1;
                q.push(nodes);
            }
        }
    }
    return node;
}

int main()
{

    return 0;
}