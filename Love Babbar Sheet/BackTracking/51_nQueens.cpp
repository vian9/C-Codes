// Link : https://leetcode.com/problems/n-queens/
// Time Complexity : O()
// Approach-> Phle ab hashing krlo ki kisse row pr kaun h...and ab usspr check krlo and phir push kro on check and then pop that is backtrack

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// optimised code
// col bhejrhe h to row dalenge harr bar
void myCombo(vector<vector<string>> &ans, vector<string> &ds, int col, int n, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
{
    if (col >= n)
    {
        ans.push_back(ds);
        return;
    }

    // row is index....now move from 0 to n-1 col
    for (int row = 0; row < n; row++)
    {
        // now instead of chek just look into upper and lower diagonal and on row to queen h ya nhi and usse row pr aa skta h ya nhi
        if (leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0)
        {
            // row pr koi h to nhi dekhlia and diagonals bhi
            leftRow[row] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[n - 1 + col - row] = 1;
            // Yha check kia value dal skte ho then htadia backtrack krdia
            ds[row][col] = 'Q';
            myCombo(ans, ds, col + 1, n, leftRow, upperDiagonal, lowerDiagonal);
            ds[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    // Vector of n strings jiska initial values lelia h
    vector<string> ds(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        ds[i] = s;
    }
    // Row k data rkhlia h
    vector<int> leftRow(n, 0);
    // 2*n-1 came from max value of sum of row and col....so 2n - 2 store kr skte ho jb 2n-1 size k array hoga 0 to 2n-2 store krne k liye
    vector<int> upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    myCombo(ans, ds, 0, n, leftRow, upperDiagonal, lowerDiagonal);
    return ans;
}

// Isme harr baar k liye O(3n) step check krrha h....so optimised code will be to use Hashing
bool myCheck(vector<string> ds, int col, int row, int n)
{
    int dupRow = row;
    int dupCol = col;
    // Ek baar upper diagronal
    while (row >= 0 && col >= 0)
    {
        if (ds[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = dupRow;
    col = dupCol;
    // same row uske liye col move kia...col move krrha h row alag alag dal rhe for a col so row check
    while (col >= 0)
    {
        if (ds[row][col] == 'Q')
            return false;
        col--;
    }
    col = dupCol;
    row = dupRow;
    // lower diagonal
    while (col >= 0 && row < n)
    {
        if (ds[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

// col bhejrhe h to row dalenge harr bar
void myCombo(vector<vector<string>> &ans, vector<string> &ds, int col, int n)
{
    if (col >= n)
    {
        ans.push_back(ds);
        return;
    }

    // row is index....now move from 0 to n-1 for same col
    for (int row = 0; row < n; row++)
    {
        bool check = myCheck(ds, col, row, n);
        if (check)
        {
            // Yha check kia value dal skte ho then htadia backtrack krdia
            ds[row][col] = 'Q';
            myCombo(ans, ds, col + 1, n);
            ds[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    // Vector of n strings jiska initial values lelia h
    vector<string> ds(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        ds[i] = s;
    }
    myCombo(ans, ds, 0, n);
    return ans;
}

int main()
{

    return 0;
}