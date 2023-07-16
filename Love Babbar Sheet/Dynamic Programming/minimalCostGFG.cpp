// Link : https://practice.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
// Time Complexity : O()
// Approach-> Same as geekJump bs k times ab aagya h lena h....bs loop chlega extra k times to choose minimum

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Tabulation - Bottom Up Approach
int helper(vector<int> &height, vector<int> &dp, int n, int k)
{
    // for dp[0] = 0 rhega as 0 and 1 k liye 1 hi possible step h
    dp[0] = 0;
    // index is 0 to n-1 but n is 1 to n
    for (int i = 1; i < n; i++)
    {
        // Ab harr k liye check krke dekhenge kaun h minimum and update
        dp[i] = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            int left = INT_MAX;
            if (i - j >= 0)
                left = helper(height, dp, n, i - j, k) + abs(height[i] - height[i - j]);
            dp[ind] = min(dp[i], left);
        }
    }
    return dp[n - 1];
}

int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n, -1);
    return helper(height, dp, n, k);
}

// Memoisation - Top Down Approach
int helper(vector<int> &height, vector<int> &dp, int n, int ind, int k)
{
    if (ind == 0)
    {
        dp[ind] = 0;
        return dp[ind];
    }

    if (dp[ind] != -1)
        return dp[ind];

    // ind = 1 k liye yha se call jayega and for every k jayega
    dp[ind] = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        // Ab harr k liye check krke dekhenge kaun h minimum and update
        int left = INT_MAX;
        if (ind - j >= 0)
            left = helper(height, dp, n, ind - j, k) + abs(height[ind] - height[ind - j]);
        dp[ind] = min(dp[ind], left);
    }
    return dp[ind];
}

int minimizeCost(vector<int> &height, int n, int k)
{
    // index is 0 to n-1 but n is 1 to n
    vector<int> dp(n, -1);
    return helper(height, dp, n, n - 1, k);
}

// Recursive - Top Down approach
// index daldo 0 to n-1...jaise hi 0 pr reach kiye mtlb pahuch gye
int helper(vector<int> &height, int n, int ind, int k)
{
    if (ind == 0)
    {
        return 0;
    }

    int curr = INT_MAX;
    // Ab harr index par 1 to k tk ka steps k possibility uska minimum lenge
    for (int j = 1; j <= k; j++)
    {
        int left = INT_MAX;
        if (ind - j >= 0)
            left = helper(height, n, ind - j, k) + abs(height[ind] - height[ind - j]);
        curr = min(dp[ind], left);
    }
    return curr;
}

int minimizeCost(vector<int> &height, int n, int k)
{
    // index is 0 to n-1 but n is 1 to n
    return helper(height, n, n - 1, k);
}

int main()
{

    return 0;
}