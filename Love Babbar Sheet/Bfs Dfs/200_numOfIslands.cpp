// Link : https://leetcode.com/problems/number-of-islands/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(vector<vector<char>> &v, int i, int j)
{
    if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j] == '0')
    {
        return;
    }

    v[i][j] = '0';
    dfs(v, i - 1, j);
    dfs(v, i + 1, j);
    dfs(v, i, j - 1);
    dfs(v, i, j + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    int res = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(v, i, j);
                res++;
            }
        }
    }
    return res;
}

int main()
{

    return 0;
}