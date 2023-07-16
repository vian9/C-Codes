// Link : https://leetcode.com/problems/triangle/
// Time Complexity : O(n * m) SC: O(n)
// Approach-> Fixed point se variable point k side jayenge....it will be easier to think approach ki kha se start kre
// And as format lelo pick krke and convert to memoisation then tabulation

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation - Bottom Up....
// So finally yha 0 pr value aayega min value to do this work return hokr
int minimumTotal(vector<vector<int>> &triangle)
{
    // dp[row][col] tells min value needed to go from that row,col to m-1 tk in triangle
    // Base case jb m-1 hit krega row...toh dp[m-1][col] is its value....toh Tabulation mein memoisation k base case save krlia
    int m = triangle.size();
    int n = triangle[m - 1].size();

    // Yha prev vector se lerhe h row+1 and curr mein store krrhe....size as row rkho
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++)
    {
        prev[i] = triangle[m - 1][i];
    }

    // Ab memoisation se opposite se start krenge i.e row m-2 se
    for (int row = m - 2; row >= 0; row--)
    {
        vector<int> curr(m, -1);
        for (int col = row; col >= 0; col--)
        {
            // mere pass ab wo m-1 k max case aagya h....ab neeche ke move se data lena h to just down or diagonal move hoga
            // Cases same as memoisation hota h
            // Ek baar down just adjacent move krenge
            int down = triangle[row][col] + prev[col];
            // Ek baar right adjacent move krenge
            int right = triangle[row][col] + prev[col + 1];

            curr[col] = min(down, right);
        }
        prev = curr;
    }

    // Jo memoisation mein call kiye thay whi return krenge
    // At end dp[0][0] pr min value saare path se aa jayega
    return prev[0];
}

// Tabulation Approach - Bottom Up....
// So finally yha 0 pr value aayega min value to do this work return hokr
int robHelp(vector<vector<int>> &triangle, int m, int n, vector<vector<int>> &dp)
{
    // dp[row][col] tells min value needed to go from that row,col to m-1 tk in triangle
    // Base case jb m-1 hit krega row...toh dp[m-1][col] is its value....toh Tabulation mein memoisation k base case save krlia
    for (int i = 0; i < n; i++)
    {
        dp[m - 1][i] = triangle[m - 1][i];
    }

    // Ab memoisation se opposite se start krenge i.e row m-2 se
    for (int row = m - 2; row >= 0; row--)
    {
        for (int col = row; col >= 0; col--)
        {
            // mere pass ab wo m-1 k max case aagya h....ab neeche ke move se data lena h to just down or diagonal move hoga
            // Cases same as memoisation hota h
            // Ek baar down just adjacent move krenge
            int down = triangle[row][col] + dp[row + 1][col];
            // Ek baar right adjacent move krenge
            int right = triangle[row][col] + dp[row + 1][col + 1];

            dp[row][col] = min(down, right);
        }
    }

    // Jo memoisation mein call kiye thay whi return krenge
    return dp[0][0];
}

int minimumTotal(vector<vector<int>> &triangle)
{
    // 2 parameter rows and col toh 2D vector
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // At end dp[0][0] pr min value saare path se aa jayega
    return robHelp(triangle, m, n, dp);
}

// Memoisation Approach - Top Down....will start from fixed point and move on till the variable point always
// Hum 0 se start krrhe h jo fixed h and m-1 tk jayenge
// So finally yha 0 pr value aayega min value to do this work return hokr
int robHelp(vector<vector<int>> &triangle, int m, int n, int row, int col, vector<vector<int>> &dp)
{
    // dp[row][col] tells min value needed to go from that row,col to m-1 tk in triangle
    // Phle exception jab over value pr variable jayega wo handle krlo
    if (row > m - 1 || col > row)
    {
        return 1e9;
    }
    // Base case jb m-1 hit krega row
    if (row == m - 1)
    {
        // Yeh bhi de dega ek baar m
        //  int mini = 1e9;
        //  for (int i = 0; i < triangle[m - 1].size(); i++)
        //  {
        //      mini = min(mini, triangle[m - 1][i]);
        //  }
        return triangle[row][col];
    }
    if (dp[row][col] != -1)
        return dp[row][col];
    // Ek baar down just adjacent move krenge
    int down = triangle[row][col] + robHelp(triangle, m, n, row + 1, col, dp);
    // Ek baar right adjacent move krenge
    int right = triangle[row][col] + robHelp(triangle, m, n, row + 1, col + 1, dp);

    return dp[row][col] = min(down, right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    // 2 parameter rows and col toh 2D vector
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // At end dp[0][0] pr min value saare path se aa jayega
    return robHelp(triangle, m, n, 0, 0, dp);
}

// Recursive Approach - Top Down....will start from fixed point and move on till the variable point always
// Hum 0 se start krrhe h jo fixed h and m-1 tk jayenge
// So finally yha 0 pr value aayega min value to do this work return hokr
int robHelp(vector<vector<int>> &triangle, int m, int row, int col)
{
    // Phle exception jab over value pr variable jayega wo handle krlo
    if (row > m - 1 || col > row)
    {
        return 1e9;
    }
    // Base case jb m-1 hit krega row
    if (row == m - 1)
    {
        // Yeh bhi de dega ek baar m
        //  int mini = 1e9;
        //  for (int i = 0; i < triangle[m - 1].size(); i++)
        //  {
        //      mini = min(mini, triangle[m - 1][i]);
        //  }
        return triangle[row][col];
    }
    // Ek baar down just adjacent move krenge
    int down = triangle[row][col] + robHelp(triangle, m, row + 1, col);
    // Ek baar right adjacent move krenge
    int right = triangle[row][col] + robHelp(triangle, m, row + 1, col + 1);

    return min(down, right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    return robHelp(triangle, triangle.size(), 0, 0);
}

int main()
{

    return 0;
}