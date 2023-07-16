// Link : https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633
// Time Complexity : O(n*m) SC:O(n)
// Approach-> Given arr[i] can be equal to 0 bhi to usse case ke hisab tk hmesa ind == 0 tk jayega naki bs sum == 0 tk and 0 ko consider krna hoga
// Baaki same as pick not pick and isme count lerhe

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int mod = 1000000007;

// Space Optimisation Approach - Bottom Up ....hum count krte jayega pick or not pick se from begin
// dp[ind][sum] tells us ki ind and sum pr kitna count of sets possible h
int perfectSum(int arr[], int n, int sum)
{
    // Just for convenience to pass
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(arr[i]);
    }
    // 2 parameter h to 2D array....prev ko save krenge
    vector<int> prev(sum + 1, 0);
    // it won't take nums[i] = 0
    // if (sum == 0)
    //     return 1;
    // Agar nums[0] bhi consider hoga to hmesa 0 ind tk chlna h
    // Hum base case of memoisation ko save kr lena h
    // Target == 0 par sbme 0 return hoga

    prev[0] = 1;

    // Ab nums[0] == 0 and sum bhi 0 toh pick and not pick k sth 2 case
    if (nums[0] == 0)
        prev[0] = 2;
    // Agar sum exist krrha h to wo true hoga...tbhi jb upar k case consider nhi hua wrna usko 1 krdega
    else if (nums[0] <= sum)
        prev[nums[0]] = 1;

    // 2 nested for loops as 2 parameters....will move from 0 to n-1 opposite of memoisation...will start from ind = 1 as 0 krlia save
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(sum + 1, 0);
        // this is for target 0
        curr[0] = 1;
        for (int sumCurr = 0; sumCurr <= sum; sumCurr++)
        {
            // Not Take
            int notTake = prev[sumCurr];
            // Take
            int take = 0;
            if (nums[ind] <= sumCurr)
                take = prev[sumCurr - nums[ind]];
            // Dono ka sum return hoga
            curr[sumCurr] = (take + notTake) % mod;
        }
        prev = curr;
    }
    // Jo memoisation mein call wo return hoga
    return prev[sum];
}

// Tabulation Approach - Bottom Up ....hum count krte jayega pick or not pick se from begin
// dp[ind][sum] tells us ki ind and sum pr kitna count of sets possible h
int perfectSum(int arr[], int n, int sum)
{
    // Just for convenience to pass
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(arr[i]);
    }
    // 2 parameter h to 2D array
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    // it won't take nums[i] = 0
    // if (sum == 0)
    //     return 1;
    // Agar nums[0] bhi consider hoga to hmesa 0 ind tk chlna h
    // Hum base case of memoisation ko save kr lena h
    // Target == 0 par sbme 0 return hoga
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    // Ab nums[0] == 0 and sum bhi 0 toh pick and not pick k sth 2 case
    if (nums[0] == 0)
        dp[0][0] = 2;
    // Agar sum exist krrha h to wo true hoga...tbhi jb upar k case consider nhi hua wrna usko 1 krdega
    else if (nums[0] <= sum)
        dp[0][nums[0]] = 1;

    // 2 nested for loops as 2 parameters....will move from 0 to n-1 opposite of memoisation....will start from ind = 1 as 0 krlia save
    for (int ind = 1; ind < n; ind++)
    {
        for (int sumCurr = 0; sumCurr <= sum; sumCurr++)
        {
            // Not Take
            int notTake = dp[ind - 1][sumCurr];
            // Take
            int take = 0;
            if (nums[ind] <= sumCurr)
                take = dp[ind - 1][sumCurr - nums[ind]];
            // Dono ka sum return hoga
            dp[ind][sumCurr] = (take + notTake) % mod;
        }
    }
    // Jo memoisation mein call wo return hoga
    return dp[n - 1][sum];
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
    return dp[ind][sum] = (take + notTake) % mod;
}

int perfectSum(int arr[], int n, int sum)
{
    // Just for convenience to pass
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(arr[i]);
    }
    // 2 parameter h to 2D array
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return sumHelper(nums, n, sum, n - 1, dp);
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
    return (take + notTake) % mod;
}

int perfectSum(int arr[], int n, int sum)
{
    // Just for convenience to pass
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(arr[i]);
    }

    return sumHelper(nums, n, sum, n - 1);
}

int main()
{

    return 0;
}