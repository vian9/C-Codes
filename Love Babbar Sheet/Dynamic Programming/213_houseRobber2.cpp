// Link : https://leetcode.com/problems/house-robber-ii/
// Time Complexity : O(n)
// Approach-> DP mein save kia and phir iterative krdia and jo max aaya wo return
// Condition bas yhi h ki first and last ka nhi hoga sth mein....to uske liye ek case lelo 0 and n-1 nhi k sth aur
// dusra 0 nhi and n-1 k sth

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// EK hi loop mein....100% faster DP
int rob(vector<int> &nums)
{
    int prev2 = 0;
    int prev = nums[0];
    int nonPrev2 = 0;
    int nonPrev = 0;
    int n = nums.size();
    for (int i = 1; i < nums.size(); i++)
    {
        if (i != n - 1)
        {
            int a = nums[i] + prev2;
            int b = 0 + prev;
            int curr = max(a, b);

            prev2 = prev;
            prev = curr;
        }
        int c = nums[i] + nonPrev2;
        int d = 0 + nonPrev;
        int nonCurr = max(c, d);

        nonPrev2 = nonPrev;
        nonPrev = nonCurr;
    }
    return max(prev, nonPrev);
}

// DP - Space O(1)....100% faster....last 2 ka output k kaam h jo hum 2 variables mein save krdiye
int rob(vector<int> &nums)
{
    int prev2 = 0;
    int prev = nums[0];
    for (int i = 1; i < nums.size() - 1; i++)
    {
        int a = nums[i] + prev2;
        int b = 0 + prev;
        int curr = max(a, b);
        prev2 = prev;
        prev = curr;
    }
    int ans1 = prev;
    prev2 = 0;
    prev = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int a = nums[i] + prev2;
        int b = 0 + prev;
        int curr = max(a, b);
        prev2 = prev;
        prev = curr;
    }
    int ans2 = prev;
    return max(ans1, ans2);
}

// Dynamic Programming - Phle 2 save kia and phir iterative
int rob(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return nums[0];
    }
    // Kya kia ki phle 0 ko lekr nikala and n-1 ko htakr
    vector<int> ans(nums.size() - 1, -1);
    ans[0] = nums[0];
    for (int i = 1; i < nums.size() - 1; i++)
    {
        int a = nums[i];
        if (i > 1)
            a += ans[i - 2];
        int b = 0 + ans[i - 1];
        ans[i] = max(a, b);
    }
    // Ab 0 ko nhi include kia and n-1 ko kia
    vector<int> ans2(nums.size() - 1, -1);
    ans[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int a = nums[i];
        if (i > 1)
            a += ans2[i - 2];
        int b = 0 + ans2[i - 1];
        ans[i] = max(a, b);
    }
    return max(ans[ans.size() - 1], ans2[ans2.size() - 1]);
}

// Memoisation - Time : O(n) + Space : O(2N)
int rob(vector<int> &nums)
{
    int index = nums.size();
    // Agar ek hi element k array hua toh
    if (index == 1)
    {
        return nums[index - 1];
    }
    vector<int> ans(index, -1);
    // Phla case agar 0 liya toh n-1 nhi lenge aur n-1 lia to 0 nhi
    int a = robHouse(nums, ans, index - 1, 1);
    int b = robHouse(nums, ans, index - 2, 0);
    return max(a, b);
}

// n-1 is startIndex and 0 is endIndex waise jaarhe h
int robHouse(vector<int> &nums, vector<int> &ans, int startIndex, int endIndex)
{
    if (startIndex < 0 || endIndex > startIndex)
    {
        return 0;
    }
    // Check ki save kia h ans
    if (ans[startIndex] != -1)
    {
        return ans[startIndex];
    }
    // Pick or not pick....Save and return
    int a = nums[startIndex] + robHouse(nums, ans, startIndex - 2);
    int b = 0 + robHouse(nums, ans, startIndex - 1);
    return ans[startIndex] = max(a, b);
}

// Recursive- Exponential.....kya kia ki hume pick or not pick krna h aur usme agar pick toh n-2 ko jayega and not pick par n-1 par
int robHouse(vector<int> &nums, int startIndexx, int endIndexx)
{
    if (startIndexx < 0 || endIndexx > startIndexx)
    {
        return 0;
    }

    int a = nums[startIndexx] + robHouse(nums, startIndexx - 2);
    int b = 0 + robHouse(nums, startIndexx - 1);
    return max(a, b);
}

int rob(vector<int> &nums)
{
    int index = nums.size();
    if (index == 1)
    {
        return nums[index - 1];
    }
    int a = robHouse(nums, index - 1, 1);
    int b = robHouse(nums, index - 2, 0);
}

int main()
{

    return 0;
}