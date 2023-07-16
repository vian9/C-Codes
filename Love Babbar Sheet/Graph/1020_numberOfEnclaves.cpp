// Link : https://leetcode.com/problems/number-of-enclaves/
// Time Complexity : O()
// Approach-> Dekho approach yhi h ki saara jo border areas h usme dekho kha kha 1 hai and usse 1 ko traverse krdo wo jha jha jayega wha wha enclave nhi
// Baad mein check krlo ki jha jha 1 bacha whi h enclave
// DFS issliye kuuki hum andar tk possible traversal krna h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int m, int n, int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> drow, vector<int> dcol)
{
    vis[row][col] = 1;

    ` //Row and col vis kro ki visited ni h and land h
        for (int i = 0; i < 4; i++)
    {
        int sr = row + drow[i];
        int sc = col + dcol[i];
        if ((sr >= 0 && sr < m) && (sc >= 0 && sc < n) && (vis[sr][sc] != 1 && grid[sr][sc] == 1))
            dfs(m, n, sr, sc, grid, vis, drow, dcol);
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));
    // 4 direction mein row and col kaise move krrha
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};

    // all 4 directions mein side wla dekhlo
    for (int i = 0; i < n; i++)
    {

        if (grid[0][i] == 1)
            dfs(m, n, 0, i, grid, vis, drow, dcol);
        if (grid[m - 1][i] == 1)
            dfs(m, n, m - 1, i, grid, vis, drow, dcol);
    }
    for (int i = 0; i < m; i++)
    {

        if (grid[i][0] == 1)
            dfs(m, n, i, 0, grid, vis, drow, dcol);
        if (grid[i][n - 1] == 1)
            dfs(m, n, i, n - 1, grid, vis, drow, dcol);
    }

    // count krlo
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] != 1 && grid[i][j] == 1)
                count++;
        }
    }
    return count;
}

int main()
{

    return 0;
}