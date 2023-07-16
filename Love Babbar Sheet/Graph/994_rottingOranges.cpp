// Link : https://leetcode.com/problems/rotting-oranges/
// Time Complexity : O()
// Approach-> BFS use krenge as isme bolrha h traversal ka level se hum time decide krrhe...jaise 1 level saare nodes ka move krgye to time hua 1

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// BFS
int orangesRotting(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();
    // Row and col jaise change horha h hum uska alag alag vector mein daldo
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};
    // Ab total rotten and fresh count krdo
    int total = 0, rotten = 0, days = 0;
    // queue mein cood dalne h
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Total agar khali ni h to update and agar rotten h to queue mein
            if (grid[i][j] != 0)
                total++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }
    int count = 0;
    // Ab queue
    while (!q.empty())
    {
        int k = q.size();
        count += k;
        // It tells at a level ki kitna rotten h usko visit krdo and bagal ko rot kro
        while (k--)
        {
            int sr = q.front().first;
            int sc = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                // Ab 4 direction mein move kro for a rotten item
                int row = sr + drow[k];
                int col = sc + dcol[k];
                // Agar not rotten to rot krdo and baaki usko traverse k lie push
                if (((row >= 0 && row < n) && (col >= 0 && col < m)) && (grid[row][col] == 1))
                {
                    grid[row][col] = 2;
                    q.push({row, col});
                }
            }
        }
        // Ab days add hoga
        days++;
    }

    // Agar total jo rotten and acha k sum count k equal aaya to sahi h as last m total rot hona chhaiye
    return total == count ? days : -1;
}

int main()
{

    return 0;
}