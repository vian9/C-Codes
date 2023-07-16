// Link : https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// Time Complexity : O(n*n) SC:O(n)
// Approach-> LIS ka approach follow kro to print the LIS and usme ab kya kro ki ek baar increasing order mein lo...ekbaar decreasing order and
// ek baar dono table ka sum krdo and usme -1 ab isme se jo max hoga whi return krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Tabulation Using a single DP Array to store the LIS
// dp[i] means the largest LIS Possible till index i in nums
// Hume jo phle tabulation mein mila value usse hum derive kiye ki kaise ye table bna hoga and phir usse table bnaye and update kiye
int LongestBitonicSequence(vector<int> nums)
{
    int n = nums.size();
    // declare a single dp array with default value 1 as bs whi ind k element consider krenge to 1 hoga hi minimum
    vector<int> dp(n, 1);

    // Phla side se max and dp table leli
    int maxi = 0;
    // Ab ind pr loop iterate krenge aur value nikalenge
    for (int ind = 0; ind < n; ind++)
    {
        // Ab last jo h 0 se start hokr ind-1 tk jayega
        for (int last = 0; last <= ind - 1; last++)
        {
            // Ab current value prev se bada h to 1+dp[last] le lenge and compare krke max le lenge and jo last h wo hum subsequence ka last value dekhrhe max and usme apne ind wla add kr derhe
            if (nums[ind] > nums[last])
            {
                dp[ind] = max(dp[ind], 1 + dp[last]);
            }
        }
        // Update krdia maxi LIS ko
        maxi = max(maxi, dp[ind]);
    }
    // Ab reverse order mein max and dp table lelo
    vector<int> rev = nums;
    reverse(rev.begin(), rev.end());
    vector<int> dp2(n, 1);
    int maxi2 = 0;
    // Ab ind pr loop iterate krenge aur value nikalenge
    for (int ind = 0; ind < n; ind++)
    {
        // Ab last jo h 0 se start hokr ind-1 tk jayega
        for (int last = 0; last <= ind - 1; last++)
        {
            // Ab current value prev se bada h to 1+dp[last] le lenge and compare krke max le lenge and jo last h wo hum subsequence ka last value dekhrhe max and usme apne ind wla add kr derhe
            if (rev[ind] > rev[last])
            {
                dp2[ind] = max(dp2[ind], 1 + dp2[last]);
            }
        }
        // Update krdia maxi LIS ko
        maxi2 = max(maxi2, dp2[ind]);
    }
    // dp2 table agar nums ka ind dekhe to opposite h to usse reverse krdo
    reverse(dp2.begin(), dp2.end());
    int maxii = 0;
    // agar completely increasing or decreasing se sbse bada length banrha h to lelo
    maxii = max(maxi, maxi2);
    // otherwise check kro increase se decrease ka and isme dono dp table add krke -1 as ind i wla number usme 2 baar h
    for (int i = 0; i < n; i++)
    {
        maxii = max(maxii, dp[i] + dp2[i] - 1);
    }

    return maxii;
}

int main()
{

    return 0;
}