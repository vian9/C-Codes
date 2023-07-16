// Link : https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// Time Complexity : O(n*m) SC:O(n)
// Approach-> It will work only when numbers are positive i.e. >= 0....equality doesn't matter as yha count nhi krna h bs kha sum pura horha bool mein dekhna h
// diff = (sum - (totalSum - sum))

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Solution - Top Down Approach .... in this we are saving at 0 and going till n-1 and finally returning n-1 and target
// dp[ind][sum] - it means that can we get sum from the ind
int minDifference(int arr[], int n)
{
    int sum = 0;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        nums.push_back(arr[i]);
    }
    // Kuuki tabulation mein curr and prev row use horha h to 2 vector le lenge 1D
    vector<bool> prev(sum + 1, false);
    // Base case of memoisation ko tabulation mein save krenge

    // For ind == 0 only the cell with sum == nums[0] will be true
    if (nums[0] <= sum)
        prev[nums[0]] = true;
    // If sum == 0 mtlb koi bhi ind pr agar sum 0 toh 0 save krlo toh ye hoga ki hnums row k phle element true krdo
    prev[0] = true;
    // Ind 0 hogya to start from 1 as ind == 0 ke liye agar sum == 0 ho tb true hoga ya sum == nums[0] tbhi true hoga
    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> curr(sum + 1, false);
        curr[0] = true;
        // Ab sum == 0 ke liye humne base mein save krlia upar toh 1 se start
        for (int target = 1; target < sum + 1; target++)
        {
            // Not Pick
            bool unPick = prev[target];
            // Pick
            bool pick = false;
            if (nums[ind] <= target)
                pick = prev[target - nums[ind]];
            curr[target] = (pick || unPick);
        }
        prev = curr;
    }
    // Jo memoisation mein call wo return krdo i.e n-1 ya last vector mein sum compare krlo ki min diff kb h
    int mini = 1e9;
    // Ab bs check krlia mini dif ko
    for (int i = 0; i <= sum; i++)
    {
        if (prev[i] == true)
        {
            // Mini diff nikal lenge i ek ka sum to dusra ka sum-i
            int diff = abs(i - (sum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

// Tabulation Solution - Top Down Approach .... in this we are saving at 0 and going till n-1 and finally returning n-1 and target
// dp[ind][sum] - it means that can we get sum from the ind
bool isSubsetPos(vector<int> &nums, int sum, vector<vector<bool>> &dp)
{
    int n = nums.size();
    // Base case of memoisation ko tabulation mein save krenge
    // If sum == 0 mtlb koi bhi ind pr agar sum 0 toh 0 save krlo
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    // For ind == 0 only the cell with sum == nums[0] will be true
    if (nums[0] <= sum)
        dp[0][nums[0]] = true;

    // Ind 0 hogya to start from 1 as ind == 0 ke liye agar sum == 0 ho tb true hoga ya sum == nums[0] tbhi true hoga
    for (int ind = 1; ind < n; ind++)
    {
        // Ab sum == 0 ke liye humne base mein save krlia upar toh 1 se start
        for (int target = 1; target < sum + 1; target++)
        {
            // Not Pick
            bool unPick = dp[ind - 1][target];
            // Pick
            bool pick = false;
            if (nums[ind] <= target)
                pick = dp[ind - 1][target - nums[ind]];
            dp[ind][target] = (pick || unPick);
        }
    }
    // Jo memoisation mein call wo return krdo
    return dp[n - 1][sum];
}

int minDifference(int arr[], int n)
{
    int sum = 0;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        nums.push_back(arr[i]);
    }
    // 2 parameters hai sum and ind
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    // Agar ye sum possible horha h tob
    // Isme ek baar hi bs call kiye as tabulation mein wo khud update krdega
    bool dummy = isSubsetPos(nums, sum, dp);
    int mini = 1e9;
    // Ab bs check krlia mini dif ko
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            // Mini diff nikal lenge i ek ka sum to dusra ka sum-i
            int diff = abs(i - (sum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

// Memoisation Solution - Top Down Approach .... in this we are calling n-1 and going till 0
// dp[ind][sum] - it means that can we get sum from the ind
bool isSubsetPos(vector<int> &nums, int sum, int ind, vector<vector<int>> &dp)
{
    // Kahi bhi sum 0 ho jaye to return krdo true
    if (sum == 0)
        // Isko save krna is imp for array size of 1
        return dp[ind][sum] = true;
    // Agar ind 0 tk pahuch jaye toh dekho nums[0] ke equal agar target hai to return true or else false
    if (ind == 0)
        return dp[ind][sum] = (nums[0] == sum);

    // -1 value not filled, 0 ia for false and 1 for true
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    // Not Pick
    bool unPick = isSubsetPos(nums, sum, ind - 1, dp);
    // Pick
    bool pick = false;
    if (nums[ind] <= sum)
        pick = isSubsetPos(nums, sum - nums[ind], ind - 1, dp);
    return dp[ind][sum] = (pick || unPick);
}

int minDifference(int arr[], int n)
{
    int sum = 0;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        nums.push_back(arr[i]);
    }
    // 2 parameters hai sum and ind
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    for (int i = 0; i <= sum; i++)
    {
        // Agar ye sum possible horha h tob
        bool dummy = isSubsetPos(nums, i, n - 1, dp);
    }
    int mini = 1e9;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n - 1][i] == 1)
        {
            // Mini diff nikal lenge i ek ka sum to dusra ka sum-i
            int diff = abs(i - (sum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

// Recursive Solution - Top Down Approach .... in this we are calling n-1 and going till 0
bool isSubsetPos(vector<int> &nums, int sum, int ind)
{
    // Kahi bhi sum 0 ho jaye to return krdo true
    if (sum == 0)
        return true;
    // Agar ind 0 tk pahuch jaye toh dekho nums[0] ke equal agar target hai to return true or else false
    if (ind == 0)
        return (nums[0] == sum);

    // Not Pick
    bool unPick = isSubsetPos(nums, sum, ind - 1);
    // Pick
    bool pick = false;
    if (nums[ind] <= sum)
        pick = isSubsetPos(nums, sum - nums[ind], ind - 1);
    return pick or unPick;
}

int minDifference(int arr[], int n)
{
    int sum = 0;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        nums.push_back(arr[i]);
    }

    int mini = INT_MAX;
    for (int i = 0; i <= sum; i++)
    {
        // Agar ye sum possible horha h tob
        bool dummy = isSubsetPos(nums, i, n - 1);
        if (dummy == true)
        {
            // Mini diff nikal lenge i ek ka sum to dusra ka sum-i
            mini = min(mini, abs(i - (sum - i)));
        }
    }
    return mini;
}

int main()
{

    return 0;
}