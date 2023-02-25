// Link : https://leetcode.com/problems/n-th-tribonacci-number/
// Time Complexity : O(n) Time and O(1) Space
// Approach-> DP with 3 variables.....ab usko store krte gye and return....similar to fibonacci

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Recursive - Top Down
int tribonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (n == 2)
    {
        return 1;
    }
    // 0th index se chalrha
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

// Memoisation - Top Down Approach
int tribonacciHelper(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (n == 2)
    {
        return 1;
    }
    if (ans != -1)
    {
        return dp[n];
    }
    return dp[n] = tribonacciHelper(n - 1, dp) + tribonacciHelper(n - 2, dp) + tribonacciHelper(n - 3, dp);
}

int tribonacci(int n)
{
    vector<int> dp(n + 1, -1);
    // 0th index se chalrha
    return tribonacciHelper(n, dp);
}

// DP - Bottom Up Approach
int tribonacciHelper(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (n == 2)
    {
        return 1;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int tribonacci(int n)
{
    vector<int> dp(n + 1, -1);
    // 0th index se chalrha
    return tribonacciHelper(n, dp);
}

int tribonacci(int n)
{
    int prev3 = 0;
    int prev2 = 1;
    int prev = 1;
    if (n < 1)
        return prev3;
    for (int i = 3; i < n + 1; i++)
    {
        int curr = prev + prev2 + prev3;
        prev3 = prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{

    return 0;
}