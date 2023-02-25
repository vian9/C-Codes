// Link : https://leetcode.com/problems/zigzag-conversion/
// Time Complexity : O(n)
// Approach-> Just jaise hi aage jaye flag se aage peeche krwa lo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    vector<vector<char>> ans(numRows);
    int j = 0;
    bool flag = true;
    for (int i = 0; i < s.length(); i++)
    {
        ans[j].push_back(s[i]);
        if (flag)
        {
            j++;
        }
        else
        {
            j--;
        }
        if (j == numRows)
        {
            flag = false;
            j -= 2;
        }
        else if (j == -1)
        {
            flag = true;
            j += 2;
        }
    }
    string st;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            st.push_back(ans[i][j]);
        }
    }
    return st;
}

int main()
{

    return 0;
}