// Link : https://leetcode.com/problems/rotate-image/
// Time Complexity : O(n)
// Approach-> Phle column values ko reverse krdo aur phir matrix ka transpose lelo will give the 90 degree rotated matrix

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// The approach I am getting in mind is harr column ko reverse krdo aur phir transpose krdo
void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    // Phle column ko reverse kia
    vector<int> rowCopy(col);
    for (int i = 0; i < row / 2; i++)
    {
        rowCopy = {matrix[i].begin(), matrix[i].end()};
        matrix[i] = {matrix[row - i - 1].begin(), matrix[row - i - 1].end()};
        matrix[row - i - 1] = {rowCopy.begin(), rowCopy.end()};
    }
    // Transpose lena h
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            // Agar same index to continue
            if (i == j)
            {
                continue;
            }
            // Different index to swap
            else
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}

int main()
{

    return 0;
}