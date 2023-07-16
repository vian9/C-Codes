// Link : https://leetcode.com/problems/largest-divisible-subset/
// Time Complexity : O(n*n) SC:O(n)
// Approach-> Dp[i] of LIS ka method use kro to print the subsequence....yha hum select nhi krrhe h balki divisible h to move krrhe h
// So to print it hum dp[i] update kro and last mein backtrack krlo kaun sa index se kha move hua tha

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Tabulation Using a single DP Array to store the LIS waise hi yha pr store krenge
// dp[i] means the largest divisible subset Possible till index i in nums
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    // Sort krdo taaki phla sequence wla hume mile
    sort(nums.begin(), nums.end());
    // declare a single dp array with default value 1 as bs whi ind k element consider krenge to 1 hoga hi minimum
    vector<int> dp(n, 1);

    int maxi = -1;
    int lastIndex = -1;
    // Ab ye hash se hum jo subsequence mein curr ke alwa last index dalenge wo hash mein dal denge and hum subsequence track kr payenge
    vector<int> hash(n, -1);
    // Ab ind pr loop iterate krenge aur value nikalenge
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        // Ab last jo h 0 se start hokr ind-1 tk jayega
        for (int last = 0; last <= ind - 1; last++)
        {
            // Ab current value prev se bada h to 1+dp[last] le lenge and compare krke max le lenge and jo last h wo hum
            // subsequence ka last value dekhrhe max and usme apne ind wla add kr derhe
            // Jb current dp[ind] value se bada ho tbhi update krenge and then hash mein bhi last index update krenge
            if (nums[ind] % nums[last] == 0 && dp[ind] < 1 + dp[last])
            {
                dp[ind] = 1 + dp[last];
                hash[ind] = last;
            }
        }
        // Update krdia maxi LIS ko and whi hum LIS ka lastIndex bhi update krenge sbse bade value ka
        if (maxi < dp[ind])
        {
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    vector<int> lis;
    // Sbse last element push krdia
    lis.push_back(nums[lastIndex]);
    // 1st way
    //  maxi kaam krdia
    //  nmaxi--;
    //  Hum ye loop ka lastIndex jb -ve ya 0 ho jaye kuch aise krke nhi lga skte h....hume maxi pta h LIS k length h jbtk wo 0 se bada h utna len hume milgya
    //  while (maxi > 0)
    //  {
    //      lastIndex = hash[lastIndex];
    //      lis.push_back(nums[lastIndex]);
    //      maxi--;
    //  }

    // 2nd way....jaise hi hash ka lastIndex ka value same ko point na krde
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }

    // Reverse order mein LIS aaya h just reverse it
    reverse(lis.begin(), lis.end());

    return lis;
}

// Check for this approach
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
    {
        return 0;
    }

    // Index shift hua h last ka toh jo last ka index aarha usme +1 add krke check kro
    if (dp[ind][last + 1] != -1)
        return dp[ind][last + 1];

    // Pick krunga
    int pick = 0;
    // Agar first pick h ya greater h....last mein ab index shift h jha save krenge....0 will mean -1 but jb call krrhe and last derhe wha original last index dalrhe
    if (last == -1 || (nums[ind] % nums[last] == 0))
    {
        pick = 1 + stringHelper(nums, n, ind + 1, ind, dp);
    }
    // Subsequence mein nhi pick krunga
    int notPick = 0 + stringHelper(nums, n, ind + 1, last, dp);
    // return the max length possible
    // last +1 kuuki index shift kiye h ek se to store
    return dp[ind][last + 1] = max(pick, notPick);
}

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // Yha 2 parameters h ind and dusra last...ind can go from 0 to n-1 and last can also go from 0 to n-1 and ek -1...toh n+1 size ka hoga and index shift krenge to store from 0 to n...where 0 means -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // Hum len nikal lenge
    int len = stringHelper(nums, nums.size(), 0, -1, dp);
    // Ab dp se traverse krenge
    vector<int> ans;
    int row = n - 1;
    int col = n;
    while (row >= 0 && col > 0)
    {
        if ()
    }

    return ans;
}

// Recursive Approach - Top Down....hum ind 0 se denge wo mjhe last tk run krke dega max subsequence increasing ka length...TLE
int stringHelper(vector<int> &nums, int n, int ind, int last, vector<vector<int>> &ans, vector<int> &temp)
{
    if (ind == n)
    {
        // Ab jaise hi over ho save krdo wo vect ko and agar len 0 h ya prev se bada h tb krna
        if (ans.size() == 0)
            ans.push_back(temp);
        else
        {
            int len = ans.back().size();
            if (temp.size() > len)
            {
                ans.pop_back();
                ans.push_back(temp);
            }
        }
        return 0;
    }

    // Pick krunga
    int pick = 0;
    // Agar first pick h ya greater h
    if (last == -1 || (nums[ind] % nums[last] == 0))
    {
        // Push krdia and call and return pr pop
        temp.push_back(nums[ind]);
        pick = 1 + stringHelper(nums, n, ind + 1, ind, ans, temp);
        temp.pop_back();
    }
    // Subsequence mein nhi pick krunga
    int notPick = 0 + stringHelper(nums, n, ind + 1, last, ans, temp);
    // return the max length possible
    return max(pick, notPick);
}

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int len = stringHelper(nums, nums.size(), 0, -1, ans, temp);
    return ans.back();
}

int main()
{

    return 0;
}