// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countBeautifulPairs(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int digits = (int)log10(nums[i]);
            int a = (int)(nums[i] / pow(10, digits));
            int b = nums[j] % 10;
            if (__gcd(a, b) == 1)
                cnt++;
        }
    }
    return cnt;
}

int helper(vector<int> &nums, int sum, int ind, int parti, int currSum, int k, vector<vector<int>> &dp)
{

    if (sum % k != 0)
        return 0;
    if (ind != nums.size() and parti == k + 1)
        return 0;

    // Base case
    if (ind == nums.size())
    {
        if (parti == k + 1)
            return 1;
        else
            return 0;
    }

    if (dp[ind][parti] != -1)
        return dp[ind][parti];
}

int numberOfGoodSubarraySplits(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    int k = sum;
    if (sum == 0)
        return 0;
    if (sum == 1)
        return 1;
    if (sum % k != 0)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    dp[n][k + 1] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i][k] = 0;
    }

    int currSum = sum;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int parti = k - 1; parti > 0; parti--)
        {
            currSum -= nums[ind];
            int notPick = dp[ind + 1][parti];
            notPick = notPick % mod;
            if (currSum == (sum / k) * parti)
                notPick += dp[ind + 1][parti + 1];

            dp[ind][parti] = notPick % mod;
        }
    }

    return dp[0][1];
}

int mod = 1e9 + 7;

public:
int helper(vector<int> &nums, int sum, int ind, int parti, int currSum, int k, vector<vector<int>> &dp)
{

    if (sum % k != 0)
        return 0;
    if (ind != nums.size() and parti == k + 1)
        return 0;

    // Base case
    if (ind == nums.size())
    {
        if (parti == k + 1)
            return 1;
        else
            return 0;
    }

    if (dp[ind][parti] != -1)
        return dp[ind][parti];
    currSum += nums[ind];

    int notPick = helper(nums, sum, ind + 1, parti, currSum, k, dp);
    notPick = notPick % mod;
    if (currSum == (sum / k) * parti)
        notPick += helper(nums, sum, ind + 1, parti + 1, currSum, k, dp);

    return dp[ind][parti] = notPick % mod;
}

int numberOfGoodSubarraySplits(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    if (sum == 0)
        return 0;
    if (sum == 1)
        return 1;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return helper(nums, sum, 0, 1, 0, sum, dp);
}

int numberOfGoodSubarraySplits(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    int k = sum;
    if (sum == 0)
        return 0;
    if (sum == 1)
        return 1;
    if (sum % k != 0)
        return 0;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 2, vector<int>(sum + 1, 0)));

    for (int i = 0; i < sum + 1; i++)
    {
        dp[n][k + 1][i] = 1;
    }

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int parti = k; parti > 0; parti--)
        {
            for (int z = sum; z >= 0; z--)
            {
                currSum -= nums[ind];
                int notPick = dp[ind + 1][parti];
                notPick = notPick % mod;
                if (currSum == (sum / k) * parti)
                    notPick += dp[ind + 1][parti + 1];
                dp[ind][parti] = notPick % mod;
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return dp[0][1][0];
}

int numberOfGoodSubarraySplits(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if (sum == 0)
        return 0;
    if (sum == 1)
        return 1;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1])
            {
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
                dp[i][j] %= MOD;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= sum; i++)
    {
        if (sum % i == 0)
        {
            cnt += dp[n][i];
            cnt %= MOD;
        }
    }

    return cnt;
}

int numberOfGoodSubarraySplits(vector<int> &nums)
{
    int count1 = 0;
    for (int num : nums)
    {
        count1 += num;
    }

    int result = 0;
    int currSum = 0;
    for (int num : nums)
    {
        currSum += num;
        if (currSum == count1 / 2)
        {
            result++;
        }
    }

    return result;
}

int main()
{

    return 0;
}