// Link : https://leetcode.com/problems/jump-game/
// Time Complexity : O(n)
// Approach-> DP lagrhaa tha ki lgega but greedy due to constraints

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Greedy - DP nhi lagrha and constraints bada ho tbc...here constraints were in power of e
bool canJump(vector<int> &nums)
{
    if (nums.size() <= 1)
        return true;
    int n = nums.size();
    // current max Dist
    int maxDist = nums[0];
    for (int i = 1; i < n; i++)
    {
        // Agar max dist se i jada aage badh gya mtlb wahan tk pahuch nhi skte
        if (i > maxDist)
            return false;
        // Update max dist
        maxDist = max(maxDist, i + nums[i]);
    }
    return true;
}

// Memoisation....O(N*m) time....taking a lot of time and dp bhi nhi lag paarha it's taking O(n2) time
bool canJumpCheck(vector<int> &nums, int j, vector<int> &dp)
{
    int n = nums.size();
    // Agar end pr aagye toh true
    if (j >= n)
        return true;

    if (dp[j] != -1)
    {
        return dp[j] == 1 ? true : false;
    }

    // Ab we will call func from nums[j-1] to 0 aur agar kahin bhi end mein aagya toh return true
    // j-1 issliiye kuuki we are starting from 1 and array is 0 indexed based
    for (int i = nums[j - 1]; i > 0; --i)
    {
        bool check = canJumpCheck(nums, j + i, dp);
        if (check)
        {
            dp[j] = 1;
            return true;
        }
        else
        {
            dp[j] = 0;
        }
    }

    return false;
}

bool canJump(vector<int> &nums)
{
    if (nums.size() <= 1)
        return true;
    // 1D Array kuuki kisi ek data sample k liye at a moment single variable data chahiye ki wahan se end tk jaa skte h
    vector<int> dp(nums.size() + 1, -1);
    return canJumpCheck(nums, 1, dp);
}

// Recursive - TLE
bool canJumpCheck(vector<int> &nums, int j)
{
    int n = nums.size();
    // Agar end pr aagye toh true
    if (j >= n)
        return true;

    // Ab we will call func from nums[j-1] to 0 aur agar kahin bhi end mein aagya toh return true
    // j-1 issliiye kuuki we are starting from 1 and array is 0 indexed based
    for (int i = nums[j - 1]; i > 0; --i)
    {
        bool check = canJumpCheck(nums, j + i);
        if (check)
            return true;
    }

    return false;
}

bool canJump(vector<int> &nums)
{
    if (nums.size() <= 1)
        return true;
    return canJumpCheck(nums, 1);
}

int main()
{

    return 0;
}