// Link : https://practice.geeksforgeeks.org/problems/number-of-provinces
// Time Complexity : O()
// Approach-> Isme DFS BFS dono lga skte h....same as Leetcode 547 Graph No of Provinces

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int n, vector<vector<int>> &isConnected, vector<int> &visited, int root)
{
    visited[root] = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && isConnected[root][i] == 1)
        {
            dfs(n, isConnected, visited, i);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    int n = V;
    vector<int> visited(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(n, adj, visited, i);
        }
    }
    return count;
}
// int numProvinces(vector<vector<int>> adj, int V) {
//     int n = V;
//     vector<int> visited(n, 0);
//     queue<int> q;
//     int count = 0;
//     for(int i=0; i<n; i++){
//         if(!visited[i]){
//             q.push(i);
//             count++;
//             while(!q.empty()){
//                 int front = q.front();
//                 visited[front] = 1;
//                 q.pop();
//                 for(int node=0; node <n; node++){
//                     if(!visited[node] && adj[front][node]){
//                          q.push(node);
//                          visited[node] = 1;
//                     }
//                 }
//             }
//         }
//     }
//     return count;
// }

int main()
{

    return 0;
}