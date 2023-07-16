// Link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int ans = 0;
int helper(int n, vector<int> &nums, int ind, int lastDel, vector<vector<int>> &dp)
{
    if (ind >= n)
    {
        return 0;
    }

    if (dp[ind][lastDel] != -1)
        return dp[ind][lastDel];
    int curr = 0;
    if (lastDel)
    {
        if (nums[ind] == 1)
        {
            curr = 1 + helper(n, nums, ind + 1, lastDel, dp);
            ans = max(curr, ans);
        }
        else
        {
            curr = 0;
            ans = max(curr, ans);
        }
    }
    else
    {
        if (nums[ind] == 1)
        {
            curr = 1 + helper(n, nums, ind + 1, lastDel, dp);
            ans = max(curr, ans);
        }
        else
        {
            // either delete or not delete
            int deletee = 0 + helper(n, nums, ind + 1, !lastDel, dp);
            int nonDelete = 0 + helper(n, nums, ind + 1, lastDel, dp);
            curr = deletee;
            ans = max(max(deletee, nonDelete), ans);
        }
    }
    return dp[ind][lastDel] = curr;
}

int longestSubarray(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    if (sum == n)
        return n - 1;
    // 2 parameters
    vector<vector<int>> dp(n, vector<int>(2, -1));
    helper(n, nums, 0, 0, dp);
    return ans;
}

int longestSubarray(vector<int> &nums)
{
    int zeroCount = 0;
    int start = 0;
    int wini = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            zeroCount++;

        while (zeroCount > 1)
        {
            if (nums[start] == 0)
                zeroCount -= 1;
            start++;
        }
        wini = max(wini, i - start + 1);
    }
    return wini;
}

int main()
{

    return 0;
}