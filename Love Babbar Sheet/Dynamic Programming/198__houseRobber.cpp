// Link : https://leetcode.com/problems/house-robber/
// Time Complexity : O(n)
// Approach-> DP mein save kia and phir iterative krdia and jo max aaya wo return

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Dynamic Programming - Phle 2 save kia and phir iterative
int rob(vector<int> &nums)
{
    vector<int> ans(nums.size(), -1);
    ans[0] = nums[0];
    int neg = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int a = nums[i];
        if (i > 1)
            a += ans[i - 2];
        int b = 0 + ans[i - 1];
        ans[i] = max(a, b);
    }

    return ans[ans.size() - 1];
}

// DP - Space O(1)....100% faster....last 2 ka output k kaam h jo hum 2 variables mein save krdiye
int rob(vector<int> &nums)
{
    int prev2 = 0;
    int prev = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int a = nums[i] + prev2;
        int b = 0 + prev;
        int curr = max(a, b);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

// Memoisation - Time : O(n) + Space : O(2N)
int rob(vector<int> &nums)
{
    int index = nums.size();
    vector<int> ans(index, -1);
    return robHouse(nums, ans, index - 1);
}

int robHouse(vector<int> &nums, vector<int> &ans, int index)
{
    if (index < 0)
    {
        return 0;
    }
    // Check ki save kia h ans
    if (ans[index] != -1)
    {
        return ans[index];
    }
    // Pick or not pick....Save and return
    int a = nums[index] + robHouse(nums, index - 2);
    int b = 0 + robHouse(nums, index - 1);
    return ans[index] = max(a, b);
}

// Recursive- Exponential.....kya kia ki hume pick or not pick krna h aur usme agar pick toh n-2 ko jayega and not pick par n-1 par
int robHouse(vector<int> &nums, int index)
{
    if (index < 0)
    {
        return 0;
    }

    int a = nums[index] + robHouse(nums, index - 2);
    int b = 0 + robHouse(nums, index - 1);
    return max(a, b);
}

int rob(vector<int> &nums)
{
    int index = nums.size();
    return robHouse(nums, index - 1);
}

int main()
{

    return 0;
}