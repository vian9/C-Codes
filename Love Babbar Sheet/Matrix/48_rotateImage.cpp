// Link : https://leetcode.com/problems/rotate-image/
// Time Complexity : O(n)
// Approach-> Phle column values ko reverse krdo aur phir matrix ka transpose lelo will give the 90 degree rotated matrix
// Another approach could be transpose lelo matrix ka and reflect by perpendicular
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Optimal
// Another approach could be transpose lelo matrix ka and reflect by perpendicular
void rotate(vector<vector<int>> &matrix)
{
    // Ab transpose lena h
    for (int i = 0; i < row; i++)
    {
        // jha tk krlia wha se next row m start
        for (int j = i; j < col; j++)
        {
            if (i == j)
                continue;
            else
            {
                // Image identical se swap hoga
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    // Ab reflect krlo perpendicular se
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col / 2; j++)
        {
            swap(matrix[i][j], matrix[i][col - j - 1]);
        }
    }
}
// The approach I am getting in mind is harr column ko reverse krdo aur phir transpose krdo
void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    // Column ko reverse in O(1) space by using pointers in col to reverse
    for (int i = 0; i < col; i++)
    {
        int start = 0;
        int end = row - 1;
        while (start < end)
        {
            swap(matrix[start][i], matrix[end][i]);
            start++;
            end--;
        }
    }
    // Phle column ko reverse kia
    // vector<int> rowCopy(col);
    // for (int i = 0; i < row / 2; i++)
    // {
    //     rowCopy = {matrix[i].begin(), matrix[i].end()};
    //     matrix[i] = {matrix[row - i - 1].begin(), matrix[row - i - 1].end()};
    //     matrix[row - i - 1] = {rowCopy.begin(), rowCopy.end()};
    // }
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