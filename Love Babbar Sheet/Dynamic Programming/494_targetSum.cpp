// Link : https://leetcode.com/problems/target-sum/
// Time Complexity : O(n*m) SC: O(n)
// Approach-> Similar to Partition with given difference target...yha 2 mein divide kro such tha ek mein + lgarhe and ek mein - such that diff is target
// nums[i] can be 0 toh whi PerfectSumProbGFG ke jaisa agar ind 0 tk jana hoga and sum == 0 and nums[0] == 0 toh 2 set return hoga
// s1 nikalo lo and agar uska count possible h to s2 apne aap nikal jayega usse set mein to s1 ka count nikal lo
// s1 + s2 = sum, target = s1 - s2 => s1 = (target + sum )/ 2....Agar ye possible horha h to hum s2 bhi ho jayega to iska count nikalo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Approach - Bottom Up ....hum count krte jayega pick or not pick se from begin
// dp[ind][sum] tells us ki ind and sum pr kitna count of sets possible h
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    // Agar s1 ko peeche s2 ko aage to negative target generate krloge to usko bs -1 se mulptily krdo as array -ve size k nhi declare hoga
    if (target < 0)
        target = -1 * target;
    // S1 nikalne k formula
    int s1 = target + sum;
    if (s1 % 2 != 0)
        return 0;
    s1 = s1 / 2;
    // 2 parameter h to 2D numsay....prev ko save krenge
    vector<int> prev(s1 + 1, 0);
    // it won't take nums[i] = 0
    // if (s1 == 0)
    //     return 1;
    // Agar nums[0] bhi consider hoga to hmesa 0 ind tk chlna h
    // Hum base case of memoisation ko save kr lena h
    // Target == 0 par sbme 0 return hoga

    prev[0] = 1;

    // Ab nums[0] == 0 and s1 bhi 0 toh pick and not pick k sth 2 case
    if (nums[0] == 0)
        prev[0] = 2;
    // Agar s1 exist krrha h to wo true hoga...tbhi jb upar k case consider nhi hua wrna usko 1 krdega
    else if (nums[0] <= s1)
        prev[nums[0]] = 1;

    // 2 nested for loops as 2 parameters....will move from 0 to n-1 opposite of memoisation...will start from ind = 1 as 0 krlia save
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(s1 + 1, 0);
        // this is for target 0
        curr[0] = 1;
        for (int sumCurr = 0; sumCurr <= s1; sumCurr++)
        {
            // Not Take
            int notTake = prev[sumCurr];
            // Take
            int take = 0;
            if (nums[ind] <= sumCurr)
                take = prev[sumCurr - nums[ind]];
            // Dono ka s1 return hoga
            curr[sumCurr] = (take + notTake);
        }
        prev = curr;
    }
    // Jo memoisation mein call wo return hoga
    return prev[s1];
}

// Tabulation Approach - Bottom Up ....hum count krte jayega pick or not pick se from begin
// dp[ind][sum] tells us ki ind and sum i.e. s1 pr kitna count of sets possible h
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    // Agar s1 ko peeche s2 ko aage to negative target generate krloge to usko bs -1 se mulptily krdo as array -ve size k nhi declare hoga
    if (target < 0)
        target = -1 * target;
    // S1 nikalne k formula
    int s1 = target + sum;
    if (s1 % 2 != 0)
        return 0;
    s1 = s1 / 2;
    // 2 parameter h to 2D numsay...sum is s1 toh usse +1 krke size lenge...imp ki 0 default value rkho yha na ki -1 for tabulation
    vector<vector<int>> dp(n, vector<int>(s1 + 1, 0));
    // it won't take nums[i] = 0
    // if (s1 == 0)
    //     return 1;
    // Agar nums[0] bhi consider hoga to hmesa 0 ind tk chlna h
    // Hum base case of memoisation ko save kr lena h
    // Target == 0 par sbme 0 return hoga
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    // Ab nums[0] == 0 and s1 bhi 0 toh pick and not pick k sth 2 case
    if (nums[0] == 0)
        dp[0][0] = 2;
    // Agar s1 exist krrha h to wo true hoga...tbhi jb upar k case consider nhi hua wrna usko 1 krdega
    else if (nums[0] <= s1)
        dp[0][nums[0]] = 1;

    // 2 nested for loops as 2 parameters....will move from 0 to n-1 opposite of memoisation....will start from ind = 1 as 0 krlia save
    for (int ind = 1; ind < n; ind++)
    {
        for (int sumCurr = 0; sumCurr <= s1; sumCurr++)
        {
            // Not Take
            int notTake = dp[ind - 1][sumCurr];
            // Take
            int take = 0;
            if (nums[ind] <= sumCurr)
                take = dp[ind - 1][sumCurr - nums[ind]];
            // Dono ka s1 return hoga
            dp[ind][sumCurr] = (take + notTake);
        }
    }
    // Jo memoisation mein call wo return hoga
    return dp[n - 1][s1];
}

// Memoisation Approach - Top Down ....hum count krte jayega pick or not pick se
// dp[ind][sum] tells us ki ind and sum pr kitna count of sets possible h
int sumHelper(vector<int> &nums, int n, int sum, int ind, vector<vector<int>> &dp)
{
    // it won't take nums[i] = 0
    // if (sum == 0)
    //     return 1;
    // Agar nums[0] bhi consider hoga to hmesa 0 ind tk chlna h
    if (ind == 0)
    {
        // Agar sum 0 ho and nums[ind] bhi 0 ho to pick kroge farq nhi pdega but 2 alag alag sets bnega
        if (sum == 0 && nums[ind] == 0)
        {
            return dp[ind][sum] = 2;
        }
        // sum 0 ho jaye ya sum==nums[ind] dono mein 1 hi set bnega
        else if (sum == 0 || sum == nums[ind])
            return dp[ind][sum] = 1;
        else
            return dp[ind][sum] = 0;
    }

    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    // Not Take
    int notTake = sumHelper(nums, n, sum, ind - 1, dp);
    // Take
    int take = 0;
    if (nums[ind] <= sum)
        take = sumHelper(nums, n, sum - nums[ind], ind - 1, dp);
    // Dono ka sum return hoga
    return dp[ind][sum] = (take + notTake);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    // Agar s1 ko peeche s2 ko aage to negative target generate krloge to usko bs -1 se mulptily krdo as array -ve size k nhi declare hoga
    if (target < 0)
        target = -1 * target;
    // S1 nikalne k formula
    int s1 = target + sum;
    if (s1 % 2 != 0)
        return 0;
    s1 = s1 / 2;
    // 2 parameter h to 2D numsay...sum is s1 toh usse +1 krke size lenge
    vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));
    return sumHelper(nums, n, s1, n - 1, dp);
}

// Recursive Approach - Top Down ....hum count krte jayega pick or not pick se
int sumHelper(vector<int> &nums, int n, int sum, int ind)
{
    // it won't take nums[i] = 0
    // if (sum == 0)
    //     return 1;
    // Agar nums[0] bhi consider hoga to hmesa 0 ind tk chlna h
    if (ind == 0)
    {
        // Agar sum 0 ho and nums[ind] bhi 0 ho to pick kroge farq nhi pdega but 2 alag alag sets bnega
        if (sum == 0 && nums[ind] == 0)
        {
            return 2;
        }
        // sum 0 ho jaye ya sum==nums[ind] dono mein 1 hi set bnega
        else if (sum == 0 || sum == nums[ind])
            return 1;
        else
            return 0;
    }

    // Not Take
    int notTake = sumHelper(nums, n, sum, ind - 1);
    // Take
    int take = 0;
    if (nums[ind] <= sum)
        take = sumHelper(nums, n, sum - nums[ind], ind - 1);
    // Dono ka sum return hoga
    return (take + notTake);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    // S1 nikalne k formula
    int s1 = target + sum;
    if (s1 % 2 != 0)
        return 0;
    s1 = s1 / 2;
    return sumHelper(nums, n, s1, n - 1);
}

int main()
{

    return 0;
}