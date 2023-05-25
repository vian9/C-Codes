// Link :https://leetcode.com/problems/4sum/
// Time Complexity : O(n^3) and Space : O(n)
// Approach-> First sort krdo and k sum ko dedo
// Ab k sum m avg val dekhlo and k == 2 pr 2 sum ko dedo
// wrna recursive call kro num[i] ko ek element lekr and then k dec krke copy krdo vector in ans

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// We will write code for ksum....sbko 2sum m torenge
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    return kSum(nums, 0, target, 4);
}

vector<vector<int>> kSum(vector<int> &nums, int start, long long target, int k)
{
    vector<vector<int>> ans;
    // Agar start hi end ho
    if (start == nums.size())
    {
        return ans;
    }
    // Agar target bda ho ya chota ho to bhi
    long long avg_val = target / k;
    if (avg_val < nums[start] || nums.back() < avg_val)
    {
        return ans;
    }

    // 2sum horha h
    if (k == 2)
    {
        return twoSum(nums, start, target);
    }

    for (int i = start; i < nums.size(); ++i)
    {
        // if same element to continue
        if (i > start && nums[i] == nums[i - 1])
        {
            continue;
        }
        // num[i] ko ek element lelia and call for k-1 and i++ se and agar exist krta h to daldo
        for (vector<int> &res : kSum(nums, i + 1, static_cast<long long>(target - nums[i]), k - 1))
        {
            ans.push_back({nums[i]});
            // pos and val
            ans.back().insert((ans.back().end()), res.begin(), res.end());
        }
    }
    return ans;
}

vector<vector<int>> twoSum(vector<int> &nums, int start, long long target)
{
    vector<vector<int>> ans;
    int low = start, high = nums.size() - 1;
    // 2Sum using 2 pointers....low and high
    while (low < high)
    {
        int sum = nums[low] + nums[high];
        // agar sum chota h to low bdao ya same h to continue
        if (sum < target || (low > start && nums[low] == nums[low - 1]))
        {
            low++;
        }
        // sum bada h to high ghatao
        else if (sum > target || (high < nums.size() - 1 && nums[high] == nums[high + 1]))
        {
            high--;
        }
        else
        {
            ans.push_back({nums[low], nums[high]});
            low++;
            high--;
        }
    }
    return ans;
}

int main()
{

    return 0;
}