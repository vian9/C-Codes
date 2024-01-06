// Link : https://leetcode.com/problems/path-with-minimum-effort/
// Time Complexity : O()
// Approach-> Isme hume harr path mein maximum lena h and saare maximum effort se minimum lena h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    // Min-heap priority queue
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;

        // Agar destination aa jate h to wha se kahi ni jaa skte h and wo min hi hoga
        if (row == n - 1 && col == m - 1)
            return dis;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];

            if ((newRow >= 0 && newRow < n) && (newCol >= 0 && newCol < m))
            {
                // NewEffort is max of difference or exist dis
                int newEffort = max(abs(heights[newRow][newCol] - heights[row][col]), dis);
                // Pick newEffort it is min of existing
                if (dist[newRow][newCol] > newEffort)
                {
                    dist[newRow][newCol] = newEffort;
                    pq.push({newEffort, {newRow, newCol}});
                }
            }
        }
    }
}

int main()
{

    return 0;
}