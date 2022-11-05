#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int> &curr, int row, int col)
{
    for (int i = 0; i <= row - 1; i++)
    {
        if (curr[i] - 1 == col || ((abs(curr[i] - 1 - col) == 1) && (abs(i - row) == 1)))
        {
            return false;
        }
    }
    return true;
}

int helper(int row, int n, vector<int> &temp, vector<vector<int>> &ans)
{
    int count = 0;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(temp, row, col))
        {
            temp[row] = col + 1;
            if (row == n - 1)
            {
                ans.push_back(temp);
                count++;
            }
            else
            {
                helper(row + 1, n, temp, ans);
            }
        }
    }
    return count;
}

void nQueen(int n)
{
    // code here
    vector<int> temp(n, -1);
    vector<vector<int>> ans;

    cout << helper(0, n, temp, ans) << endl;
}

int main()
{
    nQueen(6);

    return 0;
}