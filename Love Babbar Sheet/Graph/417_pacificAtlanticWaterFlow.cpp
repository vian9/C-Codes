// Link : https://leetcode.com/problems/pacific-atlantic-water-flow/
// Time Complexity : O(n*m)
// Approach-> Phle jitna bhi pacific k side h dfs call kia aur ussse greater jahan jahan pahuch skte h mark true
// Similarly phir atlantic k liye kia aur finally dono mein jo common wo ans

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Usse cell se greater jo jo h call them as hum ocean se start krrhe h
void checkFlow(vector<vector<int>> &heights, vector<vector<bool>> &flag, int i, int j)
{
    int row = heights.size();
    int col = heights[0].size();
    flag[i][j] = true;
    if (i - 1 >= 0 && !flag[i - 1][j] && heights[i - 1][j] >= heights[i][j])
        checkFlow(heights, flag, i - 1, j);
    if (i + 1 < row && !flag[i + 1][j] && heights[i + 1][j] >= heights[i][j])
        checkFlow(heights, flag, i + 1, j);
    if (j - 1 >= 0 && !flag[i][j - 1] && heights[i][j - 1] >= heights[i][j])
        checkFlow(heights, flag, i, j - 1);
    if (j + 1 < col && !flag[i][j + 1] && heights[i][j + 1] >= heights[i][j])
        checkFlow(heights, flag, i, j + 1);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int row = heights.size();
    int col = heights[0].size();
    vector<vector<int>> ans;
    vector<vector<bool>> flag1(row, vector<bool>(col));
    vector<vector<bool>> flag2(row, vector<bool>(col));

    // Pacific dfs from north and left
    for (int i = 0; i < row; i++)
    {
        checkFlow(heights, flag1, i, 0);
    }
    for (int i = 0; i < col; i++)
    {
        checkFlow(heights, flag1, 0, i);
    }

    // Atlantic dfs from east and south
    for (int i = 0; i < row; i++)
    {
        checkFlow(heights, flag2, i, col - 1);
    }
    for (int i = 0; i < col - 1; i++)
    {
        checkFlow(heights, flag2, row - 1, i);
    }

    // dono mein jo common mtlb wha se ocean pahuch skte h to push them to vector
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (flag1[i][j] && flag2[i][j])
                ans.push_back({i, j});
        }
    }

    return ans;
}

int main()
{

    return 0;
}