// Link : https://leetcode.com/problems/climbing-stairs/
// Time Complexity : O(n)
// Approach-> Bas base case yhi h n<=1 k liye 1 hoga aur return hoga n-1 and n-2 ka sum

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// n steps tk hum kitna ways m pahuch skte h....0 k liye 0 steps hi rhega
// standing at 0 there is only 1 way

// DP - O(1) Space....Bottom Up Approach....Iterative
int climbStairs(int n)
{
    // if (n == 1)
    //     return 1;
    // if (n == 2)
    //     return 2;
    // for zero and 1 stairs
    int prev = 1;
    int prev2 = 1;
    for (int i = 2; i < n + 1; i++)
    {
        int curr = prev + prev2;
        prev = prev2;
        prev2 = curr;
    }
    return prev2;
}

// DP - Space O(n)...Bottom up Approach...Iterative
int climbStairs(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 2];
    }
    return dp[n];
}

// Recursive - TLE...Top Down Approach...Recursive
int climbStairs(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return climbStairs(n - 1) + climbStairs(n - 2);
}

// Memoisation....Top Down Approach...Recursive
int climbStairs(int n)
{
    // 0 to n save krna h toh size will be n+1
    vector<int> dp(n + 1, -1);
    return memHelper(dp, n);
}

int memHelper(vector<int> &dp, int n)
{
    // Base Case
    if (n <= 1)
    {
        // dp[n] = 1;
        // return dp[n];
        return 1;
    }
    // Check if mem exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Save in dp and return
    return dp[n] = memHelper(dp, n - 1) + memHelper(dp, n - 2);
}

int main()
{

    return 0;
}