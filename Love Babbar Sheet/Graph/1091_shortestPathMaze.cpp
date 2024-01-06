// Link : https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Time Complexity : O()
// Approach-> Jaise hi sbse phle pahuchenge wo shortest path hoga...jo dikstra se hum dist update krte jayenge

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // Agar start ya end 1 hogya to can't reach
    if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
    {
        return -1;
    }
    if (grid[0][0] == 0 && n == 1 && m == 1)
    {
        return 1;
    }
    vector<vector<int>> dist(n, vector<int>(m, 1e7));
    // dist, row and col
    queue<pair<int, pair<int, int>>> qt;
    // Initial dist 1 se kuuki wo 0 pr rehna ke bhi 1 consider kia h ques m
    qt.push({1, {0, 0}});
    // 8 directional
    vector<int> drow = {0, 1, -1, 0, 1, -1, 1, -1};
    vector<int> dcol = {1, 0, 0, -1, 1, 1, -1, -1};
    dist[0][0] = 0;
    while (!qt.empty())
    {
        auto it = qt.front();
        qt.pop();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        // New row and col
        for (int i = 0; i < 8; i++)
        {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            // Ab agar wo row col exist and wha 0 hai and 1 + dis kaam h to update it
            if ((newRow >= 0 && newRow < n) && (newCol >= 0 && newCol < m) && (grid[newRow][newCol] == 0) && (dist[newRow][newCol] > 1 + dis))
            {
                dist[newRow][newCol] = 1 + dis;
                // End cell aagye to
                if (newRow == n - 1 && newCol == m - 1)
                    return dist[newRow][newCol];
                // Queue mein push krdo
                qt.push({1 + dis, {newRow, newCol}});
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}