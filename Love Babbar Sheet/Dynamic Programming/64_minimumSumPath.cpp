// Link : https://leetcode.com/problems/minimum-path-sum/
// Time Complexity : O(n*m) SC: O(m)
// Approach-> Dekho similar to Unique Paths I and II bs yha base case add ho gya h ki min sum lena h aur jha nhi consider krna h out of bound to INT_MAX dedo
// taki hume min consider krte time wo khud bahar ho jaye

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up Approach...0,0 se start krke m-1 n-1 pahuche
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // dp[row][col] means wha se 0 0 jane k kitne ways h
    // m-1 n-1 se jaarha tha recursion to hmne yha 0 0  se start kia
    // Ab base case ko save kro opposite of memoisation
    // Hume kuch min points ye sb nikalna h bs INT_MAX or 1e9 as in case of points m krte maximum points k liye....INT_MAX nhi kuuki overload krdega

    // Since bs row-1 and ek col-1 ka use h toh 2 vector lelo
    vector<int> prev(n, 0);

    for (int row = 0; row < m; row++)
    {
        vector<int> curr(n, 0);
        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
            {
                curr[col] = grid[row][col];
            }
            else
            {
                // Andar k case same as memoisation
                // Ab tabulation opp to memoisation....down nd right
                // Dono ko Max value assign daldo taki agar exist na kre to uska value consider na kre
                // Ek baar down
                int down = 1e9;
                if (row - 1 >= 0)
                    down = grid[row][col] + prev[col];
                // Ek baar right
                int right = 1e9;
                if (col - 1 >= 0)
                    right = grid[row][col] + curr[col - 1];

                curr[col] = min(down, right);
            }
        }
        prev = curr;
    }
    // Isse hi call kia gya tha in memoisation to whi return hoga
    return prev[n - 1];
}

// Tabulation Approach - Bottom Up Approach...0,0 se start krke m-1 n-1 pahuche
int robHelp(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
{
    // dp[row][col] means wha se 0 0 jane k kitne ways h
    // m-1 n-1 se jaarha tha recursion to hmne yha 0 0  se start kia
    // Ab base case ko save kro opposite of memoisation
    // Hume kuch min points ye sb nikalna h bs INT_MAX or 1e9 as in case of points m krte maximum points k liye....INT_MAX nhi kuuki overload krdega
    dp[0][0] = grid[0][0];

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
                dp[row][col] = grid[0][0];
            else
            {
                // Ab tabulation opp to memoisation....down nd right
                // Dono ko Max value assign daldo taki agar exist na kre to uska value consider na kre
                // Ek baar down
                int down = 1e9;
                if (row - 1 >= 0)
                    down = grid[row][col] + dp[row - 1][col];
                // Ek baar right
                int right = 1e9;
                if (col - 1 >= 0)
                    right = grid[row][col] + dp[row][col - 1];

                dp[row][col] = min(down, right);
            }
            cout << row << " " << col << " " << dp[row][col] << endl;
        }
    }
    // Isse hi call kia gya tha in memoisation to whi return hoga
    return dp[m - 1][n - 1];
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // 2 parameters h to 2d array
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return robHelp(grid, m, n, dp);
}

// Memoisation Approach - Top Down Approach...m-1, n-1 se start krke 0 0 pahuche
int robHelp(vector<vector<int>> &grid, int m, int n, int row, int col, vector<vector<int>> &dp)
{
    // dp[row][col] means wha se 0 0 jane k kitne ways h
    // Hume kuch min points ye sb nikalna h bs INT_MAX or 1e9 as in case of points m krte maximum points k liye....INT_MAX nhi kuuki overload krdega
    if (row < 0 || col < 0)
        return 1e9;
    // Base Case...jb 0 and 0 reach kr jaye
    if (row == 0 && col == 0)
        return grid[row][col];

    if (dp[row][col] != -1)
        return dp[row][col];
    // Ek baar up
    int up = grid[row][col] + robHelp(grid, m, n, row - 1, col, dp);
    // Ek baar left
    int left = grid[row][col] + robHelp(grid, m, n, row, col - 1, dp);

    return dp[row][col] = min(up, left);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // 2 parameters h to 2d array
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return robHelp(grid, m, n, m - 1, n - 1, dp);
}

// Recursive Approach - Top Down Approach...m-1,n-1 se start krke 0 0 pahuche
int robHelp(vector<vector<int>> &grid, int m, int n, int row, int col)
{
    // Base Case...jb 0 nd 0 reach kr jaye
    // Hume kuch min points ye sb nikalna h bs INT_MAX or 1e9 as in case of points m krte maximum points k liye....INT_MAX nhi kuuki overload krdega
    if (row < 0 || col < 0)
        return 1e9;
    if (row == 0 && col == 0)
        return grid[row][col];

    // Ek baar up
    int up = grid[row][col] + robHelp(grid, m, n, row - 1, col);
    // Ek baar left
    int left = grid[row][col] + robHelp(grid, m, n, row, col - 1);

    return min(up, left);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    return robHelp(grid, m, n, m - 1, n - 1);
}

int main()
{

    return 0;
}