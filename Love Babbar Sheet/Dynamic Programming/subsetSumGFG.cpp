// Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Time Complexity : O(n*sum) SC:O(n*sum)
// Approach-> Dekho isme bs ye ki pick and unpick se jada kb ye target 0 hoga and kaise hoga ye imp h
// If sum == 0 mtlb koi bhi ind pr agar sum 0 toh 0 save krlo toh ye hoga ki harr row k phle element true krdo in space optimisation

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation Solution - Top Down Approach .... in this we are saving at 0 and going till n-1 and finally returning n-1 and target
// dp[ind][sum] - it means that can we get sum from the ind
bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    // Kuuki tabulation mein curr and prev row use horha h to 2 vector le lenge 1D
    vector<bool> prev(sum + 1, false);
    // Base case of memoisation ko tabulation mein save krenge

    // For ind == 0 only the cell with sum == arr[0] will be true
    if (arr[0] <= sum)
        prev[arr[0]] = true;

    // If sum == 0 mtlb koi bhi ind pr agar sum 0 toh 0 save krlo toh ye hoga ki harr row k phle element true krdo
    prev[0] = true;

    // Ind 0 hogya to start from 1 as ind == 0 ke liye agar sum == 0 ho tb true hoga ya sum == arr[0] tbhi true hoga
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
            if (arr[ind] <= target)
                pick = prev[target - arr[ind]];
            curr[target] = (pick || unPick);
        }
        prev = curr;
    }
    // Jo memoisation mein call wo return krdo
    return prev[sum];
}

// Tabulation Solution - Top Down Approach .... in this we are saving at 0 and going till n-1 and finally returning n-1 and target
// dp[ind][sum] - it means that can we get sum from the ind
bool isSubsetPos(vector<int> &arr, int sum, vector<vector<bool>> &dp)
{
    int n = arr.size();
    // Base case of memoisation ko tabulation mein save krenge
    // If sum == 0 mtlb koi bhi ind pr agar sum 0 toh 0 save krlo
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    // For ind == 0 only the cell with sum == arr[0] will be true
    if (arr[0] <= sum)
        dp[0][arr[0]] = true;

    // Ind 0 hogya to start from 1 as ind == 0 ke liye agar sum == 0 ho tb true hoga ya sum == arr[0] tbhi true hoga
    for (int ind = 1; ind < n; ind++)
    {
        // Ab sum == 0 ke liye humne base mein save krlia upar toh 1 se start
        for (int target = 1; target < sum + 1; target++)
        {
            // Not Pick
            bool unPick = dp[ind - 1][target];
            // Pick
            bool pick = false;
            if (arr[ind] <= target)
                pick = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = (pick || unPick);
        }
    }
    // Jo memoisation mein call wo return krdo
    return dp[n - 1][sum];
}

bool isSubsetSum(vector<int> arr, int sum)
{
    // 2 parameters hai sum and ind
    // sum+1 tk issliye kuuki sum hume 0 se sum tk lena h toh size sum+1 hoga
    vector<vector<bool>> dp(arr.size(), vector<bool>(sum + 1, false));
    return isSubsetPos(arr, sum, dp);
}

// Memoisation Solution - Top Down Approach .... in this we are calling n-1 and going till 0
// dp[ind][sum] - it means that can we get sum from the ind
bool isSubsetPos(vector<int> &arr, int sum, int ind, vector<vector<int>> &dp)
{
    // Kahi bhi sum 0 ho jaye to return krdo true
    if (sum == 0)
        return true;
    // Agar ind 0 tk pahuch jaye toh dekho arr[0] ke equal agar sum hai to return true or else false
    if (ind == 0)
        return (arr[0] == sum);

    // -1 value not filled, 0 ia for false and 1 for true
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    // Not Pick
    bool unPick = isSubsetPos(arr, sum, ind - 1, dp);
    // Pick
    bool pick = false;
    if (arr[ind] <= sum)
        pick = isSubsetPos(arr, sum - arr[ind], ind - 1, dp);
    return dp[ind][sum] = pick or unPick;
}

bool isSubsetSum(vector<int> arr, int sum)
{
    // 2 parameters hai sum and ind
    vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
    return isSubsetPos(arr, sum, arr.size() - 1, dp);
}

// Recursive Solution - Top Down Approach .... in this we are calling n-1 and going till 0
bool isSubsetPos(vector<int> &arr, int sum, int ind)
{
    // Kahi bhi sum 0 ho jaye to return krdo true
    if (sum == 0)
        return true;
    // Agar ind 0 tk pahuch jaye toh dekho arr[0] ke equal agar target hai to return true or else false
    if (ind == 0)
        return (arr[0] == sum);

    // Not Pick
    bool unPick = isSubsetPos(arr, sum, ind - 1);
    // Pick
    bool pick = false;
    if (arr[ind] <= sum)
        pick = isSubsetPos(arr, sum - arr[ind], ind - 1);
    return pick or unPick;
}

bool isSubsetSum(vector<int> arr, int sum)
{
    return isSubsetPos(arr, sum, arr.size() - 1);
}

int main()
{

    return 0;
}