// Link : https://leetcode.com/problems/permutation-sequence/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void recurse(int ind, vector<vector<int>> &ans, vector<int> &nums, vector<int> &ds)
{
    // Jb size equal ho jaye to push
    if (ind == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    // Thora complex than pick unpick....isme hum loop se start item lerhe nd usse swap krrhe
    // aur ab woh ind k next wale pr call krrhe
    for (int i = ind; i < nums.size(); i++)
    {
        ds.push_back(nums[ind]);
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
                continue;
            ds.push_back(nums[j]);
        }
        recurse(i + 1, ans, nums, ds);
        for (int j = nums.size(); j >= 0; j--)
        {
            ds.pop_back();
        }
    }
}

string getPermutation(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        nums.push_back(i);
    }
    vector<int> ds;
    recurse(0, ans, nums, ds);
    ds = ans[k - 1];
    string st = "";
    for (int i = 0; i < ds.size(); i++)
    {
        st.push_back(ds[i] + '0');
    }
    return st;
}

int main()
{

    return 0;
}