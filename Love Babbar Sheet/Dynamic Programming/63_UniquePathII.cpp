// Link : https://leetcode.com/problems/unique-paths-ii/
// Time Complexity : O(n*m) and SC: O(N)
// Approach-> Dekho similar to Unique Paths I bs yha base case add ho gya h ki jha obstacle h wha se jane k rasta 0 krdo bs

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up Approach...0,0 se start krke m-1 n-1 pahuche
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    // dp[row][col] means wha se 0 0 jane k kitne ways h
    // m-1 n-1 se jaarha tha recursion to hmne yha 0 0  se start kia
    // Ab base case ko save kro opposite of memoisation

    // Since bs row-1 and ek col-1 ka use h toh 2 vector lelo
    vector<int> prev(n, 0);

    for (int row = 0; row < m; row++)
    {
        vector<int> curr(n, 0);
        for (int col = 0; col < n; col++)
        {
            // Agar wo 1 horha h to wha se 0 0 jane k rasta is total 0 ways
            if (obstacleGrid[row][col] == 1)
            {
                curr[col] = 0;
            }
            else if (row == 0 && col == 0)
            {
                if (obstacleGrid[0][0] != 1)
                    curr[col] = 1;
                else
                    curr[col] = 0;
            }
            else
            {
                // Ab tabulation opp to memoisation....down nd right
                // Andar k case same as memoisation
                //  Ek baar down
                int down = 0, right = 0;
                if (row - 1 >= 0)
                    down = prev[col];
                // Ek baar right
                if (col - 1 >= 0)
                    right = curr[col - 1];

                curr[col] = down + right;
            }
        }
        prev = curr;
    }
    // Isse hi call kia gya tha in memoisation to whi return hoga
    return prev[n - 1];
}

// Tabulation Approach - Bottom Up Approach...0,0 se start krke m-1 n-1 pahuche
int robHelp(vector<vector<int>> &obstacleGrid, int m, int n, vector<vector<int>> &dp)
{
    // dp[row][col] means wha se 0 0 jane k kitne ways h
    // m-1 n-1 se jaarha tha recursion to hmne yha 0 0  se start kia
    // Ab base case ko save kro opposite of memoisation
    // Hume kuch points ye sb nhi nikalna h bs ways to return 0 na ki INT_MIN or -1e9 as in case of points m krte maximum points k liye
    if (obstacleGrid[0][0] != 1)
        dp[0][0] = 1;
    else
        dp[0][0] = 0;

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // Agar wo 1 horha h to wha se 0 0 jane k rasta is total 0 ways
            if (obstacleGrid[row][col] == 1)
            {
                dp[row][col] = 0;
            }
            else if (row == 0 && col == 0)
            {
                if (obstacleGrid[0][0] != 1)
                    dp[0][0] = 1;
                else
                    dp[0][0] = 0;
            }
            else
            {
                // Ab tabulation opp to memoisation....down nd right
                // Andar k case same as memoisation
                //  Ek baar down
                int down = 0, right = 0;
                if (row - 1 >= 0)
                    down = dp[row - 1][col];
                // Ek baar right
                if (col - 1 >= 0)
                    right = dp[row][col - 1];

                dp[row][col] = down + right;
            }
        }
    }
    // Isse hi call kia gya tha in memoisation to whi return hoga
    return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    // 2 parameters h to 2d array
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return robHelp(obstacleGrid, m, n, dp);
}

// Memoisation Approach - Top Down Approach...m-1, n-1 se start krke 0 0 pahuche
int robHelp(vector<vector<int>> &obstacleGrid, int m, int n, int row, int col, vector<vector<int>> &dp)
{
    // dp[row][col] means wha se 0 0 jane k kitne ways h
    // Base Case...jb 0 and 0 reach kr jaye
    if (row < 0 || col < 0)
        return 0;
    // Hume kuch points ye sb nhi nikalna h bs ways to return 0 na ki INT_MIN or -1e9 as in case of points m krte maximum points k liye
    // Yeh case phle aayega then the return 1 as agar jha pahuchna h whi 1 hai to 0 ways hoga
    if (obstacleGrid[row][col] == 1)
        return 0;
    if (row == 0 && col == 0)
        return 1;

    if (dp[row][col] != -1)
        return dp[row][col];
    // Ek baar up
    int up = robHelp(obstacleGrid, m, n, row - 1, col, dp);
    // Ek baar left
    int left = robHelp(obstacleGrid, m, n, row, col - 1, dp);

    return dp[row][col] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    // 2 parameters h to 2d array
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return robHelp(obstacleGrid, m, n, m - 1, n - 1, dp);
}

// Recursive Approach - Top Down Approach...m-1,n-1 se start krke 0 0 pahuche
int robHelp(vector<vector<int>> &obstacleGrid, int m, int n, int row, int col)
{
    // Base Case...jb 0 nd 0 reach kr jaye
    if (row < 0 || col < 0)
        return 0;
    if (row == 0 && col == 0)
        return 1;
    // Hume kuch points ye sb nhi nikalna h bs ways to return 0 na ki INT_MIN or -1e9 as in case of points m krte maximum points k liy
    if (obstacleGrid[row][col] == 1)
        return 0;

    // Ek baar up
    int up = robHelp(obstacleGrid, m, n, row - 1, col);
    // Ek baar left
    int left = robHelp(obstacleGrid, m, n, row, col - 1);

    return up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    return robHelp(obstacleGrid, m, n, m - 1, n - 1);
}

int main()
{

    return 0;
}