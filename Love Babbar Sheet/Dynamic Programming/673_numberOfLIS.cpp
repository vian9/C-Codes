// Link : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// Time Complexity : O(n*n) SC:O(n)
// Approach-> LIS jaise dp[i] array se nikalte h nikal lenge and then hume saare dp[i] mein ek count ka table maintain krna hoga ki kaun sa se wo max aarha tha itne baar
// Agar dp jada aarha ya same aarha to purane wale ka count value hum daal denge....as purane ka total possibility isme bhi ab add on ho jayega

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // declare a single dp array with default value 1 as bs whi ind k element consider krenge to 1 hoga hi minimum
    vector<int> dp(n, 1);
    // Initialise 1 se krenge as min sb apna subsequence rkhega hi....update hoga to replace kr denge
    vector<int> cnt(n, 1);
    int maxi = 0;
    // Ab ind pr loop iterate krenge aur value nikalenge
    for (int ind = 0; ind < n; ind++)
    {
        // Ab last jo h 0 se start hokr ind-1 tk jayega
        for (int last = 0; last <= ind - 1; last++)
        {
            // Ab current value prev se bada h to 1+dp[last] le lenge and compare krke max le lenge and jo last h wo hum subsequence ka last value dekhrhe max and usme apne ind wla add kr derhe
            if (nums[ind] > nums[last] && dp[ind] < 1 + dp[last])
            {
                dp[ind] = 1 + dp[last];
                // Purane wale ka count ka value isme daal denge
                cnt[ind] = cnt[last];
            }
            else if (nums[ind] > nums[last] && dp[ind] == 1 + dp[last])
            {
                // Agar same values dp se aarha to purane wale ka count add krdo
                cnt[ind] += cnt[last];
            }
        }
        // Update krdia maxi LIS ko
        maxi = max(maxi, dp[ind]);
    }

    int vals = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            vals += cnt[i];
    }
    return vals;
}

int main()
{

    return 0;
}