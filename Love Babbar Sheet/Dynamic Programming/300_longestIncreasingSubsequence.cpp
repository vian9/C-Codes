// Link : https://leetcode.com/problems/longest-increasing-subsequence/
// Time Complexity : O(n*n) SC:O(n)
// Approach-> Strictly increasing subsequence chahiye...toh hume last janna hoga and usse greater h tbhi pick kro wrna skip kro....ab last janne k liye value
// ka range mt lo balki index ka range lo aasan pdega
// Ab jb last ko store krrhe and -1 for not start...to dp mein save krte time tmhe index shift 1 ka krna hoga
// dp mein last ka loop ind-1 se lekr -1 chlega toh jha bhi last ko access krrhe tabulation mein wha +1 krna hoga and nums mein waise hi directly as -1 ka case handled h
// So bs index ka dhyan rkho baaki same recursive code memoisation ka use krenge

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Tabulation Using a single DP Array to store the LIS
// dp[i] means the largest LIS Possible till index i in nums
// Hume jo phle tabulation mein mila value usse hum derive kiye ki kaise ye table bna hoga and phir usse table bnaye and update kiye
// This method will help us print the LIS
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // declare a single dp array with default value 1 as bs whi ind k element consider krenge to 1 hoga hi minimum
    vector<int> dp(n, 1);

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

    return maxi;
}

// Space Optimisation Approach - Bottom up....hum n-1 se jayenge 0 tk and check krenge and loop mein store krt jayenge
// dp[ind][last] tells us ki max length of subsequence increasing till ind and with last value chosen as last
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // Yha 2 parameters h ind and dusra last...ind can go from 0 to n as base case bhi ab here as base case store krenge and last can also go from 0 to n-1 and ek -1...toh n+1 size ka hoga and index shift krenge to store from 0 to n...where 0 means -1
    // Instead hume bs prev and curr use horha h
    vector<int> prev(n + 1, 0);

    // Memoisation ka base case store kr lenge waise already default value 0 h

    // 2 Paramters h toh 2 nested loop chlega as opposite of memoisation....ind from n-1 to 0 and last from ind-1 to -1...ie n to 0
    for (int ind = n - 1; ind >= 0; ind--)
    {
        vector<int> curr(n + 1, 0);
        // Jo original last se jaarhe ho waise hi jao bs save krte time +1 krna
        for (int last = ind - 1; last >= -1; last--)
        {
            // Pick krunga
            int pick = 0;
            // Agar first pick h ya greater h....last mein ab index shift h jha save krenge....0 will mean -1 but jb call krrhe and last derhe wha original last index dalrhe
            if (last == -1 || nums[ind] > nums[last])
            {
                // Yha bhi jo last mein ind h original ind se +1 shift mein h
                pick = 1 + prev[ind + 1];
            }
            // Subsequence mein nhi pick krunga....ab dp access krrhe ho last mein + 1 krke kroge
            int notPick = 0 + prev[last + 1];
            // return the max length possible
            // last +1 kuuki index shift kiye h ek se to store
            curr[last + 1] = max(pick, notPick);
        }
        prev = curr;
    }
    // Jo memoisation mein call usse return krdo...ind 0 and last = 0 as index shift
    return prev[0];
}

// Tabulation Approach - Bottom up....hum n-1 se jayenge 0 tk and check krenge and loop mein store krt jayenge
// dp[ind][last] tells us ki max length of subsequence increasing till ind and with last value chosen as last
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // Yha 2 parameters h ind and dusra last...ind can go from 0 to n as base case bhi ab here as base case store krenge and last can also go from 0 to n-1 and ek -1...toh n+1 size ka hoga and index shift krenge to store from 0 to n...where 0 means -1
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Memoisation ka base case store kr lenge waise already default value 0 h

    // 2 Paramters h toh 2 nested loop chlega as opposite of memoisation....ind from n-1 to 0 and last from ind-1 to -1...ie n to 0
    for (int ind = n - 1; ind >= 0; ind--)
    {
        // Jo original last se jaarhe ho waise hi jao bs save krte time +1 krna
        for (int last = ind - 1; last >= -1; last--)
        {
            // Pick krunga
            int pick = 0;
            // Agar first pick h ya greater h....last mein ab index shift h jha save krenge....0 will mean -1 but jb call krrhe and last derhe wha original last index dalrhe
            if (last == -1 || nums[ind] > nums[last])
            {
                // Yha bhi jo last mein ind h original ind se +1 shift mein h
                pick = 1 + dp[ind + 1][ind + 1];
            }
            // Subsequence mein nhi pick krunga....ab dp access krrhe ho last mein + 1 krke kroge
            int notPick = 0 + dp[ind + 1][last + 1];
            // return the max length possible
            // last +1 kuuki index shift kiye h ek se to store
            dp[ind][last + 1] = max(pick, notPick);
        }
    }
    // Jo memoisation mein call usse return krdo...ind 0 and last = 0 as index shift
    return dp[0][0];
}

// Memoisation Approach - Top Down....hum ind 0 se denge wo mjhe last tk run krke dega max subsequence increasing ka length
// dp[ind][last] tells us ki max length of subsequence increasing till ind and with last value chosen as last
int stringHelper(vector<int> &nums, int n, int ind, int last, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    // Index shift hua h last ka toh jo last ka index aarha usme +1 add krke check kro
    if (dp[ind][last + 1] != -1)
        return dp[ind][last + 1];

    // Pick krunga
    int pick = 0;
    // Agar first pick h ya greater h....last mein ab index shift h jha save krenge....0 will mean -1 but jb call krrhe and last derhe wha original last index dalrhe
    if (last == -1 || nums[ind] > nums[last])
    {
        pick = 1 + stringHelper(nums, n, ind + 1, ind, dp);
    }
    // Subsequence mein nhi pick krunga
    int notPick = 0 + stringHelper(nums, n, ind + 1, last, dp);
    // return the max length possible
    // last +1 kuuki index shift kiye h ek se to store
    return dp[ind][last + 1] = max(pick, notPick);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // Yha 2 parameters h ind and dusra last...ind can go from 0 to n-1 and last can also go from 0 to n-1 and ek -1...toh n+1 size ka hoga and index shift krenge to store from 0 to n...where 0 means -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return stringHelper(nums, n, 0, -1, dp);
}

// Recursive Approach - Top Down....hum ind 0 se denge wo mjhe last tk run krke dega max subsequence increasing ka length
int stringHelper(vector<int> &nums, int n, int ind, int last)
{
    if (ind == n)
        return 0;

    // Pick krunga
    int pick = 0;
    // Agar first pick h ya greater h
    if (last == -1 || nums[ind] > nums[last])
    {
        pick = 1 + stringHelper(nums, n, ind + 1, ind);
    }
    // Subsequence mein nhi pick krunga
    int notPick = 0 + stringHelper(nums, n, ind + 1, last);
    // return the max length possible
    return max(pick, notPick);
}

int lengthOfLIS(vector<int> &nums)
{
    return stringHelper(nums, nums.size(), 0, -1);
}

int main()
{

    return 0;
}