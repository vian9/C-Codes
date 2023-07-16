// Link : https://leetcode.com/problems/cherry-pickup-ii/
// Time Complexity : O(n*m*n*9) SC:(M*M*2)
// Approach-> Dekho at a moment dono same row mein rhega....so bs 3D vector lenge and koi ek bob k move pr 3 alice k move hoga....so for a row and col given
// 9 cases aayega i.e. a 2D Vector
// Also 3 parameter jaarha h toh 3 loops aayega in Tabulation and ek fix krdo i.e ending row in tabulation toh 2 loop chlega ye dhyan rkhna h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up....we will start from variable point to fixed point as tabulation opposite of memoisation
//  But one thing is same ki ek time pr dono ek hi row mein honge
// toh m-1 row se start krke first row tk jayenge
int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // Yha 3 parameters h row and 2 col....so same row k liye dono k alag alag value aayega
    // Ek row k liye ek j1 pr 3 values....toh total 9 values horhe

    // At a moment prev and current row+1 and row are being used toh 2 2D Matrix se kaam ho jayega....size will be n*n i.e jitna col rhega usse k combo
    vector<vector<int>> prev(n, vector<int>(n, -1));
    // Base case memoisation ka dp mein save krenge
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                prev[i][j] = grid[m - 1][i];
            }
            else
                prev[i][j] = grid[m - 1][i] + grid[m - 1][j];
        }
    }

    // 3 parameter dia tha toh 3 loop chlega phir andar mein same loop as memoisation
    for (int row = m - 2; row >= 0; row--)
    {
        // Even if baht sarra cells INT_MIN se fill hoga still carry out the whole loop jo parameter m change horha h
        // Harr row k ek matrix bnta h to yha declare kro
        vector<vector<int>> curr(n, vector<int>(n, -1));
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                // At any moment robo1 ke ek movement -1, 0 or +1 ke liye robo2 ke 3 movements honge
                // Ab koi ek position ke liye itne movements h to better h ki unsbme max lelo
                int maxi = INT_MIN;
                for (int d1 = -1; d1 < 2; d1++)
                {
                    for (int d2 = -1; d2 < 2; d2++)
                    {
                        int ans;
                        // Agar dono same col pr h to ek baar add hoga
                        if (j1 == j2)
                        {
                            ans = grid[row][j1];
                        }
                        else
                        {
                            ans = grid[row][j1] + grid[row][j2];
                        }
                        if ((j1 + d1 < 0 || j1 + d1 >= n) || (j2 + d2 < 0 || j2 + d2 >= n))
                            ans -= 1e9;
                        else
                            ans += prev[j1 + d1][j2 + d2];
                        maxi = max(maxi, ans);
                    }
                }
                // At a row yhi max value derha h
                curr[j1][j2] = maxi;
            }
        }
        prev = curr;
    }
    // Jo memoisation mein return horha tha whi return krdo
    return prev[0][n - 1];
}

// Tabulation Approach - Bottom Up....we will start from variable point to fixed point as tabulation opposite of memoisation
//  But one thing is same ki ek time pr dono ek hi row mein honge
// toh m-1 row se start krke first row tk jayenge
int cherryHelper(vector<vector<int>> &grid, int m, int n, vector<vector<vector<int>>> &dp)
{
    // Base case memoisation ka dp mein save krenge
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dp[m - 1][i][j] = grid[m - 1][i];
            }
            else
                dp[m - 1][i][j] = grid[m - 1][i] + grid[m - 1][j];
        }
    }

    // 3 parameter dia tha toh 3 loop chlega phir andar mein same loop as memoisation
    for (int row = m - 2; row >= 0; row--)
    {
        // Even if baht sarra cells INT_MIN se fill hoga still carry out the whole loop jo parameter m change horha h
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                // At any moment robo1 ke ek movement -1, 0 or +1 ke liye robo2 ke 3 movements honge
                // Ab koi ek position ke liye itne movements h to better h ki unsbme max lelo
                int maxi = INT_MIN;
                for (int d1 = -1; d1 < 2; d1++)
                {
                    for (int d2 = -1; d2 < 2; d2++)
                    {
                        int ans;
                        // Agar dono same col pr h to ek baar add hoga
                        if (j1 == j2)
                        {
                            ans = grid[row][j1];
                        }
                        else
                        {
                            ans = grid[row][j1] + grid[row][j2];
                        }
                        if ((j1 + d1 < 0 || j1 + d1 >= n) || (j2 + d2 < 0 || j2 + d2 >= n))
                            ans -= 1e9;
                        else
                            ans += dp[row + 1][j1 + d1][j2 + d2];
                        maxi = max(maxi, ans);
                    }
                }
                // At a row yhi max value derha h
                dp[row][j1][j2] = maxi;
            }
        }
    }
    // Jo memoisation mein return horha tha whi return krdo
    return dp[0][0][n - 1];
}

int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // Yha 3 parameters h row and 2 col....so same row k liye dono k alag alag value aayega
    // Ek row k liye ek j1 pr 3 values....toh total 9 values horhe
    // So a 3D matrix will tell a row and ab usme col k values pr values rkhayega
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    //  i is for row and j1 and j2 for col
    return cherryHelper(grid, m, n, dp);
}

// Memoisation Approach - Top Down....we will start from fixed points given and end up at variable points that is at the bottom row
//  But one thing is same ki ek time pr dono ek hi row mein honge
// toh 0 row se start krke last row tk jayenge
int cherryHelper(vector<vector<int>> &grid, int m, int n, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
{
    // Phle overvalue na ho parameter se wo cases
    if (j1 < 0 || j1 > n - 1 || j2 < 0 || j2 > n - 1)
    {
        // Max chahiye to min return krdo apne aap consider nhi hoga
        return -1e9;
    }
    if (i == m - 1)
    {
        // Agar dono same col pr h to ek baar add hoga
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    // At any moment robo1 ke ek movement -1, 0 or +1 ke liye robo2 ke 3 movements honge
    // Ab koi ek position ke liye itne movements h to better h ki unsbme max lelo
    int maxi = INT_MIN;
    for (int d1 = -1; d1 < 2; d1++)
    {
        for (int d2 = -1; d2 < 2; d2++)
        {
            int ans;
            // Agar dono same col pr h to ek baar add hoga
            if (j1 == j2)
            {
                ans = grid[i][j1] + cherryHelper(grid, m, n, i + 1, j1 + d1, j2 + d2, dp);
            }
            else
            {
                ans = grid[i][j1] + grid[i][j2] + cherryHelper(grid, m, n, i + 1, j1 + d1, j2 + d2, dp);
            }
            maxi = max(maxi, ans);
        }
    }
    // At a row yhi max value derha h
    return dp[i][j1][j2] = maxi;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // Yha 3 parameters h row and 2 col....so same row k liye dono k alag alag value aayega
    // Ek row k liye ek j1 pr 3 values....toh total 9 values horhe
    // So a 3D matrix will tell a row and ab usme col k values pr values rkhayega
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    //  i is for row and j1 and j2 for col
    return cherryHelper(grid, m, n, 0, 0, n - 1, dp);
}

// Recursive Approach - Top Down....we will start from fixed points given and end up at variable points that is at the bottom row
//  But one thing is same ki ek time pr dono ek hi row mein honge
// toh 0 row se start krke last row tk jayenge
int cherryHelper(vector<vector<int>> &grid, int m, int n, int i, int j1, int j2)
{
    // Phle overvalue na ho parameter se wo cases
    if (j1 < 0 || j1 > n - 1 || j2 < 0 || j2 > n - 1)
    {
        // Max chahiye to min return krdo apne aap consider nhi hoga
        return -1e9;
    }
    if (i == m - 1)
    {
        // Agar dono same col pr h to ek baar add hoga
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
            return grid[i][j1] + grid[i][j2];
    }

    // At any moment robo1 ke ek movement -1, 0 or +1 ke liye robo2 ke 3 movements honge
    // Ab koi ek position ke liye itne movements h to better h ki unsbme max lelo
    int maxi = INT_MIN;
    for (int d1 = -1; d1 < 2; d1++)
    {
        for (int d2 = -1; d2 < 2; d2++)
        {
            int ans;
            // Agar dono same col pr h to ek baar add hoga
            if (j1 == j2)
            {
                ans = grid[i][j1] + cherryHelper(grid, m, n, i + 1, j1 + d1, j2 + d2);
            }
            else
            {
                ans = grid[i][j1] + grid[i][j2] + cherryHelper(grid, m, n, i + 1, j1 + d1, j2 + d2);
            }
            maxi = max(maxi, ans);
        }
    }
    // At a row yhi max value derha h
    return maxi;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // i is for row and j1 and j2 for col
    return cherryHelper(grid, m, n, 0, 0, n - 1);
}

int main()
{

    return 0;
}