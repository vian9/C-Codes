// Link : https://leetcode.com/problems/01-matrix/
// Time Complexity : O()
// Approach-> Dekho yha harr equal step ka cost h....so we will use bfs algorithm to solve this....hum saara 0 push krdenge and phir sbko move krwayenge
// and min distance update krenge...to jha bhi 0 aarha queue mein daldo and usko nikaldo phir and usse traversal kro in 4 directions and update the distance

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<vector<int>> ans(m, vector<int>(n, 0));
    // queue mein cood and dist dalenge
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }

    // 4 direction move
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};

    while (!q.empty())
    {
        // Row and col lo and step count
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        // Wha k matrix ko step count se replace krdo
        ans[row][col] = steps;
        q.pop();
        // Ab 4 direction mein move kro
        for (int i = 0; i < 4; i++)
        {
            int sr = row + drow[i];
            int sc = col + dcol[i];
            // If not visited h to step+1 krke push krdo for traversal
            if (((sr >= 0 && sr < m) && (sc >= 0 && sc < n)) && vis[sr][sc] != 1)
            {
                vis[sr][sc] = 1;
                q.push({{sr, sc}, steps + 1});
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}