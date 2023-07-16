// Link : https://leetcode.com/problems/cherry-pickup/
// Time Complexity : O(n^3) SC: O(N^2)
// Approach-> Dekho neeche tk jana h and then phir wapas...toh best h dono ek hi jagah se start krke end tk bhejdo
// Harr row and col k liye 4 possibility bnega jisme se max lenge
// Bs ek hi base case tha to whi save kro bs...baaki sb jo h loop ko krne do
// Yha loop peeche se chalao kuuki col + 1 in same row k value chahiye issliye

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimsation - m-1 Row, col = n-1 se start krenge dono
//  No of steps will be same chahe kaise bhi jaye so will reach end at same time
int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // 3 values h parameters ka row1 and col1 and col2 toh 3D Vector
    // But since row+1 and row use horha h toh 2 2D Vector chahiye
    vector<vector<int>> prev(n, vector<int>(n, -1));
    // Dono same no of steps mein pahuchega at a time and r+c = constant rhega dono k liye
    // Base cases ko save krenge of memoisation
    // Bs ek hi case tha to whi save kro bs...baaki sb jo h loop ko krne do
    prev[n - 1][n - 1] = grid[m - 1][n - 1];

    // 3 parameters toh 3 loop chlega
    for (int row1 = m - 1; row1 >= 0; row1--)
    {
        // Yha loop peeche se chalao kuuki col + 1 in same row k value chahiye issliye
        vector<vector<int>> curr(n, vector<int>(n, -1));
        for (int col1 = n - 1; col1 >= 0; col1--)
        {
            for (int col2 = n - 1; col2 >= 0; col2--)
            {
                int row2 = row1 + col1 - col2;
                if (row2 < 0 || row2 >= n)
                    curr[col1][col2] = -1e9;
                else if (grid[row1][col1] == -1 || grid[row2][col2] == -1)
                {
                    curr[col1][col2] = -1e9;
                }
                else if (row1 == m - 1 && (col1 == n - 1 && col2 == n - 1))
                {
                    curr[col1][col2] = grid[row1][col1];
                }
                else
                {
                    int ans = 0;
                    // Agar dono same jagah to ek jagah count
                    if (row1 == row2 && col1 == col2)
                    {
                        ans = grid[row1][col1];
                    }
                    else
                    {
                        ans = grid[row1][col1] + grid[row2][col2];
                    }
                    int right = -1e9, bothRight = -1e9, down = -1e9, bothDown = -1e9;
                    // Ek right, dono right, ek down and dono down k liye call krdia
                    if (col1 + 1 < n)
                        right = curr[col1 + 1][col2];
                    if (col1 + 1 < n && col2 + 1 < n)
                        bothRight = curr[col1 + 1][col2 + 1];
                    if (row1 + 1 < m)
                        down = prev[col1][col2];
                    if (row1 + 1 < m && col2 + 1 < n)
                        bothDown = prev[col1][col2 + 1];
                    int val = max(max(right, bothRight), max(down, bothDown));
                    curr[col1][col2] = ans + val;
                }
            }
        }
        prev = curr;
    }
    // Whi return krenge jo memoisation mein call kiye thay
    int ans = prev[0][0];
    // Agar ans < 0 toh koi path exist nhi krta h
    if (ans < 0)
        return 0;
    return ans;
}

// Tabulation Approach - m-1 Row, col = n-1 se start krenge dono
//  No of steps will be same chahe kaise bhi jaye so will reach end at same time
int cherryHelper(vector<vector<int>> &grid, int m, int n, vector<vector<vector<int>>> &dp)
{
    // Dono same no of steps mein pahuchega at a time and r+c = constant rhega dono k liye
    // Base cases ko save krenge of memoisation
    // Bs ek hi case tha to whi save kro bs...baaki sb jo h loop ko krne do
    dp[m - 1][n - 1][n - 1] = grid[m - 1][n - 1];

    // 3 parameters toh 3 loop chlega
    for (int row1 = m - 1; row1 >= 0; row1--)
    {
        // Yha loop peeche se chalao kuuki col + 1 in same row k value chahiye issliye
        for (int col1 = n - 1; col1 >= 0; col1--)
        {
            for (int col2 = n - 1; col2 >= 0; col2--)
            {
                int row2 = row1 + col1 - col2;
                if (row2 < 0 || row2 >= n)
                    dp[row1][col1][col2] = -1e9;
                else if (grid[row1][col1] == -1 || grid[row2][col2] == -1)
                {
                    dp[row1][col1][col2] = -1e9;
                }
                else if (row1 == m - 1 && (col1 == n - 1 && col2 == n - 1))
                {
                    continue;
                }
                else
                {
                    int ans = 0;
                    // Agar dono same jagah to ek jagah count
                    if (row1 == row2 && col1 == col2)
                    {
                        ans = grid[row1][col1];
                    }
                    else
                    {
                        ans = grid[row1][col1] + grid[row2][col2];
                    }
                    int right = -1e9, bothRight = -1e9, down = -1e9, bothDown = -1e9;
                    // Ek right, dono right, ek down and dono down k liye call krdia
                    if (col1 + 1 < n)
                        right = dp[row1][col1 + 1][col2];
                    if (col1 + 1 < n && col2 + 1 < n)
                        bothRight = dp[row1][col1 + 1][col2 + 1];
                    if (row1 + 1 < m)
                        down = dp[row1 + 1][col1][col2];
                    if (row1 + 1 < m && col2 + 1 < n)
                        bothDown = dp[row1 + 1][col1][col2 + 1];
                    int curr = max(max(right, bothRight), max(down, bothDown));
                    dp[row1][col1][col2] = ans + curr;
                }
            }
        }
    }
    // Whi return krenge jo memoisation mein call kiye thay
    return dp[0][0][0];
}

int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // 3 values h parameters ka row1 and col1 and col2 toh 3D Vector
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    int ans = cherryHelper(grid, m, n, dp);
    // Agar ans < 0 toh koi path exist nhi krta h
    if (ans < 0)
        return 0;
    return ans;
}

// Memoisation Approach - 0 Row, col = 0 se start krenge dono
//  No of steps will be same chahe kaise bhi jaye so will reach end at same time
int cherryHelper(vector<vector<int>> &grid, int m, int n, int row1, int col1, int col2, vector<vector<vector<int>>> &dp)
{
    // Dono same no of steps mein pahuchega at a time and r+c = constant rhega dono k liye
    int row2 = row1 + col1 - col2;
    // Out of bound cases always phle
    if (col1 < 0 || col2 < 0 || col1 >= m || col2 >= m || row1 >= m || row2 >= m)
    {
        return -1e9;
    }
    // Agar obstacle aagya to -1e9 se out krdenge wo path
    if (grid[row1][col1] == -1 || grid[row2][col2] == -1)
    {
        return -1e9;
    }
    // Dono sth hi pahuchega
    if ((row1 == m - 1 && col1 == n - 1) && col2 == n - 1)
    {
        return grid[row1][col1];
    }
    if (dp[row1][col1][col2] != -1)
        return dp[row1][col1][col2];
    int ans = 0;
    // Agar dono same jagah to ek jagah count
    if (row1 == row2 && col1 == col2)
    {
        ans = grid[row1][col1];
    }
    else
    {
        ans = grid[row1][col1] + grid[row2][col2];
    }
    // Ek right, dono right, ek down and dono down k liye call krdia
    int right = cherryHelper(grid, m, n, row1, col1 + 1, col2, dp);
    int bothRight = cherryHelper(grid, m, n, row1, col1 + 1, col2 + 1, dp);
    int down = cherryHelper(grid, m, n, row1 + 1, col1, col2, dp);
    int bothDown = cherryHelper(grid, m, n, row1 + 1, col1, col2 + 1, dp);
    int curr = max(max(right, bothRight), max(down, bothDown));
    return dp[row1][col1][col2] = ans + curr;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // 3 values h parameters ka row1 and col1 and col2 toh 3D Vector
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    int ans = cherryHelper(grid, m, n, 0, 0, 0, dp);
    // Agar ans < 0 toh koi path exist nhi krta h
    if (ans < 0)
        return 0;
    return ans;
}

// Recursive Approach - 0 Row, col = 0 se start krenge dono
//  No of steps will be same chahe kaise bhi jaye so will reach end at same time
int cherryHelper(vector<vector<int>> &grid, int m, int n, int row1, int col1, int col2)
{
    // Dono same no of steps mein pahuchega at a time and r+c = constant rhega dono k liye
    int row2 = row1 + col1 - col2;
    // Out of bound cases always phle
    if (col1 < 0 || col2 < 0 || col1 >= m || col2 >= m || row1 >= m || row2 >= m)
    {
        return -1e9;
    }
    // Agar obstacle aagya to -1e9 se out krdenge wo path
    if (grid[row1][col1] == -1 || grid[row2][col2] == -1)
    {
        return -1e9;
    }
    // Dono sth hi pahuchega
    if ((row1 == m - 1 && col1 == n - 1) && col2 == n - 1)
    {
        return grid[row1][col1];
    }

    int ans = 0;
    // Agar dono same jagah to ek jagah count
    if (row1 == row2 && col1 == col2)
    {
        ans = grid[row1][col1];
    }
    else
    {
        ans = grid[row1][col1] + grid[row2][col2];
    }
    // Ek right, dono right, ek down and dono down k liye call krdia
    int right = cherryHelper(grid, m, n, row1, col1 + 1, col2);
    int bothRight = cherryHelper(grid, m, n, row1, col1 + 1, col2 + 1);
    int down = cherryHelper(grid, m, n, row1 + 1, col1, col2);
    int bothDown = cherryHelper(grid, m, n, row1 + 1, col1, col2 + 1);
    int curr = max(max(right, bothRight), max(down, bothDown));
    return ans + curr;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = cherryHelper(grid, m, n, 0, 0, 0);
    // Agar ans < 0 toh koi path exist nhi krta h
    if (ans < 0)
        return 0;
    return ans;
}

int main()
{

    return 0;
}