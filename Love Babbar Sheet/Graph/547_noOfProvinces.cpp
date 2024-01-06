// Link : https://leetcode.com/problems/number-of-provinces/
// Time Complexity : O(V+E)
// Approach-> Dekho logic yhi h ki dfs ya bfs se pura traversal krdo and visited mark krte jao....ab jaise hi ek traversal over hoga dusra jo unvisited h
// usse call chl jayega and isse no of calls se no of provinces mil jayega

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Using Disjoint set
class DisjointSet
{
    vector<int> parents;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parents.resize(n + 1);
        size.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parents[i] = i;
        }
    }

    // Path Compression
    int findParents(int u)
    {
        if (parents[u] == u)
            return u;
        return parents[u] = findParents(parents[u]);
    }

    // Union by size
    void unionBySize(int u, int v)
    {
        int ulParU = findParents(u);
        int ulParV = findParents(v);

        if (size[ulParU] < size[ulParV])
        {
            parents[ulParU] = ulParV;
            size[ulParV] += size[ulParU];
        }
        else
        {
            parents[ulParV] = ulParU;
            size[ulParU] += size[ulParV];
        }
    }
};

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    DisjointSet ds(n);

    // Linking the components
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1)
            {
                ds.unionBySize(i, j);
            }
        }
    }

    // Finding total components
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.findParents(i) == i)
        {
            count++;
        }
    }

    return count;
}

// DFS - Mark kro and traversal krte jao
void dfs(int n, vector<vector<int>> &isConnected, vector<int> &visited, int root)
{
    visited[root] = 1;
    for (int i = 0; i < n; i++)
    {
        // Not visited and connected ho tb
        if (visited[i] == 0 && isConnected[root][i] == 1)
        {
            dfs(n, isConnected, visited, i);
        }
    }
}

// Matrix dia h
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    // Visited mark krne k liye
    vector<int> visited(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(n, isConnected, visited, i);
        }
    }
    return count;
}

// BFS - Isme loop chla do and queue mein daldo and traversal krdo
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> visited(n, 0);
    queue<int> q;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // Not viisted pr queue
        if (!visited[i])
        {
            q.push(i);
            count++;
            while (!q.empty())
            {
                // Ab queue se nikalo viisted mein dalo and then usse traverse kro queue mein push krke
                int front = q.front();
                visited[front] = 1;
                q.pop();
                // Front k traverse kro and queue mein push krte jao
                for (int node = 0; node < n; node++)
                {
                    if (!visited[node] && isConnected[front][node])
                    {
                        q.push(node);
                        visited[node] = 1;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{

    return 0;
}