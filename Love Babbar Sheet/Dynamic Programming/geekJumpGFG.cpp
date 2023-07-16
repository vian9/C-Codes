// Link : https://practice.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
// Time Complexity : O()
// Approach-> Bs dhyan rkho array k size ka and conditions and base cases ka

// Base case ko dp[0] mein sahi se dalna...dp array k size sahi se lena and recurrence relation sahi se likhna

// height i to j k energy is abs(i-j)
// Greedy nhi lga skte as harr jagah ye optimal nhi dega and also constraints are small
// n tells ki 0 to n-1 kitne kaam m aa skte ho...so n size k dp array

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation
int helper(vector<int> &height, int n)
{
    // for dp[0] = 0 rhega as 0 and 1 k liye 1 hi possible step h
    int prev2 = 0;
    int prev = 0;
    // index is 0 to n-1 but n is 1 to n
    // i = 1 se issliye taaki min 1 se tm lekr jaoge to n = 1 pr 0 return ho and n>1 pr as usual process
    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(height[i] - height[i - 2]);
        curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int minimumEnergy(vector<int> &height, int n)
{
    return helper(height, n);
}

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
                left = dp[i - j] + abs(height[i] - height[i - j]);
            dp[i] = min(dp[i], left);
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
int helper(vector<int> &height, vector<int> &dp, int n, int ind)
{
    if (ind == 0)
    {
        dp[ind] = 0;
        return dp[ind];
    }

    if (dp[ind] != -1)
        return dp[ind];

    // i = 1 k liye yha se call jayega
    int left = helper(height, dp, n - 1, ind - 1) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = helper(height, dp, n - 2, ind - 2) + abs(height[ind] - height[ind - 2]);
    return dp[ind] = min(left, right);
}

int minimumEnergy(vector<int> &height, int n)
{
    // index is 0 to n-1 but n is 1 to n
    vector<int> dp(n, -1);
    return helper(height, dp, n, n - 1);
}

// Recursive - Top Down approach
// index daldo 0 to n-1...jaise hi 0 pr reach kiye mtlb pahuch gye
int helper(vector<int> &height, int n, int ind)
{
    if (ind == 0)
    {
        return 0;
    }

    int left = helper(height, n - 1, ind - 1) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = helper(height, n - 2, ind - 2) + abs(height[ind] - height[ind - 2]);
    return min(left, right);
}

int minimumEnergy(vector<int> &height, int n)
{
    // index is 0 to n-1 but n is 1 to n
    return helper(height, n, n - 1);
}

int main()
{

    return 0;
}