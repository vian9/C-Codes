// Link : https://leetcode.com/problems/pascals-triangle/
// Time Complexity : O(n2)
// Approach-> Dp

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Iterative - O(n^2)
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> row;
    row.push_back({1});
    for (int i = 1; i < numRows; i++)
    {
        // Phle 1 pushkrdia and baad m
        vector<int> rows(i + 1, 1);
        for (int j = 1; j <= i - 1; j++)
        {
            // Ab jo sum h wo last 2 ka sum h
            int sum = row[i - 1][j - 1] + row[i - 1][j];
            rows.push_back(sum);
        }
        row.push_back(rows);
    }
    return row;
}

int main()
{

    return 0;
}