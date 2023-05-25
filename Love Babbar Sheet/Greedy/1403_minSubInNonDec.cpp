// Link : https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
// Time Complexity : O(nlogn)
// Approach-> Sort krdo and sum nikallo and then ab peeche se sum lena start kro and jbtk uska sum curr se chota na ho jaye

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> minSubsequence(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    // sorting issliye ki min lena h aur non increasing m mangrha h
    sort(nums.begin(), nums.end());
    int curr = 0;
    vector<int> ans;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        curr += nums[i];
        sum -= nums[i];
        ans.push_back(nums[i]);
        if (curr > sum)
        {
            break;
        }
    }
    return ans;
}

int main()
{

    return 0;
}