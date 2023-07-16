// Link : https://leetcode.com/problems/minimum-falling-path-sum/
// Time Complexity : O()
// Approach-> Dono start and end Variable h to kisi ek ko fix krke call krenge and last mein jisse start m fix kiye usse saare ko call krke minimum le lenge
// Isme koi ek state se start kro fixed krke and call kro and usme se wo state k sbse minimum lelo
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation - Bottom Up....
// So finally yha m-1 pr value aayega min value to do this work return hokr
int minFallingPathSum(vector<vector<int>> &matrix)
{
    // dp[row][col] tells min value needed to go from that row,col to 0 tk in matrix
    // Base case jb 0 hit krega row...toh dp[0][col] is its value....toh Tabulation mein memoisation k base case save krlia
    int m = matrix.size();
    int n = matrix[m - 1].size();

    // Yha prev vector se lerhe h row+1 and curr mein store krrhe....size as row rkho
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++)
    {
        prev[i] = matrix[0][i];
    }

    // Ab memoisation se opposite se start krenge i.e row 1 se
    for (int row = 1; row < m; row++)
    {
        vector<int> curr(n, -1);
        for (int col = 0; col < n; col++)
        {
            // mere pass ab wo 0 k min case aagya h....ab neeche ke move se data lena h to just down or diagonal move hoga
            // Cases same as memoisation hota h
            // Ek baar down just adjacent move krenge
            int up = matrix[row][col] + prev[col];
            // Ek baar right adjacent move krenge
            int right = 1e9;
            if (col + 1 < n)
                right = matrix[row][col] + prev[col + 1];
            // Ek baar left adjacent move krenge
            int left = 1e9;
            if (col - 1 >= 0)
                left = matrix[row][col] + prev[col - 1];

            curr[col] = min(up, min(left, right));
        }
        prev = curr;
    }

    // dp[m-1][col] will tell min value from it to 0
    int mini = INT_MAX;
    // n-1 row and i column se call krdia
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prev[i]);
    }
    // At end dp[m-1][col] pr min value saare path se aa jayega
    return mini;
}

// Tabulation Approach - Bottom Up....
// So finally yha m-1 pr value aayega min value to do this work return hokr
int robHelp(vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &dp)
{
    // dp[row][col] tells min value needed to go from that row,col to 0 tk in matrix
    // Base case jb 0 hit krega row...toh dp[0][col] is its value....toh Tabulation mein memoisation k base case save krlia
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i];
    }

    // Ab memoisation se opposite se start krenge i.e row 1 se
    for (int row = 1; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // mere pass ab wo 0 k min case aagya h....ab neeche ke move se data lena h to just down or diagonal move hoga
            // Cases same as memoisation hota h
            // Ek baar down just adjacent move krenge
            int up = matrix[row][col] + dp[row - 1][col];
            // Ek baar right adjacent move krenge
            int right = 1e9;
            if (col + 1 < n)
                right = matrix[row][col] + dp[row - 1][col + 1];
            // Ek baar left adjacent move krenge
            int left = 1e9;
            if (col - 1 >= 0)
                left = matrix[row][col] + dp[row - 1][col - 1];

            dp[row][col] = min(up, min(left, right));
        }
    }

    // dp[m-1][col] will tell min value from it to 0
    int mini = INT_MAX;
    // n-1 row and i column se call krdia
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, dp[m - 1][i]);
    }
    // At end dp[m-1][col] pr min value saare path se aa jayega
    return mini;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    // 2 parameter rows and col toh 2D vector
    int m = matrix.size();
    int n = matrix[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // At end dp[m-1][col] pr min value saare path se aa jayega
    return robHelp(matrix, m, n, dp);
}

// Memoisation Approach - Top Down....will start from fixed point and move on till the variable point always
// Hum n-1 se start krrhe h taking as fixed h and 0 tk jayenge
int robHelp(vector<vector<int>> &matrix, int m, int n, int row, int col, vector<vector<int>> &dp)
{
    // dp[row][col] tells min value needed to go from that row,col to m-1 tk in matrix
    // Phle exception jab over value pr variable jayega wo handle krlo
    if (row < 0 || col < 0 || col > n - 1)
    {
        return 1e9;
    }
    // Base case jb 0 hit krega row
    if (row == 0)
    {
        return matrix[row][col];
    }
    if (dp[row][col] != -1)
        return dp[row][col];
    // Ek baar down just adjacent move krenge
    int up = matrix[row][col] + robHelp(matrix, m, n, row - 1, col, dp);
    // Ek baar right adjacent move krenge
    int right = matrix[row][col] + robHelp(matrix, m, n, row - 1, col + 1, dp);
    // Ek baar left adjacent move krenge
    int left = matrix[row][col] + robHelp(matrix, m, n, row - 1, col - 1, dp);

    return dp[row][col] = min(up, min(left, right));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    // 2 parameter rows and col toh 2D vector
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int mini = INT_MAX;
    // n-1 row and i column se call krdia
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, robHelp(matrix, m, n, m - 1, i, dp));
    }
    // At end dp[m-1][col] pr min value saare path se aa jayega
    return mini;
}

// Recursive Approach - Top Down....will start from fixed point and move on till the variable point always
// Hum 0 se start krrhe h jo fixed h and m-1 tk jayenge
// So finally yha 0 pr value aayega min value to do this work return hokr
int robHelp(vector<vector<int>> &matrix, int m, int n, int row, int col)
{
    // Phle exception jab over value pr variable jayega wo handle krlo
    if (row < 0 || col < 0 || col > n - 1)
    {
        return 1e9;
    }
    // Base case jb 0 hit krega row
    if (row == 0)
    {
        return matrix[row][col];
    }
    // Ek baar down just adjacent move krenge
    int up = matrix[row][col] + robHelp(matrix, m, n, row - 1, col);
    // Ek baar right adjacent move krenge
    int right = matrix[row][col] + robHelp(matrix, m, n, row - 1, col + 1);
    // Ek baar left adjacent move krenge
    int left = matrix[row][col] + robHelp(matrix, m, n, row - 1, col - 1);

    return min(up, min(left, right));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int mini = INT_MAX;
    // n-1 row and i column se call krdia
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, robHelp(matrix, m, n, m - 1, i));
    }

    return mini;
}

int main()
{

    return 0;
}