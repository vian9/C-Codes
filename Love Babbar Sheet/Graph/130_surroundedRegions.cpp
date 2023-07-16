// Link : https://leetcode.com/problems/surrounded-regions/
// Time Complexity : O()
// Approach-> Same as No of enclaves. Dekhlo side mein kha kha O hai wha se traversal krlo jha tk ja ske and mark krdo
// DFS issliye kuuki hum andar tk possible traversal krna h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// DFS
void dfs(int m, int n, int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis, vector<int> drow, vector<int> dcol)
{
    vis[row][col] = 1;

    // All 4 direction mein dekhlo ki visited na ho and O ho to move krlo
    for (int i = 0; i < 4; i++)
    {
        int sr = row + drow[i];
        int sc = col + dcol[i];
        if ((sr >= 0 && sr < m) && (sc >= 0 && sc < n) && (vis[sr][sc] != 1 && board[sr][sc] == 'O'))
            dfs(m, n, sr, sc, board, vis, drow, dcol);
    }
}

void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};

    // All 4 side direction of box m call krlo
    for (int i = 0; i < n; i++)
    {

        if (board[0][i] == 'O')
            dfs(m, n, 0, i, board, vis, drow, dcol);
        if (board[m - 1][i] == 'O')
            dfs(m, n, m - 1, i, board, vis, drow, dcol);
    }
    for (int i = 0; i < m; i++)
    {

        if (board[i][0] == 'O')
            dfs(m, n, i, 0, board, vis, drow, dcol);
        if (board[i][n - 1] == 'O')
            dfs(m, n, i, n - 1, board, vis, drow, dcol);
    }

    // Ab jo bach gya sb X ho jayega
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] != 1)
                board[i][j] = 'X';
        }
    }
}

int main()
{

    return 0;
}