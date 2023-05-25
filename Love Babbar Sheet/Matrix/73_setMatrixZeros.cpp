// Link : https://leetcode.com/problems/set-matrix-zeroes/
// Time Complexity : O(n^2)
// Approach-> 0th Row se check kro.....1st col mein check krna....0th col ko ignore kro usko variable se check krrhe

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Thora optimised
void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    // Ek row mein no of col ghusayenge
    int col = matrix[0].size();
    vector<int> rows(col, 0);
    bool isCol = false;
    bool isRow = false;
    // Time complexity will be always O(mn)
    // Space k liye wo first cell of row and col ko zero mark krenge
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == 0)
            isCol = true;
        // 1st col se update krrhe...0th col ko waise hi rhne do....taaki 0,0 update na ho
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < col; i++)
    {
        if (matrix[0][i] == 0)
        {
            for (int j = 0; j < row; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == 0)
        {
            matrix[i] = rows;
        }
    }
    if (isCol)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    // Ek row mein no of col ghusayenge
    int col = matrix[0].size();
    bool isCol = false;
    // Time complexity will be always O(mn)
    // Space k liye wo first cell of row and col ko zero mark krenge
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == 0)
            isCol = true;
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // 1st row and 1st col se
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    // Ab 0th col touch nhi kia h to 1st row k liye
    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < col; i++)
        {
            matrix[0][i] = 0;
        }
    }
    // 1st col k liye
    if (isCol)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{

    return 0;
}