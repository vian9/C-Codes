// Link : https://leetcode.com/problems/house-robber/
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/
// Time Complexity : O(n) ...SC : O(1)
// Approach->  Either pick a element then uh can pick ind -2 or not pick bs whi h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// calculate the maximum sum with out adjacent
// Space Optimisation - Tabulation
int rob(vector<int> &nums)
{
    // base Case jo tha usko values bhardia...2 values tak chahiye
    int prev2 = 0;
    int prev = nums[0]; // dp[0]
    int n = nums.size();
    // Ab loop chalado
    for (int i = 1; i < n; i++)
    {
        // Jo recursive calls tha wha bs values bhardo
        // Pick
        int pick = nums[i];
        if (i - 2 >= 0)
            pick += prev2;
        // Unpick
        int unPick = 0;
        if (i - 1 >= 0)
            unPick += prev;
        int curr = max(pick, unPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// calculate the maximum sum with out adjacent
// Space Optimisation - Tabulation for GFG
int FindMaxSum(int arr[], int n)
{
    // base Case jo tha usko values bhardia...2 values tak chahiye
    int prev2 = 0;
    int prev = arr[0]; // dp[0]
    // Ab loop chalado
    for (int i = 1; i < n; i++)
    {
        // Jo recursive calls tha wha bs values bhardo
        // Pick
        int pick = arr[i];
        if (i - 2 >= 0)
            pick += prev2;
        // Unpick
        int unPick = 0;
        if (i - 1 >= 0)
            unPick += prev;
        int curr = max(pick, unPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// Tabulation - Bottom Up
int maxSum(vector<int> &nums, int n, vector<int> &dp)
{
    // base Case jo tha usko values bhardia
    dp[0] = nums[0];

    // Ab loop chalado
    for (int i = 1; i < n; i++)
    {
        // Jo recursive calls tha wha bs values bhardo
        // Pick
        int pick = nums[i];
        if (i - 2 >= 0)
            pick += dp[i - 2];
        // Unpick
        int unPick = 0;
        if (i - 1 >= 0)
            unPick += dp[i - 1];
        // Ab update krdia
        dp[i] = max(pick, unPick);
    }
    // Return jisse memoisation pr call horha tha
    return dp[n - 1];
}

// calculate the maximum sum with out adjacent
int rob(vector<int> &nums)
{
    // n-1 tk chahiye to n size ka
    vector<int> dp(n, -1);
    int n = nums.size();
    return maxSum(nums, n, dp);
}

// Memoisation - Top Down...yha n-1 se 0 mein break krrhe h and n-1 mein maxSum to 0 hai
int maxSum(vector<int> &nums, int n, int ind, vector<int> &dp)
{
    // Base Case
    if (ind == 0)
        return nums[0];
    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];
    // Pick
    int pick = nums[ind] + maxSum(nums, n, ind - 2, dp);
    // Unpick
    int unPick = 0 + maxSum(nums, n, ind - 1, dp);
    return dp[ind] = max(pick, unPick);
}

// calculate the maximum sum with out adjacent
int rob(vector<int> &nums)
{
    // n-1 tk chahiye to n size ka
    vector<int> dp(n, -1);
    int n = nums.size();
    return maxSum(nums, n, n - 1, dp);
}

// Memoisation - Top Down....tm 0 index se n-1 tk jao and finally 0 wla index mein rhega 0 to n-1 ka max Sum
int maxSum(vector<int> &nums, int n, int ind, vector<int> &dp)
{
    // Base Case
    if (ind == n - 1)
        return nums[n - 1];
    if (ind > n - 1)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];
    // Pick
    int pick = nums[ind] + maxSum(nums, n, ind + 2, dp);
    // Unpick
    int unPick = 0 + maxSum(nums, n, ind + 1, dp);
    return dp[ind] = max(pick, unPick);
}

// calculate the maximum sum with out adjacent
int rob(vector<int> &nums)
{
    // n-1 tk chahiye to n size ka
    vector<int> dp(n, -1);
    int n = nums.size();
    return maxSum(nums, n, 0, dp);
}

// Recursive Solution -Top Down - N-1 se pick kro and unpick kro and uske hisab se add kro
int maxSum(vector<int> &nums, int n, int ind)
{
    // Base Case
    if (ind == 0)
        return nums[0];
    if (ind < 0)
        return 0;

    // Pick
    int pick = nums[ind] + maxSum(nums, n, ind - 2);
    // Unpick
    int unPick = 0 + maxSum(nums, n, ind - 1);
    return max(pick, unPick);
}

// calculate the maximum sum with out adjacent
int rob(vector<int> &nums)
{
    return maxSum(nums, n, n - 1);
}

int main()
{

    return 0;
}