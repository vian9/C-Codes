// Link : https://leetcode.com/problems/pascals-triangle-ii/
// Time Complexity : O(n) SC:O(n)
// Approach-> Bs yeh dhyan rkhna hai kha se rows lerhe h kisko add krke and kha tk

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Iterative Space Optimisation Approach
vector<int> getRow(int rowIndex)
{
    // Prev row k hi use h to prev and curr 2 row maintain krlia
    vector<int> prev;
    // First row is 1
    prev.push_back({1});
    for (int i = 1; i <= rowIndex; i++)
    {
        vector<int> curr;
        // 1st element is always 1
        curr.push_back(1);
        for (int j = 1; j < i; j++)
        {
            // Last and second last element k sum hoga
            int sum = prev[j - 1] + prev[j];
            curr.push_back(sum);
        }
        curr.push_back(1);
        prev = curr;
    }
    return prev;
}

// Iterative Tabulation Approach
vector<int> getRow(int rowIndex)
{
    vector<vector<int>> row;
    // First row is 1
    row.push_back({1});
    for (int i = 1; i <= rowIndex; i++)
    {
        vector<int> ans;
        // 1st element is always 1
        ans.push_back(1);
        for (int j = 1; j < i; j++)
        {
            // Last and second last element k sum hoga
            int sum = row[i - 1][j - 1] + row[i - 1][j];
            ans.push_back(sum);
        }
        ans.push_back(1);
        row.push_back(ans);
    }
    return row[rowIndex];
}

int main()
{

    return 0;
}