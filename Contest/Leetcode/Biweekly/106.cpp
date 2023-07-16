#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void digits(int n, unordered_map<int, int> &mp)
{
    int num = n;
    while (num > 0)
    {
        int dig = num % 10;
        mp[dig]++;
        num = num / 10;
    }
}

bool isFascinating(int n)
{
    unordered_map<int, int> mp;
    digits(n, mp);
    digits(2 * n, mp);
    digits(3 * n, mp);
    for (int i = 1; i < 10; i++)
    {
        if (mp.count(i) > 0)
        {
            if (mp[i] > 1)
                return false;
            continue;
        }
        else
            return false;
    }
    if (mp.count(0) > 0)
        return false;
    return true;
}

int myHelper(string s, int n, int ind)
{

    int count = 0;
    for (int i = ind; i < n; i++)
    {
        int len = 0;
        vector<int> chars(26, -1);
        bool flag = false;
        chars[s[i] - '0'] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (j - 1 >= 0 && s[j - 1] != s[j])
                len++;
            else if (j - 1 >= 0 && s[j - 1] == s[j])
            {
                if (flag)
                {
                    break;
                }
                else
                {
                    flag = true;
                }
            }
            chars[s[j] - '0']++;
            count = max(count, len);
        }
    }
    return count;
}

int longestSemiRepetitiveSubstring(string s)
{
    if (s.length() <= 2)
    {
        return s.length();
    }

    int n = s.length();
    return myHelper(s, n, 0);
}

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
    }
    return 0;
}

int sumDistance(vector<int> &nums, string s, int d)
{
}

void myHelper(vector<vector<int>> &grid, int n, int m, int row, int col, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = grid[i][j];
            if (i - 1 >= 0)
                dp[i][j] += grid[i - 1][j];
        }
    }
}

vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int val = myHelper(grid, m, n, m - 1, n - 1, dp);
    vector<int> maxi(n, -1);
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = 0; j < m; j++)
        {
            curr = max(curr, dp[i][j]);
        }
        maxi[i] = curr;
    }
    int count = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        int val = floor(i / 2);
        int len = 0;
        start = i;
        for (int j = i; j < n; j++)
        {
            if (maxi[j] <= val)
                len++;
            else
            {
                if (len > count)
                {
                    start = i;
                    end = j;
                }
            }
        }
    }
    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}
